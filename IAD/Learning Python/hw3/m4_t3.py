
def my_super_cool_range(beg: float, end: float, step=None):
    while beg < end:
        yield beg  # генератор
        if step is None:
            beg += 1.0
        else:
            beg += step


def range_for_time(beg: str, end: str, step: str):
    s1_sec = beg.split(':')
    s2_sec = end.split(':')
    s3_sec = step.split(':')

    s1_sec = int(s1_sec[0]) * 3600 + int(s1_sec[1]) * 60 + int(s1_sec[2])
    s2_sec = int(s2_sec[0]) * 3600 + int(s2_sec[1]) * 60 + int(s2_sec[2])
    s3_sec = int(s3_sec[0]) * 3600 + int(s3_sec[1]) * 60 + int(s3_sec[2])
    res_sec = s1_sec
    while s1_sec < s2_sec:
        h = res_sec // 3600
        m = res_sec % 3600 // 60
        s = res_sec % 3600 % 60

        res = '{}:{}:{}'.format(h, m, s)

        yield res  # генератор
        res_sec = s3_sec + s1_sec
        s1_sec = res_sec


def main():
    # for c in my_super_cool_range(3.1, 9.5):  # without step
    # for c in my_super_cool_range(3.1, 9.5, 1.2):  # with step
    #     print(c)

    for c in range_for_time('23:40:05', '9:10:10', '00:15:05'):  # range for time
        print(c)


if __name__ == '__main__':
    main()
