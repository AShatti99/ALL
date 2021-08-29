/* Partendo dall’implementazione del primo esercizio, implementare il Quicksort su interi con three-way 
partition. L’algoritmo si differenzia dal Quicksort per la fase di partizionamento. In questo caso 
la funzione distribuzione divide l’array in tre intervalli (invece di due): 
    1. gli elementi minori del pivot;
    2. gli elementi uguali al pivot; 
    3. gli elementi maggiori del pivot.
Scrivere un programma che utilizzi la funzione per ordinare un array di N interi letti da input.
La prima riga dell’input contiene la dimensione N (non limitata) dell’array. Le righe successive 
contengono gli elementi dell’array, uno per riga. L’output contiene gli elementi dell’array ordinato,
su una sola riga. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void threeWayQuickSort(int a[], int sx, int dx);
void partiziona(int a[], int sx, int dx, int pos_pos, int *l, int *r);

int swap(int *x, int *y);

int main(){

    srand(time(NULL));

    int n, i;
    scanf("%d", &n);

    int * arr = (int *) malloc (n*sizeof(int));

    for(i=0; i<n; i++){

        scanf("%d", &arr[i]);
    }

    threeWayQuickSort(arr, 0, n-1);

    for(i=0; i<n; i++){

        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}

void threeWayQuickSort(int a[], int sx, int dx){

    if(sx < dx){
        int l, r;
        int rnd = rand () % (dx - sx + 1) + sx;
        partiziona(a, sx, dx, rnd, &l, &r);
                                                    
        threeWayQuickSort(a, sx, l);               // gli elementi tra l e r sono gli elementi = al pivot
        threeWayQuickSort(a, r, dx);
    }
}

void partiziona(int a[], int sx, int dx, int pos_pivot, int *l, int *r){

    int i=sx-1, j=sx, k=dx;
    int pivot = a[pos_pivot];

    swap(&a[pos_pivot], &a[dx]);

    while (j<k){
        
        if(a[j]<pivot){

            i++;
            swap(&a[j], &a[i]);
            j++;
        }
        else if(a[j]>pivot){

            k--;
            swap(&a[j], &a[k]);
        }
        else{

            j++;
        }
    }
    
    swap(&a[j], &a[dx]);
    *l=i, *r=j;
}

int swap(int *x, int *y){

    int temp = *x;
    *x = *y;
    *y = temp;
}