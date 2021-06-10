#include <stdio.h>

int LCG(int prev, int mult, int inc, int mod);

int main(void){
    int randArray[100];
    int seed = 42;
    randArray[0] = seed;
    for(int i = 1; i < 100;i++){
        randArray[i] = LCG(randArray[i - 1], 4, 3, 83); 
        printf("%d * %d + %d %% %d = %d\n", randArray[i - 1], 4, 3, 83, randArray[i]);
    }
    for(int i = 0; i < 100;i++){
        printf("%d ",randArray[i]);
	    if((i % 5) == 0 && i != 0){
            printf("\n");	
         }
    }    
    return 0;
}

int LCG(int prev, int mult, int inc, int mod){
    return ((prev * mult) + inc) % mod; 
}

