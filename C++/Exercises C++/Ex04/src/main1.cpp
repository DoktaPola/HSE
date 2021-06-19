#include <cstdlib>
#include <iostream>
#include "task1.h"

int main() {
    const size_t n = 3;
    int arr[n] = {2,10,5};
    qsort(arr, n, sizeof(int), comp1);

    for (int i : arr)
        std::cout << i << ' ';
    
    return 0;
}