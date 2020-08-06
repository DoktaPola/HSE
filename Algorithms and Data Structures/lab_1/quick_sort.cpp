#include <iostream>
#include <vector>

void Swap(int &el1, int &el2) {
    int tmp = el1;
    el1 = el2;
    el2 = tmp;
}

void QuickSort(std::vector<int>& arr, int low, int high) {
    int l = low, h = high;
//    int pointer = low + (high - low + 1) / 2;
//    int pointer = low + (high - low ) / 2;
    int pointer = (high + low ) / 2;

    int pivot = arr[pointer];
    while (low <= high) {
        while (arr[low] < pivot) {
            low++;
        }
        while (arr[high] > pivot) {
            high--;
        }
        if (low <= high) {
            Swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }



    if (high > l) {
        QuickSort(arr, l, high);
    }
    if (low < h) {

        QuickSort(arr, low, h);
    }
}


int main() {

    int size = 0;
    int num = 0;
    std::cin >> size;
    std::vector<int> arr;
    for (int i = 0; i < size; ++i) {
        std::cin >> num;
        arr.push_back(num);
    }
    std::cout << "Initial array:" << std::endl;
    for (int el : arr) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    int low = 0;
    int high = size - 1;

    QuickSort(arr, low, high);
    return 0;
}
