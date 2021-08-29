/* Modificare il codice del precedente esercizio “My Strcat 1” che restituisce una nuova stringa ottenuta 
concatenando due stringhe passate input. Questa volta il programma prende in input: 
    • la lunghezza della prima stringa (e alloca esattamente quanto necessario, ricordarsi il terminatore);
    • la prima stringa;
    • la lunghezza della seconda stringa;
    • la seconda stringa.
L’input e' formato, nell’ordine, da: la lunghezza della prima stringa, la prima stringa, 
la lunghezza della seconda stringa, la seconda stringa. L’unica riga dell’output contiene la stringa ottenuta 
concatenando nell’ordine le due stringhe inserite. */

#include <stdio.h>
#include <stdlib.h>

char * mystrcat2(int dimS1, char *s1, int dim2, char *s2);

int main(){

    int len1;
    scanf("%d", &len1);
    char * s = (char *) malloc((len1+1) * sizeof(char));  // +1 per il terminatore
    scanf("%s", s);

    int len2;
    scanf("%d", &len2);
    char * z = (char *) malloc((len2+1) * sizeof(char));  // +1 per il terminatore
    scanf("%s", z);

    printf("%s\n", mystrcat2(len1, s, len2, z));

    free(s), free(z);

    return 0;
}

char * mystrcat2(int dimS1, char *s1, int dim2, char *s2){

    int i = 0;
    while(s2[i])
    {
        s1[dimS1]=s2[i];
        dimS1++, i++;
    }
    s1[dimS1+1]='\0';

    return s1;
}