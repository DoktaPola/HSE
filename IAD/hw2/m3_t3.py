# TASK 1

def ss_convertor(num: int, ss_from: int, ss_to: int) -> int:
    if ss_from == 2:
        if ss_to == 8:
            pass
        elif ss_to == 10:
            fin_num = 0
            size = len(str(num)) - 1
            for n in str(num):
                fin_num += int(n) * 2 ** size
                size -= 1
            return fin_num
        elif ss_to == 16:
            pass

    elif ss_from == 8:
        if ss_to == 2:
            pass
        elif ss_to == 10:
            fin_num = 0
            size = len(str(num)) - 1
            for n in str(num):
                fin_num += int(n) * 8 ** size
                size -= 1
            return fin_num
        elif ss_to == 16:
            pass

    elif ss_from == 10:
        if ss_to == 2:
            s = ''
            while num > 0:
                n = num % 2
                s += str(n)
                num = num // 2
            s = s[::-1]
            return int(s)
        elif ss_to == 8:
            s = ''
            while num > 0: ##
                n = num % 8
                s += str(n)
                num = num // 8
            s = s[::-1]
            return int(s)
        elif ss_to == 16:
            s = ''
            while num > 0:##
                n = num % 16
                s += str(n)
                num = num // 16
            s = s[::-1]
            return int(s)

    elif ss_from == 16:
        if ss_to == 2:
            pass
        elif ss_to == 8:
            pass
        elif ss_to == 10:
            fin_num = 0
            size = len(str(num)) - 1
            for n in str(num):
                fin_num += int(n) * 16 ** size
                size -= 1
            return fin_num


def main():
    print(ss_convertor(111, 2, 10))
    print(ss_convertor(7, 10, 2))
    print(ss_convertor(110, 8, 10))
    print(ss_convertor(72, 10, 8))  ##
    print(ss_convertor(108, 16, 10))
    print(ss_convertor(264, 10, 16))  ##


if __name__ == '__main__':
    main()
