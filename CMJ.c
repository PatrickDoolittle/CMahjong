#include <stdio.h>
#include <string.h>
#define MAX_TILES 136
#define MAX_SUITS 3
#define MAX_DRAGONS 3
#define MAX_WINDS 4

struct tile{ //Data structure for a Riichi mahjong tile
    char *suit;
    char *value;
};
typedef struct tile Tile; //Global namespace alias

//String array of suits and honors
char *suits[MAX_SUITS] = {"Manzu","Pinzu","Souzu"};
char *dragons[3] = {"Red","White","Green"};
char *winds[4] = {"East","South","West","North"};

int main(void)
{
    printf("Welcome to C Mahjong.\n");
    Tile deck[MAX_TILES]; //Array of tiles for the deck
    initialize[deck]; 
    return 0;
}

// Function to initialize a new set of tiles.
void initialize(Tile deck[]){
    int suitedTiles = MAX_SUITS * 9 * 4;
    for(int i = 0;i<suitedTiles;i+=4){
        deck[i].suit = suits[i%MAX_SUITS]; 
    }
    for(int i=suitedTiles;i<MAX_DRAGONS;i++){
    
    }
}
