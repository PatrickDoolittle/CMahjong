#define INCREMENT 0
#define MODULUS 32768
#define SEED 1995
#define MULT 20505
#define RANDSIZE 1000


int * LCG(){
    static int randArray[RANDSIZE];
	randArray[0] = SEED;
	for(int i = 1; i < RANDSIZE; i++){
        randArray[i] = ((randArray[i - 1] * MULT) + INCREMENT) % MODULUS;
    	}
    return randArray;
}