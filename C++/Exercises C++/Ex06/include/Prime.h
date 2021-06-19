#ifndef KPO_PRIME_H
#define KPO_PRIME_H

class Prime {
public:
    void setValue(int num);

    bool isValid();

    bool checkPrime(int value);

    int countBetween(Prime & pr);

    Prime nextPrime();

    int getValue() const;

private:
    int prime = 2;
};

#endif //KPO_PRIME_H
