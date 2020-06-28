#include <stdio.h>
#include <string.h>


#define BUFFER 200


int main(){

    // Ask for the number of players
    char name[20];
    printf("Enter your name:\n> ");
    fgets(name, 10, stdin);
    name[strcspn(name, "\n")] = 0;
    printf("Hello %s! \n", name);


    // Ask for the number of decks
    int num_decks;
    printf("How many decks would you like to play with?\n> ");
    scanf("%d", &num_decks); // this is a vulnerable call right? I think I need to replace this with atoi?
    printf("Setting up the game for %d decks...\n", num_decks);

    // Create 52*(num_decks) cards
    // Cards have a suit and a number
    // the suits are H,D,C,S
    // numbers are 2-14, 11-14 are Jack - Ace

    // Game object
        // players
        // initial_cards
    
    // "Players" is a struct also
        // it's an array of pointers to player structs

    // "Player" has these properties:
        // a thread
        // a connection (ip, port)
        // a top_card (pointer to a Card)
    
    // "Card"
        // suit (a single byte char)
        // number (int)
        // next (pointer to another card)
}