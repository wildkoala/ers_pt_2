#ifndef NULL
#define NULL (0)
#endif

#ifndef game_objects
#define game_objects

#include <stdio.h>
#include <stdlib.h>
#include "game_objects.h"



// FUNCTIONS



Card *make_card(char given_suit, int given_num){
    Card *temp;
    temp = malloc(sizeof(char) + sizeof(int) + sizeof(Card *));
    temp->suit = given_suit;
    temp->num = given_num;
    temp->next = NULL;
    return temp;
}

Card *make_decks(int num_decks){
    int i = 0;
    Card *first_card;
    for(num_decks; i < num_decks; i++){
        
        char suits[4] = {'S', 'H', 'D', 'C'};
        int suit_c;
        for(suit_c = 0; suit_c < 4; suit_c++){
            int card_num;
            for(card_num=2; card_num < 15; card_num++){
                make_card(suits[suit_c], card_num);
            }
        }
    }
}

void print_card(Card *given){
    printf("Card: %c %d\n", given->suit, given->num);
}


#endif // closing out game_objects