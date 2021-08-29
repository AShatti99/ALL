/* Si scriva una funzione char* product(char *str, int k) che data una stringa str e un intero k 
restituisca una stringa ottenuta concatenando k volte la stringa str. Si scriva un programma che legga 
in input:
    • una stringa (assumendo che la stringa sia non piu' lunga di 1000 caratteri);
    • un intero, che indica quante volte ripetere la stringa, e infine stampi l’output di product().
L’input e' costituito, nell’ordine, da: una stringa di lunghezza non superiore a 1000 caratteri;  
un intero k che indica quante volte ripetere la stringa inserita. L’unica riga dell’output e' formata 
da una stringa contenente k concatenazioni della stringa data in input. */

#include <stdio.h>
#include <stdlib.h> 
#define MAX 1000

char* product(char *str, int k);
int mystrlen(char *s);

int main(){

    char s[MAX];
    int v;

    scanf("%s%d", s, &v);

    printf("%s\n", product(s, v));
    return 0;
}

char* product(char *str, int k){

    int i=0;
    int len=mystrlen(str);
    char * strP = (char *) malloc((len * k +1) * sizeof(char)); 
    
    while (i<k*len) {
        
        strP[i]=str[i%len];
        i++;
    }

    strP[i++]='\0';
    
    return strP;
}

int mystrlen(char *s){

    int i=0;

    while (s[i]){

        i++;
    }
    
    return i;
}