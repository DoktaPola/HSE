#include <stdio.h>
#include <malloc.h>
#include "card.h"

/* ID:
 * 0  = POKER
 * 1  = DURAK
 */

int main(){
    DECK *new_deck;
    int size = 0;
    int game_id = 0;
    printf("Pls, enter size of deck and game ID: ");
    scanf("%d%d", &size, &game_id);

    DECK* full_deck = make_deck(size, game_id, new_deck);

    shuffle(full_deck);

    int cards_num = 0;
    int play_num = 0;
    printf("Pls, enter number of cards and players: ");
    scanf("%d%d", &cards_num, &play_num);
    deal(game_id, cards_num,play_num,full_deck);

    deallocate(full_deck);

    return 0;
}


