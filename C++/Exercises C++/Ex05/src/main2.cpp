#include <iostream>
#include "task2.h"

int main() {
    const int size = 5;
    int arr[size]{0, 1, 0, 5, 1};
    std::cout << averageArr(arr, size);
    return 0;
}
