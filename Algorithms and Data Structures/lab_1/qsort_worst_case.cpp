#include <iostream>
#include <vector>


void qsort_worst(int size) {
    std::vector<int> even;
    std::vector<int> odd;
    for (int i = 1; i <= size; ++i) {
        if ( i%2 == 0) {
            even.push_back(i);
        }
    }
    for (int i = size; i >=1;i-- ){
        if ( i%2 !=0){
            odd.push_back(i);
        }
    }
    for (int i : even) {
        std::cout << i << " ";
    }
    for (int i : odd) {
        std::cout << i << " ";
    }
}

int main() {

    int num;
    std::cin >> num;

    qsort_worst(num);

    return 0;
}