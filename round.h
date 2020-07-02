//It would compile with the include statement commented out, since the main ERS2 file already knows those definitions?

//#include "game_objects.h"
#include "game_objects.h"

Player *play_round(Player *curr_player);
void face_card_played(Player *curr_player, Card *top_game_card);