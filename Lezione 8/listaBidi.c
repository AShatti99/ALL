#include <stdio.h>
#include <stdlib.h>

typedef struct _list{

    int info;
    struct _list * prec;
    struct _list * succ;
} list;

list * createList(int v);
list * insTail(list *l, int v);
void printList(list *l);

int main(){

    int n, el;
    scanf("%d%d", &n, &el);

    list * head = createList(el);
    list * next = head;

    for(int i=1; i<n; i++){

        scanf("%d", &el);
        next = insTail(next, el);
    }

    printList(head);

    free(head);

    return 0;
}

list * createList(int v){

    list * head = malloc(sizeof(list));
    head->info=v;
    head->prec=NULL;
    head->succ=NULL;

    return  head;
}

list * insTail(list *l, int v){

    l->succ= malloc(sizeof(list));
    l->succ->info=v;
    l->prec->prec=l;
    l->succ->succ=NULL;

    return l->succ;
}

void printList(list *l){

    while (l!=NULL){

        printf("%d\n", l->info);
        l=l->prec;
    }
}
