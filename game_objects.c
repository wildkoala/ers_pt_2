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
    snprintf(temp->name,BUFFER,"DEFAULT");
    temp->top_card = NULL;
    temp->next_player = NULL;
    temp->prev_player = NULL;
    temp->strikes = 0;
    return temp;
}

Player *make_players(int num_players){
    int i;
    Player *player_list = NULL;
    for(i=0; i< num_players; i++){
        Player *new_p = make_player();
        if(player_list == NULL){
            player_list = new_p;
        }
        else{
            while(player_list->next_player != NULL){
                player_list = player_list->next_player;
            }
            player_list->next_player = new_p;
            new_p->prev_player = player_list;
        }
    }
    
    while(player_list->prev_player != NULL){
        player_list = player_list->prev_player;
    }

    return player_list;

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

Card *prepend_to_hand(Card *given, Card *hand){
    if (hand == NULL){
        // Just point the players hand to this card
        hand = given;
        hand->next = NULL;
        hand->prev = NULL;
        return hand;
    }
    else{
        // Make the given the first card, and point it's next to the current hand's top card.
        hand->prev = given;
        given->next = hand;
        return given;
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
    int i;
    Card *deck = NULL;
    printf("About to start making cards:\n");
    for(i=0; i < num_decks; i++){
        
        char suits[4] = {'S', 'H', 'D', 'C'};
        int suit_c;
        for(suit_c = 0; suit_c < 4; suit_c++){
            int card_num;
            for(card_num=2; card_num < 15; card_num++){
                Card *new_card;
                new_card = make_card(suits[suit_c], card_num);
                print_card(new_card);
                deck = prepend_to_hand(new_card, deck);
            }
        }
    }
    return deck;
}

void print_card(Card *given){
    printf("Card: %c %d\n", given->suit, given->num);
}

void print_hand(Card *given){
    printf("IN PRINT_HAND:\n");
    while(given != NULL){
        printf("Card: %c %d\n", given->suit, given->num);
        print_hand(given->next);
    }
}


#endif // closing out game_objects