#define BUFFER 200

#ifndef game_objects_h
#define game_objects_h

// STRUCTS

// Maybe I should make cards doubly linked so that I can use it for checking for pairs and sandwiches
// changing the card_tag to Card trying to get rid of some warnings: https://stackoverflow.com/questions/9846951/expected-struct-matrix-t-but-argument-is-of-type-struct-matrix-t-no
typedef struct Card {
    int num;
    char suit;
    struct Card *next;
    struct Card *prev;
} Card;


// players will really be defined by their ip+port. So theoretically a person could play multiple games from the same IP. Important if players in same house, will only see 1 public IP.
typedef struct Player {
    char name[BUFFER];
    struct Card *top_card;
    struct Player *next_player;
    struct Player *prev_player;
    int strikes; // this is how many times they have wrongly slapped the pile when they have NO cards. 3 and you're kicked!
    // how do i store a connection?? Do I even have to do that?
} Player;



// is this one even necessary? Will it be needed when there are multiple games running at the same time?
typedef struct Game {
    Player *current_player; 
} Game;



// FUNCTIONS

Card *make_card(char given_suit, int given_num);
void print_card(Card *);
void print_hand(Card *);
void append_to_hand(Card *given, Card *hand); 
Card *prepend_to_hand(Card *given, Card *hand); // this will return a pointer to the card at the start of the linked list.

Card *make_decks(int num_decks);
Player *make_players();



// In the future, whenever there's a connection, I'll want to spawn a thread that communicates with that client.
// The person will automatically be put into a lobby.
// The first person will be the lobby leader.
// People will be ordered into the game in the sequence that they came in.
// There's a 5 person cap on the game. A 6th person would cause a new game to be created.
// When a person loses all their cards, they're not kicked out of the lobby, though they will be passed when it's time to flip cards.
// Everyone one will be sent thier "place" when the game is over and one person has all the cards, or when they have 3 strikes.


#endif //end of game_objects_c