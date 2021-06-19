#include <iostream>
#include "task1.h"

int main() {
    int first = 100;
    int second = 15;
    const char *x = "a";
    const char *y = "b";

    std::cout << less(first, second) << '\n' << less(x, y);

    return 0;
}