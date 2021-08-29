/* Scrivere un programma che legga da tastiera una sequenza di n interi distinti e li inserisca 
in una lista monodirezionale. Successivamente il programma deve calcolare la media aritmetica 
dei valori della lista ed eliminare tutti gli elementi il cui valore e' inferiore o uguale alla media, 
troncata all’intero inferiore. Ad esempio: avg(1, 2, 4) = 7/3 = 2
IMPORTANTE: Si abbia cura di liberare la memoria dopo ogni cancellazione.
L’input `e costituito da:
    • una riga contenente la lunghezza n della sequenza;
    • n righe contenenti gli interi che compongono la sequenza
L’output `e costituito da:
    • una riga contenente la media troncata all’intero inferiore;
    • una riga contenente tutti gli interi letti da input (separati da uno spazio);
    • una riga contenente tutti gli interi nella lista dopo aver filtrato (separati da uno spazio) */

#include <stdio.h>
#include <stdlib.h>

typedef struct _list {

    int info;
    struct _list * next;
} list;

list * createList(int v);
list * insTail(list *l, int v);
void printList(list *l);
void deleteList(list ** l, int m);

int main(int argc, char * argv[]){

    int n, el, i, del;

    scanf("%d%d", &n, &el);
    del = el;

    list * head = createList(el);
    list * next = head;

    for(i=1; i<n; i++){

        scanf("%d", &el);
        next = insTail(next, el);
        del += el;
    }

    del = del/i;
    printf("%d\n", del);
    printList(head);

    deleteList(&head, del);
    printList(head);

    return 0;
}

void deleteList(list ** l, int m){               // elimina ricorsivamente

    list * temp = *l;

    if(*l!=NULL){

        if((*l)->info <= m){

            *l = (*l)->next;
            free(temp);

            deleteList(&(*l), m);
        }
        else{

            deleteList(&(*l)->next, m);
        }
    }
    
}

void printList(list *l){

    list * temp = l;

    while (temp!=NULL){
        
        printf("%d ", temp->info);
        temp=temp->next;
    }

    puts("");
}


list * createList(int v){

    list * nuovo = malloc(sizeof(list));
    nuovo->info=v;
    nuovo->next=NULL;

    return nuovo;
}

list * insTail(list *l, int v){

    l->next=malloc(sizeof(list));
    l->next->info=v;
    l->next->next=NULL;

    return l->next;
}
