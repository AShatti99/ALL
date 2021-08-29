#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _item {

    char item[101];
    int value;
} item;

typedef struct _node {

    item key;
    struct _node * next;
} node;


int hash(char *s, int N);
void insHead(node **l, char *s, int v);
void printTable(node *l);
int updateTable(node **l, char *s, int v);
void copyTableToArray(node **T, item a[], int dim, int i, int j);
int compareItem(void const *a, void const *b);

int main(){

    int n, i, val, h;                                    // n oggetti da processare
    int len = 0;                                          // lunghezza array di supporto
    char ogg[100];
    scanf("%d", &n);

    node **T = (node **) malloc(2*n*sizeof(node *));     // tabella hash di array da 2*n posizioni

    for(i=0; i<2*n; i++){                                // setta la tabella a NULL

        T[i] = NULL;
    }

    for(i=0; i<n; i++){

        scanf("%s%d", ogg, &val);
        int h = hash(ogg, 2*n);                              // calcola la funzione hash

    
        if(!updateTable(&T[h], ogg, val)){    // controlla se e' gia presente o se e' da aggiornare

            insHead(&T[h], ogg, val);                   // inserisci in testa
            len++;                           // aumenta dimensione che sara' per l'array di supporto
        }
    }

    item * arr = (item *) malloc(len*sizeof(item));    // array di supporto
    copyTableToArray(T, arr, 2*n, 0, 0);               // copiaci gli elementi dell'hash table

    qsort(arr, len, sizeof(item), compareItem);        // ordinalo

    if(n != 0){

        for(i=0; i<15; i++){                               // stampa i primi 15 elementi

            printf("%s\n", arr[i].item);
        }
    }

    return 0;
}

void copyTableToArray(node **T, item a[], int dim, int i, int j){

    if(j < dim){

        while (T[j]!=NULL){
            
            a[i].value = T[j]->key.value;
            strcpy(a[i].item, T[j]->key.item);

            i++;
            T[j] = T[j]->next;
        } 

        copyTableToArray(T, a, dim, i, j+1);    // salva il punto in cui hai finito di copiare l'array
    }                                           // vai avanti con la prossima lista
}

int compareItem(void const *a, void const *b){

    item x = *(item *)a;
    item y = *(item *)b;

    if(x.value == y.value){

        return strcmp(x.item, y.item);
    }

    return y.value - x.value;
}

int updateTable(node **l, char *s, int v){

    if(*l!=NULL){

        if(!strcmp((*l)->key.item, s)){          // se sono uguali

            if(v > (*l)->key.value){                  // se il nuovo elemento ha un valore piu' alto

                (*l)->key.value = v;
            }
            
            return 1;                                 // altrimenti esci (e quindi non inserisci)
        }

        updateTable(&(*l)->next, s, v);
    }
    
    return 0;
}

void insHead(node **l, char *s, int v){

    node * nuovo = malloc(sizeof(node));
    strcpy(nuovo->key.item, s);
    nuovo->key.value = v;
    nuovo->next = *l;

    *l = nuovo;
}

int hash(char *s, int N){

    int sum = 0, dim = strlen(s);

    for(int i=0; i<dim; i++){

        sum = sum + (unsigned int)s[i];  
    }

    return sum % N;
}

void printTable(node *l){

    if(l!=NULL){

        printf("%d %s;", l->key.value, l->key.item);
        printTable(l->next);
    }
    else{

        puts("");
    }
}
