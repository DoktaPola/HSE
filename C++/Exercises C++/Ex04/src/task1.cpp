#include <iostream>
#include <string>
#include <cstring>
#include "task1.h"


int comp1(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int comp2(const void *a, const void *b) {
    double result = (*(double *) a - *(double *) b);
    if (result > 0)
        return 1;
    else if (result < 0)
        return -1;
    else
        return 0;
}

int comp3(const void *a, const void *b) {
    return strcmp(*(const char **) a, *(const char **) b); // check
}

int comp4(const void *a, const void *b) {
    return strlen(*(const char **) a) - strlen(*(const char **) b);
}

int comp5(const void *a, const void *b) {
    int rez1 = 0;
    int rez2 = 0;
    std::string s1 = *(const char **) a;
    std::string s2 = *(const char **) b;

    for (char i : s1) {
        if (i == ' ')
            rez1++;
    }

    for (char j : s2) {
        if (j == ' ')
            rez2++;
    }
    return rez1 - rez2;
}

int comp6(const void *a, const void *b) {
    return ((*(Person*)a).age - (*(Person*)b).age);
}