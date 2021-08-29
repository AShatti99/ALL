/* Scrivere un programma che riceve in input due sequenze di N interi positivi, dalle quali 
devono essere costruiti due alberi binari di ricerca NON bilanciati (un albero per sequenza).
Al programma viene data una chiave intera K. Si pu`o assumere che l’intero K sia presente in entrambe 
le sequenze. Il programma deve verificare che le sequenze di chiavi incontrate nel cammino che dalla 
radice porta al nodo con chiave K nei due alberi coincidano. L’input e' formattato nel seguente modo:
    • La prima riga contiene gli interi Ne K, separati da uno spazio.
    • Seguono 2Nrighe contenenti ognuna un intero. I primi Ninteri appartengono alla prima sequenza, 
      mentre i successivi Ninteri appartengono alla seconda sequenza.
L’output e' costituito da una singola riga che contiene il risultato del programma: 1 se le due sequenze 
di chiavi coincidono, 0 altrimenti. */

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {

    int info;
    struct _node * left;
    struct _node * right;
} node;

node * insertTree(node * t, int v);
int confronta(node *t1, node *t2, int key);

int main(int argc, char const *argv[]){
    
    int n, k, el, i;

    scanf("%d%d", &n, &k);
    node * tree1 = NULL;
    node * tree2 = NULL;

    for(i=0; i<n; i++){

        scanf("%d", &el);
        tree1 = insertTree(tree1, el);
    }

    for(i=0; i<n; i++){

        scanf("%d", &el);
        tree2 = insertTree(tree2, el);
    }

    printf("%d\n", confronta(tree1, tree2, k));

    return 0;
}

int confronta(node *t1, node *t2, int key){

    if(t1->info == key && t2->info == key){

        return 1;
    }
    
    if(t1->info == t2->info && t1->info > key){

        confronta(t1->left, t2->left, key);
    }
    else if(t1->info == t2->info && t1->info < key){

        confronta(t1->right, t2->right, key);
    }
    else{

        return 0;
    }
}

node * insertTree(node * t, int v){

    if(t==NULL){

        node * nuovo = malloc(sizeof(node));
        nuovo->info=v;
        nuovo->left=NULL;
        nuovo->right=NULL;

        return nuovo;
    }

    if(v > t->info){

        t->right = insertTree(t->right, v);
    }
    else{

        t->left = insertTree(t->left, v);
    }

    return t;
}
