#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_objects.h"


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
    Card *first_card = make_card('S', 14);
    print_card(first_card);

    
}