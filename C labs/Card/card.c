#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"

DECK *make_deck(int size, int game_id, DECK *new_deck) {
    new_deck->storage = 0;
    new_deck->storage = (CARD *) calloc(size, sizeof(CARD));  // ПАМЯТЬ на 36 или 52 идет игра
    new_deck->size = size; //  ПРИСВАИВАЮ РАЗМЕР
    new_deck->game_id = game_id;

    char *face[] = {"two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "Jack", "Queen",
                    "King", "Ace"};
    char *back[] = {"hearts", "diamonds", "clubs", "spades"};

    int len_back = sizeof(*back);    // THINK!!!!!!!!
    int len_face = 13;
    int counter = 0;
    int start = 0; // с двойки или с 6 начинаем колоду

    switch (new_deck->game_id){//////////////////////
        case POKER:
            start = 0;
            break;
        case DURAK:
            start = 4;
            break;
        default:break;/////////////////////////////
    }

    for (int i = 0; i < len_back; ++i) {
        for (int j = start; j < len_face; ++j) {
            new_deck->storage[counter].face = face[j];
            new_deck->storage[counter++].back = back[i];
        }
    }
    return new_deck;
}

void shuffle(DECK *new_deck) {
    int rand_index = 0;
    int size = new_deck->size;
    srand(time(0));
    rand();
    for (int i = 0; i < size; ++i) {
        rand_index = rand() % size;
        CARD tmp = new_deck->storage[i];
        new_deck->storage[i] = new_deck->storage[rand_index];
        new_deck->storage[rand_index] = tmp;
    }
}


void deal(int game_id, int cards_num, int play_num, DECK *deck) {
    int counter = 0;
    int amount_of_cards = cards_num;

    if (game_id == POKER){
        printf("We play POKER.\n");
    } else if (game_id == DURAK){
        printf("We play DURAK.\n");
    }
    printf("\n");

    for (int i = 1; i <= play_num; i++) {
        printf("Player number ");
        printf("%d", i);
        printf(":\n");
        printf("\n");

        for (int j = 0; j < amount_of_cards; ++j) {
            char *card_f = deck->storage[counter++].face;
            char *card_b = deck->storage[counter++].back;
            printf("%s", card_f);
            printf(" of ");
            printf("%s\n", card_b);
        }
        printf("\n");
    }
}

void deallocate(DECK* deck){
    free(deck);
}