#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _item {

    char name[101];
    char tel[101];
} item;

typedef struct _node {

    item key;
    struct _node * next;
} node;

int hash(char * s, int N);
void insLexi(node **l, char *s, char *t);
void printList(node *l);

int main(){

    int n, i, h, k;
    char str[100], num[100];
    scanf("%d", &n);

    node ** T = (node **) malloc (2*n*(sizeof(node *)));                // tabella hash

    for(i=0; i<2*n; i++){                                               // inizializza tabella

        T[i] = NULL;
    }

    for(i=0; i<n; i++){                                                

        scanf("%s%s", str, num);
        h = hash(str, 2*n);
        insLexi(&T[h], str, num);                                   // inserisci in ordine lessinografico
    }

    scanf("%d", &k);
    printList(T[k]);

    return 0;
}

void insLexi(node **l, char *s, char *t){

    node * nuovo = malloc(sizeof(node));
    strcpy(nuovo->key.name, s);
    strcpy(nuovo->key.tel, t);

    node * prec = NULL;
    node * corr = *l;

    // se corr e' diverso NULL (cioe' lista vuota) e il valore nuovo e' maggiore del valore corrente
    // vai avanti 
    while (corr!=NULL && strcmp(nuovo->key.name, corr->key.name)>0){        
        
        prec = corr;
        corr = corr->next;
    }

    
    if(prec == NULL){                   // se prec e' rimasto NULL, significa che la lista e' vuota

        nuovo->next = *l;
        *l = nuovo;
    }
    else{                               // altrimenti collega

        prec->next = nuovo;
        nuovo->next = corr;
    }
}

int hash(char * s, int N){

    int sum = 0, dim = strlen(s);

    for(int i=0; i<dim; i++){

        sum = sum + (unsigned int)s[i];
    }

    return sum % N;
}

void printList(node *l){

    if(l!=NULL){

        printf("%s %s\n", l->key.name, l->key.tel);
        printList(l->next);
    }
}
