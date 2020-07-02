#ifndef round
#define round

#include <stdio.h>
#include "game_objects.h"

// I need the struct definitions that are inside of game_objects.h but including them will be redifining the classes and mess it up.



// This function should be able to be interrupted by a slap
void face_card_played(Player *curr_player, Card *top_game_card){
    int i;
    int winner = 0;
    curr_player = curr_player->next_player;
    while(!winner){
        for(i=0; i < top_game_card->num - 10; i++){
            prepend_to_hand(curr_player->top_card, top_game_card);
            if(top_game_card->num > 10){
                printf("SAVED, PLAYER PLAYED ANOTHER FACE CARD");
                face_card_played(curr_player->next_player, top_game_card); // There's probably a better way than recursion... but how in this case?
            }
        }
        printf("Player did not get a face card in the appropriate amount of tries. The previous player won the pot!");
        winner = 1;
        // Set curr_player to the player that won.
        curr_player->prev_player;
    }
}


// This is really the heart of the game. It's critical that this part accounts for slaps.
// I need to return the player that won so that I know which player to start the next round with.

Player *play_round(Player *curr_player){
    int round_over = 0;
    Card *top_game_card = NULL; // need to have an empty deck to start with. Will NULL work for this?
    while(!round_over){
        
        // Put down a card. (Same as prepending a players top card to the game pile from a player.)
        prepend_to_hand(curr_player->top_card, top_game_card);
        print_card(top_game_card);
        // Check the top card on the deck now to see if it's a facecard
        if (top_game_card->num > 10){
            face_card_played(curr_player, top_game_card);
            round_over = 1;
        }
        else{
            curr_player = curr_player->next_player; 
        }
    }
    return curr_player;
}


/*
Card *place_card(Player *curr_player, Card *top_game_card){
    prepend_to_hand(curr_player->top_card, top_game_card);

}
*/


#endif //end of round definition