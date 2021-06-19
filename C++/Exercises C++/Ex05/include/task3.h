#ifndef KPO_TASK3_H
#define KPO_TASK3_H

template <typename T, unsigned int size >
T minArr(T(&arr)[size]) {
    T min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

#endif //KPO_TASK3_H
