#!/bin/bash

echo -e ">>> Hello! Welcome to ROCK-SCISSORS-PAPER game!\n"
echo -e ">>> Rules:\n Rock vs paper-> Paper wins\n Rock vs scissor-> Rock wins\n Paper vs scissor-> Scissor wins.\n"

while true
do

COMP_RAND=$((RANDOM%3+1))  # [1,2,3]
COMP_WIN=$((RANDOM%4+1))  # [1,2,3,4]=25%

echo -e ">>> Pls, enter 1 -> rock, 2 -> scissors, 3 -> paper.\n"
read dude_choice
echo -e "\n"

	while [ "$dude_choice" -gt 3 ]
	do
		echo -e ">>> Pls, enter 1 -> rock, 2 -> scissors, 3 -> paper.\n"
		read dude_choice
		echo -e "\n"
	done

if [ "$dude_choice" -eq 1 ]
then
        echo ">>> Your choice is ROCK."

elif [ "$dude_choice" -eq 2 ]
then
        echo ">>> Your choice is SCISSORS."

elif [ "$dude_choice" -eq 3 ]
then
        echo ">>> Your choice is PAPER."
fi


if [ "$COMP_WIN" -eq 1 ]  ## тут про выигрыш компа в 25 случаях(если выпало 1, то читерим)
then
        if [ "$dude_choice" -eq 1 ]
        then
                COMP_RAND=3
                echo ">>> Computer choice is PAPER!!!"

        elif [ "$dude_choice" -eq 2 ]
        then
                COMP_RAND=1
                echo ">>> Computer choice is ROCK!!!"

        elif [ "$dude_choice" -eq 3 ]
        then
                COMP_RAND=2
                echo ">>> Computer choice is SCISSORS!!!"
	fi

else
        if [ "$COMP_RAND" -eq 1 ]
        then
                echo ">>> Computer choice is ROCK."

        elif [ "$COMP_RAND" -eq 2 ]
        then
                echo ">>> Computer choice is SCISSORS."

        elif [ "$COMP_RAND" -eq 3 ]
        then
                echo ">>> Computer choice is PAPER."
        fi 
fi

# СРАВНЕНИЕ

if [ "$dude_choice" -eq "$COMP_RAND" ]
then
        echo -e ">>> Draw! Anew!\n"

elif [ "$dude_choice" -eq 1 ] && [ "$COMP_RAND" -eq 3 ]
then
        cat "./comp_win"
elif [ "$dude_choice" -eq 3 ] && [ "$COMP_RAND" -eq 1 ]
then
        cat "./human_win"

elif [ "$dude_choice" -eq 2 ] && [ "$COMP_RAND" -eq 1 ]
then
        cat "./comp_win"
elif [ "$dude_choice" -eq 1 ] && [ "$COMP_RAND" -eq 2 ]
then
        cat "./human_win"

elif [ "$dude_choice" -eq 3 ] && [ "$COMP_RAND" -eq 2 ]
then
        cat "./comp_win"
elif [ "$dude_choice" -eq 2 ] && [ "$COMP_RAND" -eq 3 ]
then
	cat "./human_win"
fi

done
