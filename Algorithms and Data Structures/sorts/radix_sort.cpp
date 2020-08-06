#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

int find_max(std::vector<int> &v) {
    int maxi = v[0];
    for (auto &el:v) {
        if (el > maxi) {
            maxi = el;
        }
    }
    return maxi;
}

void radix_sort(std::vector<int> &vec) {
    int max_el = find_max(vec);
    std::string s = std::to_string(max_el);
    int length = s.size();
    int rang = 10;
    for (int i = 0; i < length; i++) {
        std::vector<int> storage[rang];
        for (auto &el:vec) {
            int num = static_cast<int>(pow(10, i));
            int stor_num = el / num % 10;
            storage[stor_num].push_back(el);
        }
        vec.clear();
        for (int j = 0; j < rang; j++) {
            vec.insert(vec.end(), storage[j].begin(), storage[j].end());
        }
    }
    for (int i : vec) {
        std::cout << std::hex << i << " ";
    }
}

int main() {

    std::vector<std::string> vec = {"0", "4C7F", "CD80", "41FC", "782C", "74", "7EB1", "9A", "AA01", "73F1"};
    std::vector<int> new_vec;
    unsigned int x;
    for (auto &el:vec) {
        std::stringstream ss;
        ss << std::hex << el;
        ss >> x;
        new_vec.push_back(static_cast<int>(x));
    }
    radix_sort(new_vec);
    return 0;
}
