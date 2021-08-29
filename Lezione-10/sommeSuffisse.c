/* Scrivere un programma che legga da tastiera una sequenza di ninteri maggiori di 0 e li inserisca 
in una lista nell’ordine di immissione. La lista deve essere monodirezionale. Successivamente il 
programma deve sostituire il valore di ciascun elemento con la somma dei valori degli elementi che lo 
seguono nella lista. Suggerimento: si utilizzi la ricorsione per ottenere la somma ad ogni passo.
L’input e' costituito da:
    • una riga contenente la lunghezza ndella sequenza;
    • n righe contenenti gli interi che compongono la sequenza 
L’output `e costituito da:
    • una riga contenente tutti gli interi letti da input (separati da uno spazio);
    • una riga contenente tutti gli interi nella lista dopo aver calcolato le somme suffisse 
(separati da uno spazio).*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _list {

    int info;
    struct _list * next;
} list;

list * createList(int v);
list * insTail(list *l, int v);
void * sommeSuffisse(list *l, int s);
void printList(list *l);

int main(int argc, char * argv[]){

    int n, el, i, sum;

    scanf("%d%d", &n, &el);

    list * head = createList(el);
    list * next = head;
    sum = el;

    for(i=1; i<n; i++){

        scanf("%d", &el);
        next = insTail(next, el);
        sum+=el;
    }

    printList(head);
    sommeSuffisse(head, sum);
    printList(head);

    return 0;
}

void * sommeSuffisse(list *l, int s){

    if(l!=NULL){

        s=s-l->info;
        l->info=s;
        sommeSuffisse(l->next, s);
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