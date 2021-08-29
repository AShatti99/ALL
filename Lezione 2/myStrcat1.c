/* Implementare la funzione char * mystrcat1(char *s1, char *s2) che restituisce un puntatore alla nuova 
stringa ottenuta concatenando le stringhe puntate da s1 e s2. Scrivere un programma che legga due stringhe 
da tastiera e stampi la stringa ottenuta concatenandole.  Si puo' assumere che le stringhe in input 
contengano non piu' di 1000 caratteri. Notare che il comportamento di mystrcat1() e' diverso da quello 
della funzione strcat() presente nella libreria string. L’input e' formato da due stringhe di lunghezza 
non maggiore di 1000 caratteri. L’unica riga dell’output contiene la stringa ottenuta concatenando 
nell’ordine le due stringhe inserite. */

#include <stdio.h>
#define MAX 1000

char * mystrcat1(char *s1, char *s2);

int main(){

    char s[MAX], z[MAX];

    scanf("%s%s", s, z);

    printf("%s\n", mystrcat1(s, z));

    return 0;
}

char * mystrcat1(char *s1, char *s2){

    int i=0, j=0;
    
    while(s1[i]){           // dimensione s1
        
        i++;
    }

    while (s2[j])           // concatena
    {
        s1[i]=s2[j];
        i++, j++;
    }

    s1[i+1]='\0';
    
    return s1;
}