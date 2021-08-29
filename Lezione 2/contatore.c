/* Scrivere una programma che data una sequenza di interi tenga traccia delle frequenze degli interi  
compresi tra 0 e 9 (estremi inclusi). La sequenza termina quando viene letto il valore -1. 
Il programma deve stampare in output le frequenze dei valori compresi tra 0 e 9. 
Le frequenze saranno mantenute in un array di contatori di lunghezza 10 che sara' inizializzato a 0.
Implementare queste due funzioni:
• void reset(int array[], int len): inizializza l’array dei contatori a 0;
• void add(int array[], int len, int val): incrementa il contatore array[val] se val e' tra 0 e len-1.
L’input e' formato da una sequenza di interi terminata dall’intero -1. 
L’output e' costituito dalle frequenze (una per riga) degli interi tra 0 e 10 nella sequenza letta in input */

#include <stdio.h>

void reset(int array[], int len);
void add(int array[], int len, int val);

int main(){

    int a[10];
    int el;

    reset(a, 10);

    scanf("%d", &el);

    while (el!= -1){
        
        add(a, 10, el);
        scanf("%d", &el);
    }

    for(int i=0; i<10; i++){

        printf("%d\n", a[i]);
    }
    
    return 0;
}

void reset(int array[], int len){

    for(int i=0; i<10; i++){

        array[i] = 0;
    }
}

void add(int array[], int len, int val){

    array[val]++;
}