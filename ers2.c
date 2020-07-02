#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_objects.h"
#include "round.h"


#define BUFFER 200


int main(){

    // Ask for the number of players
    char name[BUFFER];
    printf("Enter your name:\n> ");
    fgets(name, BUFFER, stdin);
    name[strcspn(name, "\n")] = 0;
    printf("Hello %s! \n", name);


    // Ask for the number of decks
    char num_decks[BUFFER];
    int result;
    printf("How many decks would you like to play with?\n> ");
    fgets(num_decks, BUFFER, stdin);
    result = atoi(num_decks);
    printf("Setting up the game for %d decks...\n", result);

    // Just do 1 deck for now.
    // Just print out all the cards to verify that it's working.
    Card *game_cards = make_decks(1);
    print_hand(game_cards);

    // Game cards is a pointer to the first card in a linked list
    // Card *game_cards = make_card('S', 14);
    // print_card(game_cards);

    // Just do 4 players for now
    // curr_player is a pointer to the player whose turn it is at the moment.
    Player *curr_player = make_players(4);
    
    // Deal out the cards
    //deal_hands(game_cards, curr_player);

    // Start the game loop
    int winner = 0;
    while(!winner){
        // Wait for the user to press the up arrow, then:
        Player *winning_player = play_round(curr_player);
        curr_player = winning_player;
        //winner = check_for_winner();

    }
}