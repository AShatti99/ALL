/* Modificare il Quicksort del primo esercizio in maniera tale che ordini gli elementi pari nella parte 
inferiore dell’array e quelli dispari in quella superiore. Scrivere un programma che utilizzi la funzione 
per ordinare come indicato un array di N interi letti da input. La prima riga dell’input contiene 
la dimensione N(non limitata) dell’array. Le righe successive contengono gli elementi dell’array, 
uno per riga. L’output contiene la sequenza ordinata,su una sola riga. */

#include <stdio.h>
#include <stdlib.h>

int oddEven(int a[], int dim);
void quickSort(int a[], int sx, int dx);
int partition(int a[], int sx, int dx, int pos_pivot);
void swap(int *x, int *y);

int main(){

    int n, i, p;
    scanf("%d", &n);

    int *arr = (int *) malloc (n*sizeof(int));

    for(i=0; i<n; i++){

        scanf("%d\n", &arr[i]);
    }

    p = oddEven(arr, n);
    quickSort(arr, 0, p);
    quickSort(arr, p+1, n-1);

    for(i=0; i<n; i++){

        printf("%d ", arr[i]);
    }
    
    printf("\n");

    free(arr);

    return 0;
}

int oddEven(int a[], int dim){

    int k=-1;
    for(int t=0; t<dim; t++){

        if(a[t]%2==0){

            k++;

            swap(&a[t], &a[k]);
        }
    }
    
    return k;
}

void quickSort(int a[], int sx, int dx){

    if(sx < dx){

        int rnd = rand () % (dx - sx +1) + sx;      // numero casuale tra sx e dx
        int perno = partition(a, sx, dx, rnd);

        // printf("        A\n");
        quickSort(a, sx, perno-1);
        // printf("        B\n");
        quickSort(a, perno+1, dx);
    }
}

int partition(int a[], int sx, int dx, int pos_pivot){

    int i, j;
    int pivot = a[pos_pivot];
    
    swap(&a[pos_pivot], &a[dx]);
    
    i = sx -1;

    for(j=sx; j<dx; j++){

        if(a[j] <= pivot){

            i++;

            swap(&a[i], &a[j]);
        }
    }
    
    swap(&a[i+1], &a[dx]);

    return i+1;
}

void swap(int *x, int *y){

    int temp = *x;
    *x = *y;
    *y = temp;
}