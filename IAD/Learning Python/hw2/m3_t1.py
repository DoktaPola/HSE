from typing import Any


# TASK 1
def find_max_nums(num1: int, num2: int) -> int:  # NUMS
    if num1 > num2:
        return num1
    else:
        return num2


def find_min_nums(num1: int, num2: int) -> int:
    if num1 < num2:
        return num1
    else:
        return num2


def find_max_str(str1: str, str2: str) -> str:  # STR
    if str1 > str2:
        return str1
    else:
        return str2


def find_min_str(str1: str, str2: str) -> str:  # STR
    if str1 < str2:
        return str1
    else:
        return str2


def find_max_arr(arr1: list, arr2: list):  # ARR
    # length
    print(f'Between {arr1} and {arr2}: ')
    if len(arr1) > len(arr2):
        print(f'{arr1} is MAX.')
    elif len(arr1) < len(arr2):
        print(f'{arr2} is MAX.')
    else:
        # lexicographical order
        print(f'MAX arr is ', max(arr1, arr2), '\n')


def find_min_arr(arr1: list, arr2: list):  # ARR
    # length
    print(f'Between {arr1} and {arr2}: ')
    if len(arr1) < len(arr2):
        print(f'{arr1} is MIN.')
    elif len(arr1) > len(arr2):
        print(f'{arr2} is MIN.')
    else:
        # lexicographical order
        print(f'MIN arr is ', min(arr1, arr2), '\n')


# TASK 2 + 3
def check_similar(arr: list) -> bool:
    prev = 0
    Flag = False
    for a in arr:
        if a == prev:
            return True
        else:
            prev = a

    if not Flag:
        return False


def find_max(*args) -> Any:
    if type(args[0]) is not list:
        return max(args)
    else:
        # length
        length = -1
        maxi = args[0]
        len_arr = list()
        for arr in args:
            len_arr.append(len(arr))
            if len(arr) > length:
                length = len(arr)

        if check_similar(len_arr): # if some equal
            # lexicographical order
            print(f'Between ', args)
            lst = list()
            for arr in args:
                if len(arr) == length:
                    lst.append(arr)

            print(f'MAX arr is ', max(lst), '\n')
        else:
            length = -1
            for arr in args:
                if len(arr) > length:
                    length = len(arr)
                    maxi = arr
            print(f'Between ', args)
            print(f'{maxi} is MAX.', '\n')


def find_min(*args) -> Any:
    if type(args[0]) is not list:
        return min(args)
    else:
        # length
        length = len(args[0])
        mini = args[0]
        len_arr = list()
        for arr in args:
            len_arr.append(len(arr))
            if len(arr) < length:
                length = len(arr)

        if check_similar(len_arr):
            # lexicographical order
            print(f'Between ', args)
            print(f'MIN arr is ', min(args), '\n')
        else:
            length = -1
            for arr in args:
                if len(arr) < length:
                    length = len(arr)
                    mini = arr
            print(f'Between ', args)
            print(f'{mini} is MIN.', '\n')





def main():
    ############################### TASK 1 ###############################################
    # print('######### NUM #########')
    # print('MAX NUM: ', find_max_nums(2, 3), '\n')
    #
    # print('MIN NUM: ', find_min_nums(2, 3), '\n')
    #
    # print('########## STR ###########')
    # print('MAX STR: ', find_max_str('x', 'abc'))
    # print('MAX STR: ', find_max_str('Hello World!', 'Are u here?'), '\n')
    #
    # print('MIN STR: ', find_min_str('x', 'abc'))
    # print('MIN STR: ', find_min_str('Hello World!', 'Are u here?'), '\n')
    #
    # print('########## ARR ##########')
    # find_max_arr(['x'], ['abc', 1])
    # find_max_arr(['x', -1], ['abc', 1])
    # find_max_arr(['abc', -1], ['abc', 1])
    # print('\n')
    #
    # find_min_arr(['x'], ['abc', 1])
    # find_min_arr(['x', -1], ['abc', 1])
    # find_min_arr(['abc', -1], ['abc', 1])
    # print('\n')

    ######################################## TASK 2+3 #######################################
    print('######### NUM #########')
    print('MAX NUM: ', find_max(5.5, 3.01))
    print('MAX NUM: ', find_max(5, 3, 1, 10), '\n')

    print('MIN NUM: ', find_min(5.5, 3.01))
    print('MAX NUM: ', find_min(5, 3, 1, 10), '\n')

    print('########## STR ###########')
    print('MAX STR: ', find_max('x', 'abc', 'hhhhu'))
    print('MAX STR: ', find_max('Hello World!', 'Are u here?', 'he can help me'), '\n')

    print('MIN STR: ', find_min('x', 'abc', 'hhhu'))
    print('MIN STR: ', find_min('Hello World!', 'Are u here?', 'he can help me'), '\n')

    print('########## ARR ##########')
    find_max(['x'], ['abc', 1], ['none', 2, 36])
    find_max(['x', -1], ['abc', 1], ['rrr', 'ffffffff'])
    find_max(['abc', -1], ['abc', 1], ['one'])
    print('\n')

    find_min(['x'], ['abc', 1], ['none', 2, 36])
    find_min(['x', -1], ['abc', 1], ['rrr', 'ffffffff'])
    find_min(['abc', -1], ['abc', 1], ['one'])
    print('\n')


if __name__ == '__main__':
    main()
