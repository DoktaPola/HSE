def my_enumerate(smth_iterable):
    arr = list()
    count = 0
    for item in smth_iterable:
        tup = (count, item)
        arr.append(tup)
        count += 1
    return iter(arr)


def main():
    arr = [1, 2, 3, 4, 5]
    for i in my_enumerate(arr):
        print(i)


if __name__ == '__main__':
    main()
