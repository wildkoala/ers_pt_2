#ifndef NULL
#define NULL (0)
#endif

#ifndef game_objects
#define game_objects

#include <stdio.h>
#include <stdlib.h>
#include "game_objects.h"

#define BUFFER 200


// FUNCTIONS



Card *make_card(char given_suit, int given_num){
    Card *temp;
    temp = malloc(sizeof(Card));
    temp->suit = given_suit;
    temp->num = given_num;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

Player *make_player(){
    Player *temp;
    temp = malloc(sizeof(Player));
    //temp->name = {'T','E','S','T'}; // how do I save someone's name in here?
    temp->top_card = NULL;
    temp->next_player = NULL;
    return temp;
}

void add_player(Player *given_player, Player *player_list){
    Player *new_p = (Player *)given_player;
    Player *p_list = (Player *)player_list;

    if(p_list == NULL){
        p_list = new_p;
    }
    else{
        // go to the end and tack it on.
        while(p_list->next_player != NULL){
            p_list = (Player *)p_list->next_player;
        }
        p_list->next_player = (Player *)new_p;
        new_p->next_player = NULL;
    }
}

void append_to_hand(Card *given, Card *hand){
    if (hand == NULL){
        // Just point the players hand to this card
        hand = given;
    }
    else{
        // go to the end and tack it on.
        while(hand->next != NULL){
            hand = (Card *)hand->next;
        }
        hand->next = (Card *)given;
        given->prev = (Card *)hand;
        given->next = NULL;
    }
}

/*
// This should return a 1 if the pile was slapable, and 0 if it wasn't.
int was_slapable(Card *most_recent){
    if (most_recent->num == most_recent->prev->num){
        printf("You slapped a pair! Good job! You win the pile.");
        return 1;
    }
    else if(most_recent->num == most_recent->prev->prev->num){
        printf("You slapped a sandwich! Good job! You win the pile.");
        return 1;
    }
    else{
        return 0;
    }
}


void insert_to_hand(Card *given, Card *hand, int location){
    if (hand == NULL){
        // Just point the players hand to this card
        hand = given;
    }
    else{
        given->next = NULL;


    }
}
*/

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

void print_deck(Card *given){
    while(given != NULL){
        printf("Card: %c %d\n", given->suit, given->num);
        print_deck(given->next);
    }
}


#endif // closing out game_objects