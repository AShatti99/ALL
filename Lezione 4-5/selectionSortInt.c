/* Scrivere una funzione che, dato un array di interi e la sua lunghezza, lo ordini utilizzando l’algoritmo
Selection Sort. Scrivere un programma che utilizzi la funzione per ordinare un array di N interi letti 
da input e stampi in output gli elementi dell’array ordinato. La prima riga dell’input contiene la dimensione
N dell’array. Le righe successive contengono gli elementi dell’array, uno per riga. L’output contiene 
gli elementi dell’array ordinato, uno per riga. */

#include <stdio.h>
#include <stdlib.h> 

void selectionSort(int a[], int dim);
void swap(int *x, int *y);

int main(){

    int n, i;
    scanf("%d", &n);

    int * arr= (int *) malloc(n*sizeof(int));
    for(i=0; i<n; i++){

        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);

    for(i=0; i<n; i++){

        printf("%d\n", arr[i]);
    }

    free(arr);

    return 0;
}

void selectionSort(int a[], int dim){

    int i, j, min;

    for(i=0; i<dim-1; i++){

        min = i;
        for(j = i+1; j<dim; j++){

            if(a[j] < a[min]){

                min = j;
            }

        }

        swap(&a[min], &a[i]);
    }
}

void swap(int *x, int *y){

    int temp = *x;
    *x = *y;
    *y = temp;
}
