    #include <iostream>
    #include <vector>
    #include <algorithm>

    void mergeSort(std::vector<int> &arr, int low, int mid, int high, std::vector<int> &arr2) {
        int second_half = mid;
        for (int i = low; i < high + 1; i++) {
            arr2[i] = arr[i];
        }
        for (int i = low; i < high + 1; i++) {
            if (low >= mid) {
                arr[i] = arr2[second_half];
                second_half += 1;
            } else if (second_half > high) {
                arr[i] = arr2[low];
                low += 1;
            } else if (arr2[low] >= arr2[second_half]) {
                arr[i] = arr2[second_half];
                second_half += 1;
            } else if (arr2[low] < arr2[second_half]) {
                arr[i] = arr2[low];
                low += 1;
            }
        }
    }


    std::vector<int> sort(std::vector<int> &arr, int low, int high, std::vector<int> &arr2) {
        if (low < high) {
            int mid = low + ((high - low) / 2);

            int left_start = low;
            int left_end;
            if ((high - low) % 2 == 0) {
                left_end = mid - 1;
            } else {
                left_end = mid;
            }
            sort(arr, left_start, left_end, arr2);

            int right_start = left_end + 1;
            int right_end = high;
            sort(arr, right_start, right_end, arr2);

            std::cout << "Left part: ";
            for (int i = left_start; i <= left_end; ++i) {
                std::cout << arr[i];
                if (i + 1 <= left_end) {
                    std::cout << " ";
                }

            }
            std::cout << " ";
            std::cout << std::endl;

            std::cout << "Right part: ";
            for (int j = right_start; j <= right_end; ++j) {
                std::cout << arr[j];
                if (j + 1 <= right_end) {
                    std::cout << " ";
                }
            }
            std::cout << " ";
            std::cout << std::endl;

            mergeSort(arr, low, right_start, high, arr2);

            std::cout << "Merged parts: ";
            for (int m = low; m <= high; ++m) {
                std::cout << arr[m];
                if (m + 1 <= high) {
                    std::cout << " ";
                }
            }
            std::cout << " ";
            std::cout << std::endl;
            std::cout << std::endl;

            return arr;
        }
        return arr;
    }

    int main() {
    //    int size = 13;
    //    std::vector<int> arr = {5, 1, 42, 13, 0, -1, -1000, 90, 17, 2, 4, 10, -3};
    ////    std::vector<int> arr = {5, 1, 42};
    //
    //    std::cout << std::endl;
    //    std::cout << std::endl;
    //    std::vector<int> new_(arr);
    //    int low = 0;
    //    int high = arr.size() - 1;
    //    sort(arr, low, high, new_);
    //
    //    std::cout << std::endl;
    //    for (int i : arr) {
    //        std::cout << i << " ";
    //    }
    //    std::cout << std::endl << std::endl;

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