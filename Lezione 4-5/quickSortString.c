/* A partire dal codice dell’esercizio precedente, scrivere una funzione che, dato un array di stringhe 
e la sua lunghezza, lo ordini (lessicograficamente) utilizzando l’algoritmo Quicksort. Scrivere un 
programma che utilizzi la funzione per ordinare un array di N stringhe lette da input e stampi in output 
gli elementi dell’array ordinato. Assumere che la lunghezza massima di una stringa sia 100 caratteri. 
Si puo' utilizzare la funzione strcmp in string.h per confrontare lessicograficamente due stringhe.  
Utilizzare il comandoman strcmp per maggiori informazioni. La prima riga dell’input contiene la dimensione
N dell’array. Le righe successive contengono gli elementi dell’array, una stringa per riga. Ogni stringa
ha lunghezza massima di 100 caratteri. L’output contiene gli elementi dell’array ordinato, una stringa 
per riga. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 100

void quickSort(char **a, int sx, int dx);
int partition(char **a, int sx, int dx, int pos_pivot);
void swap(char **x, char **y);

int main(){

    srand(time(NULL));

    int n, i;

    scanf("%d", &n);
    char **arr = (char **) malloc(n*sizeof(char *));

    for(i=0; i<n; i++){

        arr[i]= (char *) malloc (MAX*sizeof(char));
        scanf("%s", arr[i]);
    }

    quickSort(arr, 0, n-1);

    for(i=0; i<n; i++){

        printf("%s\n", arr[i]);
    }

    for(i=0; i<n; i++){

        free(arr[i]);
    }

    free(arr);

    return 0;
}

void quickSort(char **a, int sx, int dx){

    if(sx < dx){

        int rnd = rand () % (dx - sx + 1) + sx;
        int perno = partition(a, sx, dx, rnd);

        quickSort(a, sx, perno-1);
        quickSort(a, perno+1, dx);
    }
}

int partition(char **a, int sx, int dx, int pos_pivot){

    int i, j;
    char * pivot = a[pos_pivot];

    swap(&a[pos_pivot], &a[dx]);

    i = sx -1;

    for(j=sx; j<dx; j++){

        if(strcmp(a[j], pivot)<0 || strcmp(a[j], pivot)==0){

            i++;

            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i+1], &a[dx]);

    return i+1;
}

void swap(char **x, char **y){

    char * temp = *x;
    *x = *y;
    *y = temp;
}