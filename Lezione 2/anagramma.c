/* Scrivere la funzione int anagramma(unsigned char *s1, unsigned char *s2) che restituisca 1 
se le stringhe puntate da s1 e s2 sono una l’anagramma dell’altro e 0 altrimenti. 
Esempio: anagramma(‘‘pizza’’, ‘‘pazzi’’) == 1 
Scrivere quindi un programma che legga da input due stringhe s1 e s2 e utilizzi questa funzione per stabilire 
se una e' l’anagramma dell’altra.  
Nota: utilizzare il tipo unsigned char * per le stringhe.
Hint. Data una stringa S, costruire un array aS[256] tale che aS[i] memorizzi il numero di occorrenze 
del carattere i in S. Come sono gli array aS e aZ di due stringhe S e Z che sono una l’anagramma dell’altra?
L’input e' formato da due stringhe s1 e s2 .L’output e' 1 se s1 e' l’anagramma di s2, 0 altrimenti. */

#include <stdio.h>

int anagramma(unsigned char *s1, unsigned char *s2);

int main (){

    unsigned char s[256];              // range [0, 255]
    unsigned char z[256];

    scanf("%s%s", s, z);

    printf("%d\n", anagramma(s, z));

    return 0;
}

int anagramma(unsigned char *s1, unsigned char *s2){

    int a[256]={0}, b[256]={0};         // inizializza gli interi array a 0
    int i=0;

    while(s1[i]){

        a[s1[i]]++;
        i++;
    }

    i=0;
    while(s2[i]){

        b[s2[i]]++;
        i++;
    }

    i=0;
    while(i<256){

        if(a[i]!=b[i]){

            return 0;
        }

        i++;
    }

    return 1;
}
