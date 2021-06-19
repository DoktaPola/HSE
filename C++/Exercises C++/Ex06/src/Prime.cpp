#include "Prime.h"

void Prime::setValue(int num) {
    this->prime = num;
}

bool Prime::checkPrime(int value) {
    if (value <= 1) {
        return false;
    } else {
        for (int i = 2; i < value; i++) {
            if (value % i == 0) {
                return false;
            }
        }
        return true;
    }
}

bool Prime::isValid() {
    return checkPrime(this->prime);
}

int Prime::countBetween(Prime &pr) {
    int count = 0;
    int start = 0;
    int end = 0;
    if (pr.prime > prime){
        start = prime;
        end = pr.prime;
    } else{
        start =pr.prime;
        end = prime;
    }
    for (int i = start + 1; i < end; ++i) {
        if (checkPrime(i)) {
            count++;
        }
    }
    return count;
}

Prime Prime::nextPrime() {
    Prime rez{};
    for (int num = prime + 1; num <= prime * prime; ++num) {
        if (checkPrime(num)) {
            rez.setValue(num);
            break;
        }
    }
    return rez;
}

int Prime::getValue() const {  // const
    return this->prime;
}
