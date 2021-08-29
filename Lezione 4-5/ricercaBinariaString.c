/* Scrivere una funzione che, data una stringa, un array di stringhe distinte e ordinate 
lessicograficamente e la sua lunghezza, cerchi la stringa nell’array utilizzando la ricerca binaria. 
La funzione restituisce la posizione della stringa se essa e' presente, il valore -1 altrimenti.
Scrivere un programma che implementi il seguente comportamento. L’input e' formato da una prima riga 
contenente la lunghezza N dell’array. Le successive N righe contengono le stringhe dell’array ordinate 
lessicograficamente. Segue una sequenza di dimensione non nota di richieste espresse con coppie. 
La prima riga di ogni coppia e' un valore che puo' essere “0” o “1”. Se il valore e' 0, il programma 
termina (non ci sono piu' richieste). Se il valore e' “1”, sulla riga successiva si trova una stringa 
da cercare. Per ciascuna richiesta ci si aspetta in output l’esito della ricerca: 
la posizione della stringa nell’array se essa e' presente, -1 altrimenti. L’input `e costituito da:
    • una riga contenente la lunghezza N dell’array;
    • N righe contenenti le stringhe dell’array ordinate lessicograficamente;
    • una sequenza di dimensione non nota di richieste espresse con coppie.La prima riga di ogni coppia 
      `e un valore che pu`o essere “0” o “1”.  Se il valore e' 0, il programma termina (non ci sono piu 
      richieste).  Se il valore e' “1”, sulla riga successiva si trova una stringa da cercare. 
      L’output contiene una riga per ogni stringa richiesta in input, contenente la posizione della stringa 
      nell’array se essa e' presente, -1 altrimenti */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct el {

    int info;
    struct el * next;
} lista;

int ricercaBinaria(char **a, int sx, int dx, char * str);
void insTail(lista ** list, int v);
void printList(lista * list);

int main(){

    int n, i, end;                                      // lunghezza array, indice, fine richieste
    char s[MAX];                                        // stringa da cercare
    lista * l=NULL;                                     // lista di output

    scanf("%d", &n);

    char **arr= (char **) malloc (n*sizeof(char *));    // array di stringhe

    for(i=0; i<n; i++){

        arr[i]= (char *) malloc (MAX*sizeof(char));     
        scanf("%s", arr[i]);
    }

    scanf("%d", &end);

    while(end==1){

        scanf("%s", s);

        insTail(&l, ricercaBinaria(arr, 0, n-1, s));    // inserisce in coda l'output di ricerca binaria

        scanf("%d", &end);
    }

    printList(l);                                       // stampa la lista

    for(i=0; i<n; i++){

        free(arr[i]);
    }

    free(arr);

    return 0;
}

int ricercaBinaria(char **a, int sx, int dx, char * str){

    if(sx <= dx){

        int cen = (sx + dx) / 2;
        
        if(strcmp(str, a[cen])==0){

            return cen;           
        }
        
        if(strcmp(str, a[cen])<0){

            return ricercaBinaria(a, sx, cen-1, str);
        }
        else{

            return ricercaBinaria(a, cen+1, dx, str);
        }
    }

    return -1;
}

void insTail(lista ** list, int v){

    lista * nuovo = malloc(sizeof(lista));

    nuovo->info=v;
    nuovo->next=NULL;

    if(*list==NULL){

        *list = nuovo;
    }
    else{

        lista * ultimo = *list;

        while (ultimo->next!=NULL){
            
            ultimo=ultimo->next;
        }

        ultimo->next=nuovo;
    }
}

void printList(lista * list){

    if(list!=NULL){

        printf("%d\n", list->info);
        printList(list->next);
    }
}