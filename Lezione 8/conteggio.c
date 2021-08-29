/* Scrivere un programma che legga da tastiera una sequenza di n interi ordinati e li inserisca in 
una lista bidirezionale. Il programma entra poi in un ciclo nel quale legge un intero i da tastiera 
e lo cerca nella lista. Se i si trova nella lista, stampa la sua posizione (contando da 0), altrimenti 
stampa -1. Ogni elemento della lista mantiene anche un contatore che ricorda quante volte `e stata 
cercata la corrispondente chiave. Tutti i contatori sono inizialmente settati a 0. Dopo ogni ricerca 
si deve garantire che gli elementi della lista siano ordinati in ordine non-crescente di contatore. 
Se il contatore di un elemento viene incrementato e risulta uguale a quello dell’elemento precedente, 
i due elementi vanno lasciati nelle loro posizioni. 
NOTA: non si devono utilizzare algoritmi di ordinamento, ma osservare che inizialmente la lista e' 
ordinata e che dopo ogni ricerca solo un contatore viene incrementato. 
L’input `e formattato come segue:
• la prima riga contiene la lunghezza n (non limitata) della lista;
• le successive n righe contengono gli interi che compongono la lista, in ordine, uno per riga;
• segue una lista di interi da cercare nella lista (uno per riga), di lunghezza non nota a priori, 
  terminata da un numero non presente nella lista
L’output contiene:
• le posizioni degli elementi trovati nella lista (si assume che il primo elemento sia in posizione 0), 
  una posizione per riga; gli elementi devono essere mantenuti ordinati in ordine non-crescente di 
  contatore;
• -1 se `e stato dato in input un numero che non `e nella lista, e in tal caso si termina
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _list{

    int info;
    int c;
    struct _list * prec;
    struct _list * succ;
} list;

list * createList(int v);
list * insTail(list *l, int v);
int conteggio(list **l, int v);
void swap(int *x, int *y);
void printList(list *l);

int main(int argc, char const *argv[]){
    
    int n, el, res;
    scanf("%d%d", &n, &el);

    list * head = createList(el);
    list * next = head;

    for(int i=1; i<n; i++){

        scanf("%d", &el);
        next = insTail(next, el);
    }

    while (1){
        
        scanf("%d", &el);
        res = conteggio(&head, el);
        printf("position: %d\n", res);
        printList(head);
        
        if(res== -1){

            break;
        }
    }
    
    return 0;
}

int conteggio(list **l, int v){

    list * corr = *l;
    int pos=0;

    while(corr!=NULL){

        if(corr->info == v){

            corr->c++;

            if(pos!=0){

                while (corr->c > corr->prec->c ){
                
                    swap(&corr->info, &corr->prec->info);
                    swap(&corr->c, &corr->prec->c);

                    if(corr->prec->prec!=NULL){

                        corr=corr->prec;
                    }
                }
            }
        
            return pos;
        }

        pos++;
        corr=corr->succ;
    }

    return -1; 
}

list * createList(int v){

    list * nuovo = (list *)malloc(sizeof(list));
    nuovo->info=v;
    nuovo->c=0;
    nuovo->prec=NULL;
    nuovo->succ=NULL;

    return nuovo;
}

list * insTail(list *l, int v){
    
    l->succ=(list *)malloc(sizeof(list));
    l->succ->info=v;
    l->succ->c=0;
    l->succ->prec=l;
    l->succ->succ=NULL;

    return l->succ;
}

void swap(int *x, int *y){

    int temp =*x;
    *x = *y;
    *y = temp;
}

void printList(list *l){

    printf("List:\n");

    while (l!=NULL){
        
        printf("%d:%d ->", l->info, l->c);
        l=l->succ;
    }

    puts("");
}
