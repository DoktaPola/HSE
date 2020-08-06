#include <iostream>

void selection_sort(int *arr, int size) {  // O(n^2)
    int maxi = 0;
    int tmp;
    for (int i = 0; i < size; ++i) {
        maxi = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[maxi]) {
                maxi = j;
            }
            tmp = arr[i];
            arr[i] = arr[maxi];
            arr[maxi] = tmp;
        }
    }
}

int main(){
    const int size = 5;
    int arr[]{2, 10, 1, 5, 89};
    selection_sort(arr, size);
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << std::endl;
    }
    return 0;
}

