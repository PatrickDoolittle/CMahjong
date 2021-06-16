/* Riichi Mahjong implemented in the C language by Patrick Doolittle
/ Project started Jun 2021. Using methods learned from a Riichi 
/ Mahjong project started in the Python language. Random Number Generator
/ and other algorithms done from scratch */

#include <stdio.h>
#include "LCG.h"

#define TILESET 136

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
//int * LCG();
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

// Initialize an array of Tiles with proper suit and value
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

// Puts the list of tiles into a random order
void shuffle(Tile deck[], int *shuffleOrder){
    for(int i = 0; i < TILESET;i++){
        deck[(*(shuffleOrder + i) % TILESET)] = deck[i];
    }
}