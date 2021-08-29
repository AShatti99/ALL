/* Scrivere un programma che accetti in input due array ordinati di interi e restituisca in output l’unione 
ordinata dei due array. Si assuma che la lunghezza di ogni array sia fornita prima dell’immissione 
degli elementi. Per semplicita' si assuma che l’intersezione tra i due array sia vuota. L’input e' formato da:
    • dimensione del primo array;
    • lista dei valori in ordine crescente del primo array;
    • dimensione del secondo array;
    • lista dei valori in ordine crescente del secondo array.
L’output contiene l’unione ordinata dei due array, un elemento per riga */

#include <stdio.h>
#include <stdlib.h>

int * fusArrayOrd(int a[], int dimA, int b[], int dimB);

int main(){

    int i, *p;

    int dimA;
    scanf("%d", &dimA);

    int *arrA=(int *) malloc (dimA*sizeof(int));
    for(i=0; i<dimA; i++){

        scanf("%d", &arrA[i]);
    }

    int dimB;
    scanf("%d", &dimB);

    int *arrB=(int *) malloc (dimB *sizeof(int));
    for(i=0; i<dimB; i++){

        scanf("%d", &arrB[i]);
    }

    p=fusArrayOrd(arrA, dimA, arrB, dimB);

    for(i=0; i<dimA+dimB; i++){

        printf("%d\n", p[i]);
    }

    free(arrA), free(arrB);

    return 0;
}


int * fusArrayOrd(int a[], int dimA, int b[], int dimB){

    int k, i=0, j=0;
    int *m =(int *) malloc ((dimA+dimB)*sizeof(int));

    for(k=0; i<dimA && j<dimB; k++){

        if(a[i] <= b[j]){

            m[k]=a[i];
            i++;
        }
        else{

            m[k]=b[j];
            j++;
        }
    }

    while (i<dimA){                     // quello che rimane viene copiato in m
        
        m[k]=a[i];
        i++, k++;
    }

    while (j<dimB){
        
        m[k]=b[j];
        j++, k++;
    }
    
    return m;
}
