/* Scrivere una funzione int* FindVal(int a[], int len, int val) che, dato un array a 
e la sua lunghezza len, cerchi il valore val all’interno di a e restituisca un puntatore alla cella 
che lo contiene, o la costante predefinita NULL se val non e' contenuto in a.
Scrivere poi un programma che legga da input un array di 10 interi e un intero val e stampi trovato
se l’intero val si trova nell’array, non trovato altrimenti. L’input e' formato da dieci righe contenenti 
gli elementi dell’array, seguite dall’intero val da cercare. 
L’unica riga dell’output contiene la stringa trovato se l’intero val si trova nell’array, 
non trovato altrimenti */

#include <stdio.h>

int * FindVal(int a[], int len, int val);

int main(){

    int arr[10];
    int el;

    for(int i=0; i<10; i++){

        scanf("%d", &arr[i]);
    }

    scanf("%d", &el);

    if(FindVal(arr, 10, el) == NULL){

        printf("non trovato\n");
    }
    else{

        printf("trovato\n");
    }

    return 0;
}

int * FindVal(int a[], int len, int val){

    int i=0;

    while(i<10){

        if(val == a[i]){

            return &a[i];
        }

        i++;
    }

    return NULL;
}