import math
import operator
import random
import time
from itertools import repeat

import numpy as np
import pandas as pd
from tsp_solver.greedy import solve_tsp


class Point:
    def __init__(self, ind, x, y):
        self.index = ind
        self.x = x
        self.y = y

    def __repr__(self):
        return str(self.index)


class GA:
    def __init__(self, matr):
        self.matrix = matr  # use just for greedy once
        self.route = list()
        self.distance = 0
        self.improve = 0.0
        # BEST
        self.best_dist = 0
        self.best_path = list()

    def dist(self, c1, c2) -> float:
        '''
        count Euclidean distance between 2 cities
        :param c1: 1st city coords (x,y)
        :param c2: 2nd city coords (x,y)
        '''
        return math.dist([c1.x, c1.y], [c2.x, c2.y])

    def count_dist(self):
        '''
        Count the whole dist of path
        '''
        if self.distance == 0:
            dist_path = 0

            for i in range(0, len(self.route)):
                start_city = self.route[i]
                end_city = None

                if i + 1 < len(self.route):
                    end_city = self.route[i + 1]
                else:
                    # start and end in the same city
                    end_city = self.route[0]

                dist_path += self.dist(start_city, end_city)

            self.distance = dist_path
            return self.distance

    def route_improvement(self):
        if self.improve == 0.0:
            self.improve = 1 / float(self.count_dist())
        return self.improve

    def make_route(self, points):
        '''
        randomly create route for initial  population  +  GREED (1)
        '''
        route = random.sample(points, len(points))
        return route

    def greedy_path(self, points):
        gr = solve_tsp(self.matrix)
        init_path = gr.copy()
        for el in points:
            num = el.index
            init_path[gr.index(num)] = el
        return init_path

    def init_population(self, population_size, points):
        '''
        generate initial population (routes)
        '''
        population = list()
        # ADD GREEDY ONE
        greedy = self.greedy_path(points)
        population.append(greedy)
        for i in range(1, population_size):
            population.append(self.make_route(points))
        return population

    def rank_routes(self, population):
        '''
        Make a dict that will collect route and its fitness
        '''
        improvements = dict()
        for i in range(0, len(population)):
            self.route = population[i]
            self.distance = 0
            self.improve = 0.0
            improvements[i] = self.route_improvement()
        return sorted(improvements.items(), key=operator.itemgetter(1), reverse=True)

    def roulette_wheel_selection(self, pop_dist, bestGenes):
        '''
        In the roulette wheel selection, each path has a chance to be selected.
         The probability of choosing an individual depends on their fitness.
         More suitable paths have a higher chance of being chosen.
        The roulette wheel selection function takes cumulative sums and a randomly generated
        value for the selection process and returns the number of the selected path.
        :param bestGenes: great routs from last generation will be in this also
        '''
        select_res = list()
        df = pd.DataFrame(np.array(pop_dist), columns=["Index", "Improvement"])
        df['partial_amount'] = df.Improvement.cumsum()
        df['partial_percent'] = 1000 * df['partial_amount'] / df['Improvement'].sum()

        # routs with better dist are going to the next generation
        for i in range(0, bestGenes):
            select_res.append(pop_dist[i][0])
        # choose other routs for "mating"
        for i in range(0, len(pop_dist) - bestGenes):
            rand = 1000 * random.random()
            for i in range(0, len(pop_dist)):
                if rand <= df['partial_percent'][i]:
                    select_res.append(pop_dist[i][0])
                    break
        return select_res

    def selected_species(self, population, selection_res):
        '''
        extract selected individuals from the population
        :param population:
        :param selection_res:
        :return:
        '''
        matingpool = list()
        for i in range(0, len(selection_res)):
            index = selection_res[i]
            matingpool.append(population[index])
        return matingpool

    def crossover_one_route(self, route1, route2):
        '''
        randomly swapping two cities in a route
        '''
        new_route1 = list()

        gene1 = int(random.random() * len(route1))
        gene2 = int(random.random() * len(route1))
        start_gene = min(gene1, gene2)
        end_gene = max(gene1, gene2)

        for i in range(start_gene, end_gene):
            new_route1.append(route1[i])

        new_route2 = [item for item in route2 if item not in new_route1]
        return new_route1 + new_route2

    def crossover_routes(self, diff_species, bestGenes):
        routes = list()
        length = len(diff_species) - bestGenes
        mix_of_species = random.sample(diff_species, len(diff_species))

        for i in range(0, bestGenes):
            routes.append(diff_species[i])

        for i in range(0, length):
            route = self.crossover_one_route(mix_of_species[i], mix_of_species[len(diff_species) - i - 1])
            routes.append(route)
        return routes

    def mutate_one_route(self, route, mutationRate):
        '''
        with a given low probability, the two cities will switch places on the route
        '''
        for gene in range(len(route)):
            if random.random() < mutationRate:
                rand_gene_ind = int(random.random() * len(route))

                city1 = route[gene]
                city2 = route[rand_gene_ind]

                route[gene] = city2
                route[rand_gene_ind] = city1
        return route

    def mutate_routs(self, population, mutationRate):
        mutated_routs = list()

        for ind in range(0, len(population)):
            mutatedInd = self.mutate_one_route(population[ind], mutationRate)
            mutated_routs.append(mutatedInd)
        return mutated_routs

    def next_generation(self, currentGen, bestGenes, mutationRate):
        population_ranked = self.rank_routes(currentGen)
        # identifying potential "parents"
        selection_res = self.roulette_wheel_selection(population_ranked, bestGenes)
        # pool for producing next generation
        pool_species = self.selected_species(currentGen, selection_res)
        # create new population
        children = self.crossover_routes(pool_species, bestGenes)
        # mutate this new population
        next_gener = self.mutate_routs(children, mutationRate)
        return next_gener

    def genetic_algorithm(self, population, population_size: int, bestGenes: int, mutationRate, generations):
        """
        :param population: cities + coords
        :param population_size: amount of generated routs
        :param bestGenes:  number of the best individuals into the next generation
        :param mutationRate: probability
        :param generations: iterations size
        :return:
        """
        # write to file
        f = open('init.txt', 'w')
        # create the initial population
        new_population = self.init_population(population_size, population)
        print(f'Initial distance: {str(1 / self.rank_routes(new_population)[0][1])}')
        f.write(f'Initial distance: {str(1 / self.rank_routes(new_population)[0][1])}\n')  ##
        # repeatedly create next generations
        for i in range(0, generations):
            print(f'Generation {i}')
            new_population = self.next_generation(new_population, bestGenes, mutationRate)
            ################
            print(f'Final distance {i}: {str(1 / self.rank_routes(new_population)[0][1])}')
            f.write(f'Final distance {i}: {str(1 / self.rank_routes(new_population)[0][1])}\n')  ##
            best_route_ind = self.rank_routes(new_population)[0][0]
            best_route = new_population[best_route_ind]
            print(f'BEST ROUTE: {best_route}')
            f.write(f'PATH\n{best_route}\n')  ##


##########################################
# additional preparations for greedy

def dista(c1, c2) -> float:
    return math.dist([c1[0], c1[1]], [c2[0], c2[1]])


# Fill in distance matrix
def bfs(size, all_coord):
    all_distances = [[0.0] * size for i in repeat(None, size)]
    for i in range(0, size):
        point1 = all_coord[i]
        for j in range(0, i + 1):
            point2 = all_coord[j]
            dist = dista(point1, point2)  # евклид
            all_distances[i][j] = dist
    np_arr = np.array(all_distances)
    mirr_matr = np.tril(np_arr) + np.triu(np_arr.T, 1)
    matr = mirr_matr.tolist()
    return matr


def main():
    start_time = time.time()
    ########################
    df_cities = pd.read_csv('data/DATA.csv')

    points = list()
    tour_points = list()
    for i in range(0, df_cities.shape[0]):
        tour_points.append(Point(i, x=df_cities.iloc[i]['X'], y=df_cities.iloc[i]['Y']))
        points.append([df_cities.iloc[i]['X'], df_cities.iloc[i]['Y']])

    size = 1000
    matr = bfs(size, points)  # matrix of dist-s
    ga = GA(matr)
    ga.genetic_algorithm(population=tour_points, population_size=600, bestGenes=5, mutationRate=0.01, generations=1000)

    print("\n\nTIME: ", time.time() - start_time)


if __name__ == '__main__':
    main()
