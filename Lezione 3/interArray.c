/* Scrivere un programma che accetti in input due array di interi distinti e restituisca in output 
il numero di elementi che occorrono in entrambi gli array. Si assuma che la lunghezza di ogni array 
sia fornita prima dell’immissione degli elementi. L’input `e formato da: 
    • dimensione del primo array;
    • lista dei valori (distinti) del primo array;
    • dimensione del secondo array;
    • lista dei valori (distinti) del secondo array.
L’unica riga dell’output contiene il numero di elementi in comune tra il primo e il secondo array. */

#include <stdio.h>
#include <stdlib.h> 

int member(int x[], int dim, int el);

int main(){

    int i, c=0;

    int dimA;
    scanf("%d", &dimA);

    int * a = (int *) malloc (dimA * sizeof(int));
    for(i = 0; i < dimA; i++){
        
        scanf("%d", &a[i]);
    }

    int dimB;
    scanf("%d", &dimB);

    int * b = (int *) malloc (dimB * sizeof(int));
    for(i = 0; i < dimB; i++){
        
        scanf("%d", &b[i]);
    }

    for(i=0; i<dimA; i++){                      // conta intersezione

        if(member(b, dimB, a[i])){

           c++; 
        }
    }

    printf("%d\n", c);

    free(a), free(b);

    return 0;
}


int member(int x[], int dim, int el){

    int i=0;

    while (i<dim){
        
        if(el == x[i]){

            return 1;
        }

        i++;
    }
    
    return 0;
}