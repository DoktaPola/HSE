"""Написать класс, реализующий итератор по текстовым файлам в указанной папке.
 Итератор должен проходить по всем строкам всех файлов,
 размер которых больше, чем 140 символов"""

import os
import re


class Iteration:
    def __init__(self, path):
        self.max = 0
        self.path = path
        self.TEXT = ''

    def __iter__(self):
        self.n = 0
        dirs = os.listdir(self.path)

        for file in dirs:
            if re.search(r'\.txt', file):
                if self.check_size(file):
                    return self
                else:
                    continue

    def __next__(self):
        if self.n <= self.max:
            result = self.TEXT[self.n]
            self.n += 1
            return result
        else:
            raise StopIteration

    def check_size(self, file):
        f = open(self.path + os.sep + file, 'r')
        self.TEXT = f.read()
        f.close()
        if len(self.TEXT) > 140:
            self.max = len(self.TEXT)
            return True
        return False


def main():
    path = 'C:' + os.sep + 'doki'

    itr = Iteration(path)
    i = iter(itr)

    # Using next to get to the next iterator element
    for letter in range(0, itr.max):
        print(next(i))


if __name__ == '__main__':
    main()
