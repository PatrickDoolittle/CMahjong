#include <stdio.h>

int main(void){
    int a[5] = {1,2,3,4,5};
    int *b;
    b = a;
    printf("%d\n", *(b));
    printf("%d\n", b);
    printf("%d\n", &b);
    for(int i = 0; i < 5; i++){
        printf("%d\n", *(b + i));
    }
    return 0;
}
