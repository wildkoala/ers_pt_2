#include <stdio.h>
#include "game_objects.h"


// This is really the heart of the game. It's critical that this part accounts for slaps.

Player *play_round(Player *curr_player){
    int round_over = 0;
    Card *game_pile = make_card('Z', 1); // need to have an empty deck to start with. This is just a garbage
    while(!round_over){
        Card *placed;
        placed = place_card(curr_player, game_pile);
        if (placed->num > 10){
            face_card_played(curr_player, game_pile);
        }
        else{
            curr_player = curr_player->next_player; 
        }
    }
    return curr_player;
}


