#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

void coolestPath(int vert, std::vector<std::vector<int>> &matrix, int n, std::vector<int>& visited, int& sum) {

    int town = 0;
    int min = INT_MAX;
    while (visited.size()!= n) {  // пока не прошли все города
        for (int j = 0; j < n; ++j) {  // хожу по столбцам строки vert
            bool needed = std::find(visited.begin(), visited.end(), j) != visited.end();
            if (!needed) {  // если город еще не посещали
                if ((matrix[vert][j] != 0) && (matrix[vert][j] < min)) {
                    min = matrix[vert][j];   // нахожу минимальный путь
                    town = j;
                }
            }
        }
        sum += min;
        visited.push_back(town);
        coolestPath(town,matrix, n, visited,sum);
    }

}

void toPrint(int n, std::vector<std::vector<int>> &matrix) {
    std::vector<int> visited; // в каких городах была
    std::vector<std::vector<int>> vec_of_path;
    std::vector<int> price;
    int sum = 0;

    for (int i = 0; i < n; ++i) {   // для каждой вершины вызываю функ
        visited.push_back(i); // первая вершина
        coolestPath(i, matrix, n, visited, sum);
        int nu = visited[visited.size()-1];
        if (matrix[nu][i] != 0){
            visited.push_back(i);
            sum += matrix[nu][i];
        }
        price.push_back(sum);
        vec_of_path.push_back(visited);
        visited.clear();
        sum = 0;
    }

    int index_min = 0;
    int min = INT_MAX;
    for (int j = 0; j < vec_of_path.size(); ++j) {
        if (vec_of_path[j][0] == vec_of_path[j][vec_of_path[j].size()-1]){ //  доходт до начала
            if ((price[j] > 0) && (price[j]< min)){
                min = price[j];    // нашла мнимальную цену
                index_min = j;
            }
        }
    }

    std::cout << "Path:" << std::endl;

    for (auto el:vec_of_path[index_min]){
       std::cout << el << " ";
    }
    std::cout << std::endl;
    std::cout << "Cost: " << min;
}


int main() {
    int n = 0;
    std::cin >> n;
    int num = 0;
    std::vector<std::vector<int>> matrix;
    for (int k = 0; k < n; ++k) {
        std::vector<int> add;
        for (int i = 0; i < n; ++i) {
            std::cin >> num;
            add.push_back(num);
        }
        matrix.push_back(add);
        add.clear();
    }


    toPrint(n, matrix);  // правильные арги
    return 0;
}
