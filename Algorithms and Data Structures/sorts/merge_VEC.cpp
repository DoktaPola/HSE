#include <iostream>
#include <vector>
#include <algorithm>

void mergeSort(std::vector<int>& arr, int low, int mid, int high, std::vector<int>& arr2){
    int second_half = mid;
    for (int i = low; i < high + 1; i++){
        arr2[i] = arr[i];
    }
    for (int i = low; i < high + 1; i++){
        if (low >= mid) {
            arr[i] = arr2[second_half];
            second_half += 1;
        }else if (second_half > high){
            arr[i] = arr2[low];
            low += 1;
        }else if (arr2[low] >= arr2[second_half]) {
            arr[i] = arr2[second_half];
            second_half += 1;
        }else if (arr2[low] < arr2[second_half]) {
            arr[i] = arr2[low];
            low += 1;
        }
    }
}



std::vector<int> sort(std::vector<int>& arr, int low, int high, std::vector<int>& arr2){
//    int mid = low + (high - low) / 2;
    int mid = (high + low) / 2;
    if (low < high){
//        sort(arr, low, mid, arr2);
        sort(arr, low, mid-1, arr2);
        std::cout << "Left part: " << arr[low] << " ";
        std::cout << std::endl;
//        sort(arr, mid + 1, high, arr2);
        sort(arr, mid+1, high, arr2);
        std::cout << "Right part: " << arr[mid+1] << " ";
        std::cout << std::endl;
        mergeSort(arr, low, mid + 1, high, arr2);
        std::cout << "Merged parts: ";
        for (int i = low; i <= (mid+1); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
        return arr;
    }
    return arr;
 }


int main(){

    int size = 0;
    int num = 0;
    std::cin >> size;
    std::vector<int> arr;

    for (int i = 0; i < size; ++i) {
        std::cin >> num;
        arr.push_back(num);
    }
    std::cout << "Initial array:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::vector<int> new_(arr);
    int low = 0;
    int high = arr.size() - 1;
    sort(arr, low, high, new_);
    return 0;
}
