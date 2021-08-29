#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _exam{

    char name[100];                 // sigla esame
    int cfu;                        // numero crediti
    int g;                          // grado di difficolta'
} exam;

typedef struct _node{

    exam key;
    struct _node * next;
} node;

int compareExam(void const *a, void const *b);
void insLexi(node **l, char *s);
void printList(node *l);

int main(int argc, char const *argv[]){
    
    int k, n, i, sum=0;
    scanf("%d", &k);
    scanf("%d", &n);

    exam * arr = malloc(n*sizeof(exam));                                // array di esami
    node * list = NULL;                                                 // lista come risultato
    
    for(i=0; i<n; i++){

        scanf("%s%d%d", arr[i].name, &arr[i].cfu, &arr[i].g);
    }

    qsort(arr, n, sizeof(exam), compareExam);                           // ordina l'array

    i=0;
    while (sum!=k){                                                     // zaino
        
        if(sum + arr[i].cfu <= k){

            insLexi(&list, arr[i].name);
            sum = sum + arr[i].cfu;
        }
        
        i++;
    }
    
    printList(list);
    return 0;
}

void insLexi(node **l, char *s){

    node * nuovo = malloc(sizeof(node));
    strcpy(nuovo->key.name, s);

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

int compareExam(void const *a, void const *b){

    exam x = *(exam *)a;
    exam y = *(exam *)b;

    if(x.cfu == y.cfu){

        if(x.g == y.g){

            return strcmp(x.name, y.name);
        }
        return x.g - y.g;
    }
    return y.cfu - x.cfu;
}

void printList(node *l){

    if(l!=NULL){

        printf("%s\n", l->key.name);
        printList(l->next);
    }
}
