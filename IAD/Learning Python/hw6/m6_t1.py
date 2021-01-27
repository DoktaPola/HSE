import random


def to_shuffle(s: str, size: int, mod: bool) -> str:
    if mod:
        return ''.join(random.choice(s) for i in range(size))
    else:
        if size > len(s):
            raise ValueError("An input string contains fewer letters, change size!")
        else:
            return ''.join(random.sample(s, len(s)))[0:size]


def main():
    print(to_shuffle('abc', 2, False))
    # print(to_shuffle('abc', 10, False))  # ERROR
    print(to_shuffle('aac', 2, False))

    print(to_shuffle('abc', 2, True))
    print(to_shuffle('abc', 5, True))


if __name__ == '__main__':
    main()
