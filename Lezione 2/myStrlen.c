/* Scrivere una funzione int mystrlen(char *s) che restituisce il numero di caratteri della stringa s.
Scrivere un programma che provi questa funzione leggendo una stringa da tastiera. Si puo' assumere che la  
stringa in input contenga non piu' di 1000 caratteri. L’input e' costituito da una stringa di lunghezza 
non maggiore di 1000 caratteri. L’unica riga dell’output contiene la lunghezza della stringa. */

#include <stdio.h>
#define MAX 1000

int main(){

    char str[MAX];
    int i=0;

    scanf("%s", str);

    while(str[i]){      // str[i] != '/0' 

        i++;
    }

    printf("%d\n", i);

    return 0;
}