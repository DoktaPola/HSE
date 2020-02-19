#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

int find_max(std::vector<std::string> &v) {
    int maxi = v[0].size();
    for (auto &el:v) {
        if (el.size() > maxi) {
            maxi = el.size();
        }
    }
    return maxi;
}

void radix_sort(std::vector<std::string> &vec) {
    std::vector<char> hex_vec = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    std::vector<std::string> for_1_dig;

    int max_el = find_max(vec);
    int position = 1;
    int length = max_el;
    int rang = 16;
    int len_for_output = 0;
    for (int i = 0; i < length; i++) {
        std::vector<std::string> storage[rang];
        len_for_output = length - 1;
        for (std::string &el:vec) {
            int dig_pos = el.size() - position;
            if (dig_pos < 0){
                for_1_dig.push_back(el);//
            } else{
                char digit = el[dig_pos]; // иду с конца
                int pos = std::find(hex_vec.begin(), hex_vec.end(), digit) - hex_vec.begin();
                storage[pos].push_back(el);
            }
        }
        position++;
        vec.clear();


        vec.insert(vec.end(), for_1_dig.begin(), for_1_dig.end());
        for_1_dig.clear();

        for (int j = 0; j < rang; j++) {
            vec.insert(vec.end(), storage[j].begin(), storage[j].end());
        }

        std::cout << "Sorting by " << len_for_output - i <<" digit:" << std::endl;

        for(auto&el:vec){
            std::cout << el << std::endl;
        }
        std::cout << std::endl;

    }
}

int main() {
    int size = 0;
    std::string s;
    std::cin >> size;
    std::vector<std::string> vec;
    for (int i = 0; i < size; ++i) {
        std::cin >> s;
        vec.push_back(s);
    }
    radix_sort(vec);
    return 0;
}
