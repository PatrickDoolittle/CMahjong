#include <stdio.h>

// Source code for little test projects in C.

int main(void){
    char *classes[5] = {"RED", "WHITE","BLUE","GREEN","YELLOW"};
    for(int i = 0; i < 5; i++){
        printf("%s\n",classes[i]);
    }
    return 0;
}