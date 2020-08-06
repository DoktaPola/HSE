#include <iostream>

void insertion_sort(int *arr, int size) {  // O(n^2)
    std::cout << "Initial array:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    int count = 1;
    for (int ind_1 = 1; ind_1 < size; ++ind_1) {
        int ind_2 = ind_1 - 1;
        int elem = arr[ind_1];
        while ((ind_2 >= 0) && (arr[ind_2] > elem)) {
            arr[ind_2 + 1] = arr[ind_2];
            --ind_2;
        }
        arr[ind_2 + 1] = elem;

        std::cout << "Insertion - Element #" << count << std::endl;
        for (int k = 0; k < size; k++) {

            std::cout << arr[k] << " ";
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
