#include <stdio.h>

int main(){

    int a[]={1, 2, 3, 4};
    int *p=a;

    p[2]=5;

    for(int i=0; i<4; i++){

        printf("%d ", a[i]);   // 1 2 5 4
    }

    int b=6;
    p=&b;

    printf("\n%d\n", *p);      // 6

    scanf("%d", p);            // i puntatori non hanno bisogno di &

    return 0;
}