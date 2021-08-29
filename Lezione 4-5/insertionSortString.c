/* Scrivere una funzione che, dato un array di stringhe e la sua lunghezza, lo ordini utilizzando 
l’algoritmo Insertion Sort. Scrivere un programma che utilizzi la funzione per ordinare un array di N
stringhe lette da input e stampi in output gli elementi dell’array ordinato. Assumere che la lunghezza 
massima di una stringa sia 100 caratteri. Si puo' utilizzare la funzione strcmp in string.h per confrontare 
lessicograficamente due stringhe. Utilizzare il comando man strcmpper maggiori informazioni. 
La prima riga dell’input contiene la dimensione N dell’array. Le righe successive contengono gli elementi 
dell’array, una stringa per riga.  Ogni stringa ha lunghezza massima di 100 caratteri. L’output contiene 
gli elementi dell’array ordinato, una stringa per riga. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void insertionSort(char **a, int dim);

int main(){

    int n, i;
    scanf("%d", &n);

    char **arr = (char **) malloc(n*sizeof(char *));  // array di stringhe

    for(i=0; i<n; i++){

        arr[i] = (char *) malloc(MAX * sizeof(char)); // stringa
        scanf("%s", arr[i]);
    }

    insertionSort(arr, n);

    for(i=0; i<n; i++){

        printf("%s\n", arr[i]);
    }

    for(i=0; i<n; i++){

        free(arr[i]);
    }

    free(arr);

    return 0;
}

void insertionSort(char **a, int dim){

    int i, j;
    char * key;                          

    for(i=1; i<dim; i++){

        key = a[i];
        j= i-1;

        while (j>=0 && strcmp(a[j], key)>0){
            
            a[j+1] = a[j];
            j--;
        }
        
        a[j+1] = key;
    }
}