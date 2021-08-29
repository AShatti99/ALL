/* Scrivere un programma che legga in input un array A di stringhe e che utilizzi la funzione qsort
per ordinare in ordine alfabetico decrescente lestringhe in input. Assumere che la lunghezza massima 
di una stringa sia 100 caratteri. La prima riga dell’input contiene la dimensione N dell’array. 
Le righe successive contengono gli elementi dell’array, una stringa per riga. Ogni stringa ha lunghezza 
massima di 100 caratteri. L’output contiene gli elementi dell’array ordinato in modo decrescente, una 
stringa per riga. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int compare (const void *a, const void *b); 

int main(){

    int n, i;
    scanf("%d", &n);

    char **arr = (char **) malloc (n*sizeof(char *));
    for(i=0; i<n; i++){

        arr[i] = (char *) malloc (MAX * sizeof(char));
        scanf("%s", arr[i]);
    }

    qsort(arr, n, sizeof(char *), compare);

    for(i=0; i<n; i++){

        printf("%s\n", arr[i]);
    }

    for(i=0; i<n; i++){

        free(arr[i]);
    }

    free(arr);

    return 0;
}

int compare (const void *a, const void *b){

    char * const *x = a;
    char * const *y = b;

    return strcmp(*y, *x);
}