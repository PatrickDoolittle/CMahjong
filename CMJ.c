#include <stdio.h>
#include <string.h>

struct tile{ //Data structure for a Riichi mahjong tile
    char *suit;
    int value; 
};
typedef struct tile Tile; //Global namespace alias

//String array of suits and honors
char *suits[3] = {"Manzu","Pinzu","Souzu"};
char *dragons[3] = {"Red","White","Green"};
char *winds[4] = {"East","South","West","North"};

//Function declarations
void initialize(Tile deck[]);

int main(void)
{
    printf("Welcome to C Mahjong.\n");
    Tile deck[136]; //Array of tiles for the deck
    initialize(deck); 
    return 0;
}

// Function to initialize a new set of tiles.
void initialize(Tile deck[]){
    int deckIndex = 0;
    //Initialize suited tiles
    for(int i=0;i<3;i++){
        for(int j=1;j<10;j++){
            for(int k=0;k<4;k++){
                deck[deckIndex].suit = suits[i];
                deck[deckIndex].value = j;
		printf("Tile at index %d has suit %s and value %d\n", deckIndex, deck[deckIndex].suit, deck[deckIndex].value);
                deckIndex++;
            }
        }
    }
    //Initialize dragons
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            deck[deckIndex].suit = dragons[i];
            deck[deckIndex].value = 0;
	    printf("Tile at index %d has suit %s and value %d\n", deckIndex, deck[deckIndex].suit, deck[deckIndex].value);
            deckIndex++;
        }
    }
    //Initialize winds
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            deck[deckIndex].suit = winds[i];
            deck[deckIndex].value = 0;
	    printf("Tile at index %d has suit %s and value %d\n", deckIndex, deck[deckIndex].suit, deck[deckIndex].value);
            deckIndex++;
        }
    }
}
