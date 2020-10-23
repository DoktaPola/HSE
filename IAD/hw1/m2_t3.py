import random


def guess_num_human():
    """     Game 'Guess Number'   """

    print("Hello! Welcome to 'Guess Number' game! Enter, pls, the highest possible border from 1 to n.")
    high_border = int(input())
    right_num = random.randint(1, high_border)

    count = 0
    print("Lets start! Guess and enter!")
    while True:
        num = int(input())
        if num == right_num:
            count += 1
            if count > 1:
                print("Victory!!!!!!!!!!!!" + f" You won for {count} tries :)")
            else:
                print("Victory!!!!!!!!!!!!" + f" You won for {count} try :)")
            break
        elif num < right_num:
            print('Too small. Next try!')
            count += 1
            continue
        elif num > right_num:
            print('Too big. Next try!')
            count += 1
            continue


def guess_num_computer(right_num: int):
    """     Game 'Guess Number'   """
    
    print("Hello! Welcome to 'Guess Number' game! Enter, pls, number from 1 to 10 000.")
    low_border = 1
    high_border = 10000
    count = 0
    print("Lets start! Guess and enter!")

    while True:
        num = random.randint(low_border, high_border)
        if num == right_num:
            count += 1
            if count > 1:
                print("Victory!!!!!!!!!!!!" + f" You won for {count} tries :)")
            else:
                print("Victory!!!!!!!!!!!!" + f" You won for {count} try :)")
            break
        elif num < right_num:
            print('Too small. Next try!')
            low_border = num
            count += 1
            continue
        elif num > right_num:
            print('Too big. Next try!')
            high_border = num
            count += 1
            continue


def main():
    ####### FUNC CALL ########

    # guess_num_human() # man plays
    guess_num_computer(88)  # comp plays


if __name__ == '__main__':
    main()
