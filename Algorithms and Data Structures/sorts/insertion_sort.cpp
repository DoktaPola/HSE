#include <iostream>

void insertion_sort(int *arr, int size) {  // O(n^2)
    std::cout << "Initial array:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    int count = 1;
    for (int i = 1; i < size; ++i) {
        while ((i - 1 >= 0) && (arr[i] < arr[i - 1])) {
            int tmp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = tmp;
            i--;
        }
        std::cout << "Insertion - Element #" << count << std::endl;
        for (int j = 0; j < size; j++) {

            std::cout << arr[j] << " ";
        }
        std::cout << std::endl;
        count++;
    }
}

int main() {
//    const int size = 7;
//    int arr[]{10, -2, 5, 3, 4, 9, -2};
    int size = 0;
    int num = 0;
    std::cin >> size;
    int arr[size];
    for (int i = 0; i < size; ++i) {
        std::cin >> num;
        arr[i] = num;
    }
    insertion_sort(arr, size);
//    for (int i = 0; i < size; i++) {
//        std::cout << arr[i] << std::endl;
//    }
    return 0;
}


