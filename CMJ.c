#include <stdio.h>
#include <string.h>
#define TILESET 136
#define RANDSIZE 1000
#define INCREMENT 0
#define MODULUS 32768
#define SEED 1995
#define MULT 20505

struct tile{ //Data structure for a Riichi mahjong tile
    char *suit;
    int value; 
};
typedef struct tile Tile; //Global namespace alias

struct player{ //Data structure for a Riichi mahjong player
    Tile hand[14];
    char *name;
    char *seatWind;
};
typedef struct player Player;


//String array of suits and honors
char *suits[3] = {"Manzu","Pinzu","Souzu"};
char *dragons[3] = {"Red","White","Green"};
char *winds[4] = {"East","South","West","North"};

//Function declarations
void initialize(Tile deck[]);
int * LCG();
void shuffle (Tile deck[], int *shuffleOrder);

int main(void)
{
    printf("Welcome to C Mahjong.\n");
    Tile deck[TILESET]; //Array of tiles for the deck
    initialize(deck);
    int *randomOrder;
    randomOrder = LCG(); 
    shuffle(deck, randomOrder);
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
    // Function to draw a hand of 14 tiles randomly from the Tile array deck[]
    //void draw(Tile deck[]){ 
    //}

void shuffle(Tile deck[], int *shuffleOrder){
    for(int i = 0; i < TILESET;i++){
        deck[(*(shuffleOrder + i) % TILESET)] = deck[i];
    }
}

int * LCG(){
    static int randArray[RANDSIZE];
	randArray[0] = SEED;
	for(int i = 1; i < RANDSIZE; i++){
        randArray[i] = ((randArray[i - 1] * MULT) + INCREMENT) % MODULUS;
        printf("%d\n", randArray[i]);
    	}
    return randArray;
}
