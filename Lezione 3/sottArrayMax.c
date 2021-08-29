/* Dato un array A di n interi (positivi e negativi), scrivere un programma che identifichi il sottoarray \
di A i cui elementi hanno somma massima tra tutti gli altri sottoarray di A e ne stampi la somma. 
La prima riga dell’input contiene la dimensione n dell’array.  Le righe successive contengono gli elementi dell’array, uno per riga.
L’unica  riga  dell’output  contiene  il  valore  della  somma  del  sottoarray  disomma massima. */

#include <stdio.h>
#include <stdlib.h>

int sottArrayMax(int a[], int dim);

int main(){

    int dim;
    scanf("%d", &dim);
    int *arr=(int *) malloc(dim * sizeof(int));
    for(int i=0; i<dim; i++){

        scanf("%d", &arr[i]);
    }

    printf("%d\n", sottArrayMax(arr, dim));

    free(arr);

    return 0;
}

int sottArrayMax(int a[], int dim){

    int max=0, somma=0;

    for(int i=0; i<dim; i++){

        if(somma>0){

            somma=somma+a[i];
        }
        else{

            somma=a[i];
        }

        if(somma>max){

            max=somma;
        }
    }

    return max;
}