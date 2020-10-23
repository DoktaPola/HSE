import os
import re


def make_full_name(path, arr) -> list:
    dirs = os.listdir(path)

    for file in dirs:
        if re.search(r'..', file):  # it's file
            arr.append(path + os.sep + file)
        else:
            make_full_name(path + os.sep + file, arr)
    return arr


def main():
    path = 'C:' + os.sep + 't2' + os.sep + '1 КУРС' + os.sep + 'ПИ 1 курс'
    arr = list()
    for item in make_full_name(path, arr):
        print(item)


if __name__ == '__main__':
    main()
