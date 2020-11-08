import itertools


def to_rearrange(s: str) -> str:
    arr = list()
    for i in itertools.permutations(s, len(s)):
        arr.append(''.join(i))
    return f'{s} : {arr}'


def main():
    print(to_rearrange('abc'))


if __name__ == '__main__':
    main()
