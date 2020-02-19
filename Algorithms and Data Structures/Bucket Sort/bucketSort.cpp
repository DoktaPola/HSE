#include <iostream>
#include <vector>
#include <cfloat>
#include <cmath>

float find_max(std::vector<float> &v) {
    float maxi = v[0];
    for (auto &el:v) {
        if (el > maxi) {
            maxi = el;
        }
    }
    return maxi;
}

float find_min(std::vector<float> &v) {
    float min = v[0];
    for (auto &el:v) {
        if (el < min) {
            min = el;
        }
    }
    return min;
}

std::vector<float> insertion_sort(std::vector<float> &arr) {
    for (int ind_1 = 1; ind_1 < arr.size(); ++ind_1) {
        int ind_2 = ind_1 - 1;
        float elem = arr[ind_1];
        while ((ind_2 >= 0) && (arr[ind_2] > elem)) {
            arr[ind_2 + 1] = arr[ind_2];
            --ind_2;
        }
        arr[ind_2 + 1] = elem;
    }
    return arr;
}


void bucket_sort(std::vector<float> &vec, int size) {

    std::vector<std::vector<float>> storage(static_cast<unsigned int>(2 * size));
    float min_el = find_min(vec);
    float max_el = find_max(vec);
    int needed_buc = 0;

    float eps = 1e-12;
    for (auto &el:vec) {
        float b_len = (max_el - min_el) / (2 * size);;
        int index = (int)((el - min_el) / b_len + eps);
        if(index >= storage.size()) index = storage.size() - 1;

        if (needed_buc == 2*size){
            needed_buc--;
            storage[index].push_back(el);
        }else{
            storage[index].push_back(el);
        }
    }

    int ind = 0;
    for (auto &bucket: storage) {
        std::vector<float> sorted_vec = {};
        if (!bucket.empty()) {
            std::cout << "Bucket:" << std::endl;
            for (auto &el:bucket) {
                std::cout << std::fixed;
                std::cout.precision(2);
                std::cout << el << " ";
            }
            std::cout << std::endl;
            std::cout << "Sorted bucket:" << std::endl;
            sorted_vec = insertion_sort(bucket);
            for (auto &el:sorted_vec) {
                std::cout << std::fixed;
                std::cout.precision(2);
                std::cout << el << " ";
            }
            std::cout << std::endl;
            std::cout << std::endl;
        } else {
            continue;
        }
        for (float el : sorted_vec) {
            vec[ind++] = el;
        }
    }
    std::cout << "Final array:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << std::fixed;
        std::cout.precision(2);
        std::cout << vec[i] << " ";
    }
}

int main() {
    int size = 0;
    float num = 0.0;
    std::cin >> size;
    std::vector<float> vec;
    for (int i = 0; i < size; ++i) {
        std::cin >> num;
        vec.push_back(num);
    }
    std::cout << "Initial array:" << std::endl;
    for (auto &el:vec) {
        std::cout << std::fixed;
        std::cout.precision(2);
        std::cout << el << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    if (vec.size() == 1) {
        return 0;
    } else {
        bucket_sort(vec, size);
    }
    return 0;
}

