#include <iostream>
#include "Prime.h"

int main(){
    Prime num1,num2;

    num1.setValue(3);

    num2 = num1.nextPrime();
    std::cout << "Next prime after 3 is " << num2.getValue() << std::endl;

    std::cout << "Is 15 prime? " << num1.checkPrime(15) << std::endl;

    num2.setValue(83);
    std::cout << "Is 83 valid? " << num2.isValid() << std::endl;;

    std::cout << "Amount of primes between 3 and 83: " << num2.countBetween(num1) << std::endl;
    return 0;
}