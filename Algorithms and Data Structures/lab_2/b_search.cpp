#include <iostream>
#include <vector>

int binarySearch(int num, const std::vector<int>& ar){   // void
    int low = 0;
    int half = 0;
    int high = ar.size() - 1;
    while (low <= high){
        half = (low + high) / 2;
        if (num < ar[half]){
            high = half - 1;
        }else if (num > ar[half]){
            low = half + 1;
        }else if (num == ar[half]){
            return half;
        }
    }
    return -1;
}


int main(){
    int num;
    std::cin >> num;
    std::vector<int> vec = {2, 4, 10, 0, 123, 12};
    std::cout << "index: " << binarySearch(num, vec);
    return 0;
}
