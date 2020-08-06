#include <iostream>

void sequential_search(const int *arr, const int size, int num) {
    std::cout << "Linear search:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
        if (arr[i] == num) {
//            std::cout << arr[i];
        }
    }

//    return INT_MAX;
}

int main() {
    int size = 0;
    std::cin >> size;
    int target = 0;
    std::cin >> target;
    int num;
    int arr[size];
    std::cout << "Initial array:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cin >> num;
        arr[i] = num;
        std::cout << num << " ";
    }
    std::cout << std::endl;
    sequential_search(arr, size, target);
    return 0;
}