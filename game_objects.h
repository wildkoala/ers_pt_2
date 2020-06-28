#ifndef game_objects
#define game_objects
    

typedef struct card_tag {
    int num;
    char suit;
    Card *next;
} Card;


// players will really be defined by their ip+port. So theoretically a person could play multiple games from the same IP. Important if players in same house, will only see 1 public IP.
typedef struct player_tag {
    char *name; // this is going to be a string... Pointer to a char?
    char suit;
    Card *top_card;
    Player *next_player;
    int strikes; // this is how many times they have wrongly slapped the pile when they have NO cards. 3 and you're kicked!
    // how do i store a connection?? Do I even have to do that?
} Player;



// is this one even necessary? Will it be needed when there are multiple games running at the same time?
typedef struct game_tag {
    Player *current_player; 
} Game;

// In the future, whenever there's a connection, I'll want to spawn a thread that communicates with that client.
// The person will automatically be put into a lobby.
// The first person will be the lobby leader.
// People will be ordered into the game in the sequence that they came in.
// There's a 5 person cap on the game. A 6th person would cause a new game to be created.
// When a person loses all their cards, they're not kicked out of the lobby, though they will be passed when it's time to flip cards.
// Everyone one will be sent thier "place" when the game is over and one person has all the cards, or when they have 3 strikes.


#endif