/* Scrivere un programma che legga da tastiera una sequenza di n interi distinti e li inserisca 
in una tabella hash di dimensione 2n posizioni utilizzando liste monodirezionali per risolvere eventuali 
conflitti. Utilizzare la funzione hash h(x) = ((ax + b) % p) % 2n dove p e' il numero primo 999149 e 
a e b sono interi positivi minori di 10.000 scelti casualmente. Una volta inseriti tutti gli interi, 
il programma deve stampare la lunghezza massima delle liste e il numero totale di conflitti.
Prima di scrivere il programma chiedersi perch ́e la tabella ha dimensione
2n e non n.
L’input e' cosi formato:
    • la prima riga contiene la lunghezza n della sequenza;
    • la seconda riga contiene a;
    • la terza riga contiene b;
    • le successive n righe contengono gli interi che compongono la sequenza.
L’output e' cosi' formato:
    • la prima riga contiene la dimensione della lista di lunghezza massima;
    • la seconda riga contiene il numero totale di conflitti
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
int hash(int a, int b, int v, int size);
void printHashTable(list * T, int size);

int main(int argc, char const *argv[]){

    int n, a, b;
    int el, h, i;
    int max=0, conflict=0;

    scanf("%d%d%d", &n, &a, &b);

    list * T = (list *) malloc(2*n*sizeof(list));    // tabella hash

    for(i=0; i<2*n; i++){                            // inizializza tabella hash

        T[i].head=NULL;
        T[i].last=NULL;
        T[i].dim=0;
    }

    for(i=0; i<n; i++){

        scanf("%d", &el);
        h = hash(a, b, el, 2*n);                     // calcola funzione hash
        insTail(&T[h], el, &max, &conflict);         // inserisci controllando la dimensione
    }                                                // della lista piu' lunga, e il numero di conflitti

    printHashTable(T, 2*n);

    printf("%d\n%d\n", max, conflict);

    return 0;
}

int hash(int a, int b, int v, int size){

    return ((a * v + b) % 999149) % size;
}

void insTail(list * l, int v, int *dimMax, int *Nconflicts){

    node * nuovo = malloc(sizeof(node));
    nuovo->info=v;
    nuovo->next=NULL;

    if(l->dim==0){                      // per ricordarsi i puntatori alla testa (nel caso sia vuota)

        l->head=nuovo;
    }
    else{                                 // e coda della lista     

        l->last->next=nuovo;
        *Nconflicts = *Nconflicts +1;     // se e' in coda significa che ci sta un conflitto  
    }

    l->dim++;                             // incrementi dimensione lista
    if(l->dim > *dimMax){                 // controlli se e' il max 

        *dimMax = l->dim;
    }

    l->last=nuovo;                          
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