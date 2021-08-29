/* Scrivere una funzione char * mystrcpy(char* dest, char* src) che copi src in dest 
(incluso il terminatore ’\0’) e restituisca un puntatore a dest. La funzione assume che in dest vi sia 
spazio sufficiente per contenere src (e' compito del chiamante assicurarsi che cio' sia vero).
Si noti che il comportamento di mystrcpy() e' uguale a quello della funzione strcpy() presente 
nella libreriastring. Scrivere poi un programma che:  legga una stringa da tastiera 
(di lunghezza non maggiore di 1000 caratteri); allochi spazio sufficiente per una seconda stringa 
destinata a contenere la prima; copi la prima stringa nella seconda; stampi la seconda stringa. 
L’input e' formato da una sola riga contenente una stringa di lunghezza non maggiore di 1000 caratteri.
L’unica riga dell’output contiene la stampa della seconda stringa */

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

char * mystrcpy(char* dest, char* src);

int main(){

    int i;
    char s[MAX];
    scanf("%s", s);

    while (s[i]){                                       // dimensione di s
        
        i++;
    }

    char* z=(char *) malloc ((i+1) * sizeof(char));     // alloco spazio a sufficienza + 1 per il terminatore
    z=mystrcpy(z, s);

    printf("%s\n", z);

    free(z);

    return 0;
}

char * mystrcpy(char* dest, char* src){

    int i=0;
    while (src[i]) {
        
        dest[i]=src[i];
        i++;
    }

    dest[i+1]='\0';
    
    return dest;
}