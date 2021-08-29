/* Scrivere un programma che legga da tastiera una sequenza di n interi NON distinti e li inserisca 
senza duplicati in una tabella hash di dimensione 2n posizioni utilizzando liste monodirezionali 
per risolvere eventuali conflitti. Utilizzare la funzione hash h(x) = ((ax + b) % p) % 2n dove p e'
il numero primo 999149 e a e b sono interi positivi minori di 10.000 scelti casualmente.
Una volta inseriti tutti gli interi, il programma deve stampare il numero totale di conflitti, 
la lunghezza massima delle liste e il numero di elementi distinti.
L’input e' cosi' formato:
    • la prima riga contiene la lunghezza n della sequenza;
    • la seconda riga contiene a;
    • la terza riga contiene b;
    • le successive n righe contengono gli interi che compongono la sequenza.
L’output `e cos`ı formato:
    • la prima riga contiene il numero totale di conflitti;
    • la seconda riga contiene la dimensione della lista di lunghezza massima;
    • la terza riga contiene il numero totale di elementi distinti
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {

    int info;
    struct _node * next;
} node;

typedef struct _list {

    struct _node * head;        // puntatore alla testa della lista
    struct _node * last;        // puntatore alla coda della lista
    int dim;                    // dimensione lista
} list;


void insTail(list * l, int v, int *dimMax, int *Nconflicts);
int searchList(list *l, int v);
int hash(int a, int b, int v, int size);
void printHashTable(list * T, int size);

int main(int argc, char const *argv[]){

    int n, a, b;
    int el, h, i;
    int max=0, conflicts=0, numbers=0;

    scanf("%d%d%d", &n, &a, &b);

    list * T = (list *) malloc(2*n*sizeof(list));    // tabella hash

    for(i=0; i<2*n; i++){                            // inizializza tabella hash

        T[i].head=NULL;
        T[i].last=NULL;
        T[i].dim=0;
    }

    for(i=0; i<n; i++){                                     

        scanf("%d", &el);
        h = hash(a, b, el, 2*n);                   // calcola funzione hash

        if(!searchList(&T[h], el)){                // cerca nella lista: se non e' presente, inserisci

            insTail(&T[h], el, &max, &conflicts);
            numbers++;
        }     
    }                                                         

    // printHashTable(T, 2*n);

    printf("%d\n%d\n%d\n", conflicts, max, numbers);

    return 0;
}

int hash(int a, int b, int v, int size){

    return ((a * v + b) % 999149) % size;
}

void insTail(list * l, int v, int *dimMax, int *Nconflicts){

    node * nuovo = malloc(sizeof(node));
    nuovo->info=v;
    nuovo->next=NULL;

    if(l->dim == 0){                       // per ricordarsi i puntatori alla testa (nel caso sia vuota)

        l->head=nuovo;
    }
    else{                                  // e coda della lista     

        l->last->next=nuovo;
        *Nconflicts = *Nconflicts +1;      // e' in coda quindi significa che ci sta un conflitto  
    }

    l->dim++;                              // incrementi dimensione lista
    if(l->dim > *dimMax){                  // controlli se e' il max 

        *dimMax = l->dim;
    }

    l->last=nuovo;                          
}

int searchList(list *l, int v){

    node * corr = l->head;

    while (corr!=NULL) {
        
        if(corr->info==v){

            return 1;
        }

        corr=corr->next;
    }
    
    return 0;
}

void printHashTable(list * T, int size){

    for(int i=0; i<size; i++){

        printf("%d -> ", i);
        while (T[i].head!=NULL){
            
            printf("%d ", T[i].head->info);
            T[i].head=T[i].head->next;
        }
        printf("NULL\n");
    }
}