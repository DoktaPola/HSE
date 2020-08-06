#ifndef CARD_CARD_H
#define CARD_CARD_H

typedef enum gameID{
    POKER,
    DURAK,
}GameID;

typedef struct Card {
    char *face;
    char *back;
}CARD;
///////////////////////
typedef struct Deck {
    int size;
    CARD *storage;
    int game_id;
}DECK;


DECK* make_deck(int size, int game_id, DECK *new_deck);
void shuffle(DECK* new_deck);
void deal(int game_id, int cards_num, int play_num, DECK* deck);
void deallocate(DECK* deck);

#endif //CARD_CARD_H
