#include <iostream>
#include <vector>

int binarySearch(int low, int high, int num, const std::vector<int> &ar) {   // void & работа над выводом!!
//    int low = 0;
    int half = 0;
//    int high = ar.size() - 1;
    while (low <= high) {
        half = (low + high) / 2;
        if (num < ar[half]) {
            high = half - 1;
        } else if (num > ar[half]) {
            low = half + 1;
        } else if (num == ar[half]) {
            return half;
        }
    }
    return -1;
}

void doubling_searh(std::vector<int> &vec, int target) {
    for (int i = 0; i < vec.size(); ++i) {
        if (target == vec[i]) {
            std::cout << i;
            break;                    //?
        } else if (vec[i] < target) {
            if (i == 1) {
                i = (i * 2);
            } else if (i >1){
                i = (i * 2) - 1;
            }
        } else if (vec[i] > target) {
            int high = i;
            int low = i / 2 + 1;  // проверить
            int res = binarySearch(low, high, target, vec);
            std::cout << res;
            break;
        }
    }
}

int main() {
    int target = 0;
    std::cin >> target;
    std::vector<int> vec = {9, 23, 45, 88, 900, 1001, 1025, 2074, 30000};
    doubling_searh(vec, target);

//    int num = 0;
//    int size =0;
//    std::cin >> size;
//    std::vector<int> vec;
//    for (int i = 0;i < size; ++i){
//        std::cin >> num;
//        vec.push_back(num);
//    }
    return 0;
}