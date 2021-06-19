#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task1.h"

using namespace std;

int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    // Рандомизация по таймеру
    srand(time(nullptr));

    for (int i = 1; i <= 50; i++){
        const size_t LS = 10000 + i * 2000;
        // генерируем случайные данные
        generate(arr, arr + LS, rnd());
        copy(arr, arr + LS, arr_copy);
        // засекаем время
        time_t start = clock();
        // выполняем сортировку, используя функцию qsort
        qsort(arr, LS, sizeof(int), comp);
        cout << LS << ";" << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\t;";
        // снова засекаем время
        start = clock();
        // выполняем сортировку, используя алгоритм С++
        sort(arr_copy, arr_copy + LS);
        cout << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
    }
    return 0;
}