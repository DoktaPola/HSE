#include <iostream>

void bubble_sort(int *arr, int size) {  // O(n^2)
    int tmp;
    bool need_sort = true;
    while (need_sort) {
        need_sort = false;
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                need_sort = true;
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
            }
        }
    }
}

int main() {
    const int size = 7;
    int arr[]{10, -2, 5, 3, 4, 9, -2};
    bubble_sort(arr, size);
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }
    return 0;
}



