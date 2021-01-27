class Fraction:
    def __init__(self, numerator, denominator):
        self.numerator = numerator
        self.denominator = denominator
        self.reduce_fraction(numerator, denominator)  # сокр дробь

    def _nod(self, nomer, denom):
        if nomer < 0:  # если отрицательное
            return 1
        while nomer != 0 and denom != 0:
            if nomer > denom:
                nomer %= denom
            else:
                denom %= nomer
        return nomer + denom

    def reduce_fraction(self, nomer, denom):
        nod = self._nod(nomer, denom)
        if nod != 1:
            self.numerator = nomer // nod
            self.denominator = denom // nod
        else:
            self.numerator = nomer
            self.denominator = denom

    def __str__(self) -> str:
        if self.denominator == 1:
            return f'{str(self.numerator)}'
        else:
            return f'{str(self.numerator)}/{str(self.denominator)}'

    def __repr__(self):
        return f'Fraction({self.numerator}/{self.denominator})'

    def additional_preps(self, other):
        if self.denominator == other.denominator:
            return Fraction(self.numerator + other.numerator, self.denominator)
        else:
            numer1 = self.numerator * other.denominator
            numer2 = other.numerator * self.denominator
            dev = self.denominator * other.denominator
            return numer1, numer2, dev

    def __add__(self, other):
        numer1, numer2, dev = self.additional_preps(other)
        self.reduce_fraction(numer1 + numer2, dev)
        return Fraction(self.numerator, self.denominator)

    def __sub__(self, other):
        numer1, numer2, dev = self.additional_preps(other)
        self.reduce_fraction(numer1 - numer2, dev)
        return Fraction(self.numerator, self.denominator)

    def __mul__(self, other):
        self.reduce_fraction(self.numerator * other.numerator, self.denominator * other.denominator)
        return Fraction(self.numerator, self.denominator)

    def __truediv__(self, other):
        self.reduce_fraction(self.numerator * other.denominator, self.denominator * other.numerator)
        return Fraction(self.numerator, self.denominator)

    def __eq__(self, other):
        if self.denominator == other.denominator:
            if self.numerator == other.numerator:
                return True
            else:
                return False
        else:
            numer1, numer2, dev = self.additional_preps(other)
            if numer1 == numer2:
                return True
            else:
                return False

    def __ne__(self, other):  # CHANGE
        if self.denominator == other.denominator:
            if self.numerator != other.numerator:
                return True
            else:
                return False
        else:
            numer1, numer2, dev = self.additional_preps(other)
            if numer1 != numer2:
                return True
            else:
                return False

    def __lt__(self, other):
        if self.denominator == other.denominator:
            if self.numerator >= other.numerator:
                return False
            elif self.numerator < other.numerator:
                return True
        else:
            numer1, numer2, dev = self.additional_preps(other)
            if numer1 >= numer2:
                return False
            elif numer1 < numer2:
                return True

    def __le__(self, other):
        if self.denominator == other.denominator:
            if self.numerator > other.numerator:
                return False
            elif self.numerator <= other.numerator:
                return True
        else:
            numer1, numer2, dev = self.additional_preps(other)
            if numer1 > numer2:
                return False
            elif numer1 <= numer2:
                return True

    def __gt__(self, other):
        if self.denominator == other.denominator:
            if self.numerator > other.numerator:
                return True
            elif self.numerator <= other.numerator:
                return False
        else:
            numer1, numer2, dev = self.additional_preps(other)
            if numer1 > numer2:
                return True
            elif numer1 <= numer2:
                return False

    def __ge__(self, other):
        if self.denominator == other.denominator:
            if self.numerator >= other.numerator:
                return True
            elif self.numerator < other.numerator:
                return False
        else:
            numer1, numer2, dev = self.additional_preps(other)
            if numer1 >= numer2:
                return True
            elif numer1 < numer2:
                return False


def main():
    # initialization
    fr = Fraction(5, 7)
    # fr = Fraction(2, 4)

    # __str__
    s = str(fr)
    print(s, f'has type:{type(s)}')

    # __repr__
    print(repr(fr))

    # __add__
    fr1 = Fraction(1, 3)
    fr2 = Fraction(1, 2)
    print(fr1 + fr2)

    # __sub__
    fr3 = Fraction(1, 2)
    fr4 = Fraction(4, 5)
    print(fr3 - fr4)

    # __mul__
    fr5 = Fraction(1, 2)
    fr6 = Fraction(4, 5)
    print(fr5 * fr6)

    # __truediv__
    fr7 = Fraction(1, 2)
    fr8 = Fraction(1, 8)
    print(fr7 / fr8)

    # __eq__
    fr9 = Fraction(1, 2)
    fr10 = Fraction(2, 4)
    # fr9 = Fraction(1, 2)
    # fr10 = Fraction(3, 8)
    print(fr9 == fr10)

    # __ne__
    fr11 = Fraction(1, 2)
    fr12 = Fraction(3, 8)
    # fr11 = Fraction(1, 2)
    # fr12 = Fraction(2, 4)
    print(fr11 != fr12)

    # __lt__
    fr13 = Fraction(1, 2)
    fr14 = Fraction(3, 8)
    # fr13 = Fraction(1, 2)
    # fr14 = Fraction(2, 4)
    print(fr13 < fr14)

    # __le__
    # fr15 = Fraction(3, 8)
    # fr16 = Fraction(1, 2)
    fr15 = Fraction(1, 2)
    fr16 = Fraction(2, 4)
    print(fr15 <= fr16)

    # __gt__
    fr17 = Fraction(1, 2)
    fr18 = Fraction(3, 8)
    # fr17 = Fraction(1, 2)
    # fr18 = Fraction(2, 4)
    print(fr17 > fr18)

    # __ge__
    # fr19 = Fraction(3, 8)
    # fr20 = Fraction(1, 2)
    fr19 = Fraction(1, 2)
    fr20 = Fraction(2, 4)
    print(fr19 >= fr20)


if __name__ == '__main__':
    main()
