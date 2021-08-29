/* Scrivere una funzione che, dato un array di interi e la sua lunghezza, lo ordini utilizzando 
l’algoritmo Insertion Sort. Scrivere un programma che utilizzi la funzione per ordinare un array di N interi 
letti da input e stampi in output gli elementi dell’array ordinato. La prima riga dell’input contiene 
la dimensione N dell’array. Le righe successive contengono gli elementi dell’array, uno per riga. L’output 
contiene gli elementi dell’array ordinato, uno per riga. */

#include <stdio.h>
#include <stdlib.h> 

void insertionSort(int a[], int dim);

int main(){

    int n, i;
    scanf("%d", &n);

    int *arr = (int *) malloc (n*sizeof(int));
    for(i=0; i<n; i++){

        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    for(i=0; i<n; i++){

        printf("%d\n", arr[i]);
    }

    free(arr);

    return 0;
}

void insertionSort(int a[], int dim){

    int i, j, key;
    for(i=1; i<dim; i++){

        key = a[i];
        j= i-1;

        while (j>=0 && a[j] > key){
            
            a[j+1] = a[j];
            j--;
        }
        
        a[j+1] = key;
    }
}
