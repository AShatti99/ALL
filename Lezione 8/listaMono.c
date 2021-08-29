#include <stdio.h>
#include <stdlib.h>

typedef struct _list {

    int info;
    struct _list * next;
} list;

list * createList(int v);
list * insTail(list * l, int v);
void printRev(list *l);

int main(){

    int n, el;
    scanf("%d", &n);
    scanf("%d", &el);

    list * head = createList(el);
    list * last = head;

    for(int i=1; i<n; i++){

        scanf("%d", &el);
        last = insTail(last, el);
    }

    printRev(head);

    free(head);

    return 0;
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

void printRev(list *l){

    if(l==NULL){

        return;
    }

    printRev(l->next);
    printf("%d\n", l->info);
}

