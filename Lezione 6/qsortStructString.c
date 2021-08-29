/* Scrivere un programma che utilizzi la funzione qsort per ordinare un array di stringhe. Le stringhe 
devono essere ordinate per lunghezza crescente. A parita' di lunghezza, si utilizzi l’ordinamento 
lessicografico. Utilizzare una struct che memorizzi una stringa e la sua lunghezza per evitare di calcolare
quest’ultima ad ogni confronto. La prima riga dell’input contiene la dimensione N dell’array. Le righe 
successive contengono gli elementi dell’array, una stringa per riga. Ogni stringa ha lunghezza massima 
di 100 caratteri. L’output contiene gli elementi dell’array ordinato come richiesto, una stringa per riga.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _string{

    char s[100];
    int dim;
} string;

int compare (const void *a, const void *b);

int main(){

    int n, i;
    scanf("%d", &n);

    string * s = (string *) malloc (n*sizeof(string));
    for(i=0; i<n; i++){

        scanf("%s", s[i].s);
        s[i].dim = strlen(s[i].s);
    }
    
    qsort(s, n, sizeof(string), compare);

    for(i=0; i<n; i++){

        printf("%s\n", s[i].s);
    }

    free(s);

    return 0;
}

int compare (const void *a, const void *b){

    const string *x = a;
    const string *y = b;

    if(x->dim == y->dim){

        return strcmp(x->s, y->s);
    }

    return x->dim - y->dim;
}