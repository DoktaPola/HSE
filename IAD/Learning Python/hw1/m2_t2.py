def find_highest_iter() -> int:
    count = 0
    d = dict()
    for num in range(1, 1001):
        n = num
        while n != 1:
            if n % 2 == 0:
                n = n / 2
                count += 1
            else:
                n = n * 3 + 1
                count += 1
        d[num] = count
        count = 0

    maxi = 0
    val = ''
    for k, v in d.items():
        if v > maxi:
            maxi = v
            val = k
    return val


def main():
    print(find_highest_iter())


if __name__ == '__main__':
    main()
