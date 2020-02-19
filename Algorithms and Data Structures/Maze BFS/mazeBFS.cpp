#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>

class Graph {

public:
    Graph(int V);

    void addEdge(int vertex, int w);

    // Returns number of vertices in the graph
    int V();

    // Returns number of edges in the graph
    std::set<int> adj(int vertex);

    void vanishStructs();

    void toPrintGraph(std::vector<std::vector<char>> matr_char, std::vector<std::vector<int>> mart_int, int row_size,
                      int column_size);

    void findFinish(const std::vector<std::vector<char>> &matr_char, const std::vector<std::vector<int>> &mart_int,
                    int row_size, int column_size);


private:
    std::map<int, std::set<int>> adj_lists;   // vec

    std::queue<int> v_queue;
    std::set<int> v_set;
    std::vector<int> arrVer;
    int prev = 0;
    std::vector<int> cycle;
    std::vector<int> new_cycle;
    std::vector<int> path;

    void bfsQueue(int v, int f, int s_r, int s_c, int f_r, int f_);
};


Graph::Graph(int V) {
    arrVer.assign(V, 0);
    std::set<int> cell = {};
    for (int i = 0; i < V; ++i) {
        adj_lists[i] = cell;
    }
}

void Graph::addEdge(int vertex, int nbVertex) {
    adj_lists[vertex].insert(nbVertex);
}

std::set<int> Graph::adj(int vertex) {
    if (vertex <= V() && vertex >= 0) {
        std::set<int> value;
        value = adj_lists[vertex];
        return value;
    } else {
        throw std::invalid_argument("There is no such vertex!");
    }
}

void Graph::bfsQueue(int v, int f, int s_r, int s_c, int f_r, int f_c) {
    v_queue.push(v);
    v_set.insert(v);
    while (!v_queue.empty()) {   ////////////////////
        int num = v_queue.front();
        v_queue.pop();
        if (num == f){
            return;
        } else{
            for (int adj_to_num : adj_lists[num]) {
                if (path[adj_to_num] == -1) {
                    path[adj_to_num] = path[num] + 1;
                }
                if (v_set.find(adj_to_num) == v_set.end()) {
                    arrVer[adj_to_num] = num;
                    v_queue.push(adj_to_num);
                    v_set.insert(adj_to_num);
                }
            } 
        }
    }
}


int Graph::V() {
    return adj_lists.size();
}


void Graph::vanishStructs() {
    arrVer.assign(V(), 0);
    v_set.clear();
}


void Graph::toPrintGraph(std::vector<std::vector<char>> matr_char, std::vector<std::vector<int>> mart_int, int row_size,
                         int column_size) {
    std::vector<char> ch = {'.', 'S', 'F'};
    for (int i = 0; i < row_size; ++i) {
        for (int j = 0; j < column_size; ++j) {
            bool check = std::find(ch.begin(), ch.end(), matr_char[i][j]) != ch.end();
            if (check) {  // если тут  <. S F>
                if (((i - 1) >= 0) && (matr_char[i - 1][j] != '#')) { // проверяем путь наверх, подним на строку (1)
                    addEdge(mart_int[i][j], mart_int[i - 1][j]);
                }
                if (((j - 1) >= 0) && (matr_char[i][j - 1] != '#')) {          // (2)
                    addEdge(mart_int[i][j], mart_int[i][j - 1]);
                }
                if (((j + 1) < column_size) && (matr_char[i][j + 1] != '#')) {      // (3)
                    addEdge(mart_int[i][j], mart_int[i][j + 1]);
                }
                if (((i + 1) < row_size) && (matr_char[i + 1][j] != '#')) {       // (4)
                    addEdge(mart_int[i][j], mart_int[i + 1][j]);
                }
            } else if (matr_char[i][j] == '#') {
                continue;
            }
        }
    }

    std::cout << "Graph:" << std::endl;
    for (int k = 0; k < adj_lists.size(); ++k) {
        std::cout << k << " - ";
        if (adj_lists[k].empty()) {
            std::cout << "None";
        } else {
            for (auto el:adj_lists[k]) {
                std::cout << el << " ";
            }
        }
        std::cout << std::endl;
    }
}

void Graph::findFinish(const std::vector<std::vector<char>> &matr_char, const std::vector<std::vector<int>> &mart_int,
                       int row_size, int column_size) {

    for (int k = 0; k < row_size * column_size; ++k) { // заполнен -1
        path.push_back(-1);
    }
    int finish = 0;
    int f_r = 0;
    int f_c = 0;
    for (int l = 0; l < row_size; ++l) {   //  ищу координаты финиша
        for (int i = 0; i < column_size; ++i) {
            if (matr_char[l][i] == 'F') {
//                finish = path[l][i];
                finish = mart_int[l][i];
                f_r = l;
                f_c = i;
            }
        }
    }
    int co = -1;
    for (int j = 0; j < row_size; ++j) {
        for (int i = 0; i < column_size; ++i) {
            co++;
            if (matr_char[j][i] == 'S') {  // делаю нулевой точку старта
                path[co] = 0; /////////////
                bfsQueue(mart_int[j][i], finish, i, j, f_r, f_c); // от S запускаю bfs , нужно до финиша и обходя #
            }
        }
    }
    std::cout << "BFS result is :" << std::endl;
    int size = row_size * column_size - 1;
    int count = 0;
    for (int m = 0; m < row_size; ++m) {
        for (int i = 0; i < column_size; ++i) {
            if (count <= size) {
                std::cout << path[count] << " ";
                count++;
            }
        }
        std::cout << std::endl;
    }
}


int main() {

    int row_size = 0;
    int column_size = 0;
    std::cin >> row_size;
//
    std::cin >> column_size;
    Graph g(row_size * column_size); /// создаю граф
    std::vector<std::vector<char>> mart_char;
    std::vector<std::vector<int>> mart_int;
    std::string s;
    for (int i = 0; i < row_size; ++i) {  // считываю строку
        std::cin >> s;
        std::vector<char> add;
        for (int k = 0; k < s.size(); ++k) { // заполняю матрицу чарами
            add.push_back(s[k]);
        }
        mart_char.push_back(add);
        add.clear();
    }

    std::cout << "Initial labyrinth:" << std::endl;
    for (int j = 0; j < row_size; ++j) {
        for (int i = 0; i < column_size; ++i) {
            std::cout << mart_char[j][i];
        }
        std::cout << std::endl;
    }

    int size = column_size * row_size - 1;
    int count = 0;
    for (int k = 0; k < row_size; ++k) { // заполняю 2 матр цифрами
        std::vector<int> add;
        for (int i = 0; i < column_size; ++i) {
            if (count <= size) {
                add.push_back(count);
                count++;
            }
        }
        mart_int.push_back(add);
        add.clear();
    }
    g.toPrintGraph(mart_char, mart_int, row_size, column_size);
    g.findFinish(mart_char, mart_int, row_size, column_size);
    return 0;
}


