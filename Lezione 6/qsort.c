/* Scrivere un programma che utilizzi la funzione qsort e ordini un vettore di interi (in input), 
in modo da ottenere il seguente effetto. L’array ordinato deve contenere prima tutti i numeri pari e, 
a seguire, i numeri dispari. Si assuma che il numero 0 sia pari. I numeri pari devono essere ordinati 
in modo crescente fra di loro. I numeri dispari devono essere ordinati in modo decrescente fra di loro.
La prima riga dell’input contiene la dimensione N (non limitata) dell’array. Le righe successive 
contengono gli elementi dell’array, uno per riga. L’output contiene gli elementi dell’array ordinati come 
richiesto, uno per riga.*/

#include <stdio.h>
#include <stdlib.h>

int compare (const void *a, const void *b); 

int main(){

    int n, i;
    scanf("%d", &n);

    int *arr=(int *) malloc(n*sizeof(int));
    for(i=0; i<n; i++){

        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    for(i=0; i<n; i++){

        printf("%d\n", arr[i]);
    }

    free(arr);

    return 0;
}

int compare (const void *a, const void *b){

    const int *x= a;
    const int *y= b;

    if(*x %2 ==0 && *y%2 ==0){                      // se sono entrambi pari -> ordine crescente

        return *x - *y;
    }
    else if(*x % 2 !=0 && *y % 2 !=0){              // se sono entrambi dispari -> ordine decrescente

        return *y - *x;
    }
    else{                                           // altrimenti se sono diversi, il pari viene prima

        if(*x%2==0){

            return -1;
        }
        else{

            return 1;
        }
    }    
}
