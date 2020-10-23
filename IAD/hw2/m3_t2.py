# TASK 1
def get_prime(n: int) -> list:
    fin_arr = list()
    for i in range(2, n + 1):
        for j in fin_arr:  # зачем делить на 4, если на 2 число не делится
            if i % j == 0:
                break
        else:
            fin_arr.append(i)
    print(f'All primes to {n} ')
    return fin_arr


# TASK 2
def find_all_devs(x: int) -> list:
    fin_arr = list()
    for num in range(1, x + 1):
        if x % num == 0:
            fin_arr.append(num)
    return fin_arr


# TASK 3
def nod_2(x: int, y: int) -> int:
    devs_x = find_all_devs(x)
    devs_y = find_all_devs(y)
    inter = set(devs_x).intersection(set(devs_y))
    arr = list(inter)
    print(f'NOD of {x} and {y} is ')
    return arr[len(arr) - 1]


def main():
    print('####### PRIME #########')
    print(get_prime(5))
    print(get_prime(100), '\n')

    print('######## DEVS #########')
    n = int(input('Enter, pls, num from 1 to n.'))
    print(f'All devs. of {n} ')
    print(find_all_devs(n), '\n')

    print('######## NOD ##########')
    print(nod_2(9, 27))


if __name__ == '__main__':
    main()
