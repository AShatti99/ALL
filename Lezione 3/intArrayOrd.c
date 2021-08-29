/* Scrivere un programma che accetti in input due array di interi distinti e restituisca in output 
il numero di elementi che occorrono in entrambi gli array. Si assuma che la lunghezza di ogni array sia 
fornita prima dell’immissione degli elementi. Si assuma che questa volta gli array vengano inseriti
ordinati in maniera strettamente crescente. L’input e' formato da:
    • dimensione del primo array;
    • lista dei valori (distinti) del primo array;
    • dimensione del secondo array;
    • lista dei valori (distinti) del secondo array.
L’unica riga dell’output contiene il numero di elementi in comune tra il primoe il secondo array */

#include <stdio.h>
#include <stdlib.h>

int ricBin(int x[], int dim, int el);

int main(){

    int i, c=0;

    int dimA;
    scanf("%d", &dimA);

    int *a= (int *) malloc (dimA*sizeof(int));
    for(i=0; i<dimA; i++){

        scanf("%d", &a[i]);
    }
                                     

    int dimB;
    scanf("%d", &dimB);

    int *b= (int *) malloc (dimB * sizeof(int));
    for(i=0; i<dimB; i++){

        scanf("%d", &b[i]);
    }

    for(i=0; i<dimA; i++){

        if(ricBin(b, dimB, a[i])){

            c++;
        }
    }

    printf("%d\n", c);

    free(a), free(b);

    return 0;
}

int ricBin(int x[], int dim, int el){

    int cen;
    int sx=0;
    int dx=dim;

    while (sx<=dx){

        cen = (sx + dx)/2;                      
    
        if(el == x[cen]){                       

            return 1;
        }
        else if(el < x[cen]){

            dx = cen-1;
        }
        else{

            sx = cen+1;
        }
    }

    return 0;
}