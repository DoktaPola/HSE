#ifndef KPO_TASK1_H
#define KPO_TASK1_H

#include <cstring>

template<typename T>
bool less(T first, T second) {
    if (first < second) {
        return true;
    } else {
        return false;
    }
}

template<>
bool less<const char *>(const char *first, const char *second) {
    return strcmp(first, second) < 0;
}


#endif //KPO_TASK1_H
