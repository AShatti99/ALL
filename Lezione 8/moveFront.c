/* Scrivere un programma che legga da tastiera una sequenza di n interi distinti e li inserisca in una lista 
monodirezionale (nell’ordine dato). Il programma entra poi in un ciclo nel quale legge un intero i da tastiera 
e lo cerca nella lista. Se i si trova nella lista stampa la sua posizione (contando da 0) e porta l’elemento 
in testa alla lista (MTF), altrimenti stampa -1 e termina. L’input e' formattato come segue:
• la prima riga contiene la lunghezza n (non limitata) della sequenza;
• le successive n righe contengono gli interi che compongono la sequenza, uno per riga;
• segue una sequenza di interi da cercare nella lista (uno per riga), di lunghezza non nota 
a priori, terminata da un numero non presente nella lista
L’output contiene:
• le posizioni degli elementi trovati nella lista (si assume che il primo elemento sia in posizione 0), 
  una posizione per riga;
• -1 se e' stato dato in input un numero che non `e nella lista, e in tal
caso si termina.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _list {

    int info;
    struct _list * next;
} list;

list * createList(int v);
list * insTail(list * l, int v);
int moveFront(list ** l, int v);


int main(int argc, char const *argv[]){
    
    int n, el, i;
    int res;
    scanf("%d%d", &n, &el);

    list * head = createList(el);
    list * last = head;

    for(i = 1; i<n; i++){

        scanf("%d", &el);
        last = insTail(last, el);
    }

    while (1){
        
        scanf("%d", &el);
        res = moveFront(&head, el);
        printf("%d\n", res);
        
        if(res== -1){

            break;
        }
    }
    
    return 0;
}

int moveFront(list ** l, int v){

    if((*l)->info==v){                           // se si trova in prima posizione

        return 0;
    }
    else{                                       

        list * prec = *l;
        list * corr = prec->next;

        int j=1;

        while (corr->next!=NULL){               // se non e' in prima e ultima posizione
        
            if(corr->info==v){
                
                prec->next=corr->next;
                corr->next=*l;
                
                *l = corr;
                return j;
            }

            prec = corr;
            corr = corr->next;
            j++;
        }

        if(corr->info==v){                      // se e' in ultima posizione

            corr->next=*l;
            prec->next=NULL;

            *l=corr;
            return j;
        }
        else{                                   // se non e' presente

            return -1;
        }
    }
}


list * createList(int v){

    list * nuovo = (list *)malloc(sizeof(list));
    nuovo->info=v;
    nuovo->next=NULL;

    return nuovo;
}

list * insTail(list *l, int v){

    l->next=(list *)malloc(sizeof(list));
    l->next->info=v;
    l->next->next=NULL;

    return l->next;
}


