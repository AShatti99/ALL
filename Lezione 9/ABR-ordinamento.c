/* Scrivere un programma che legga da tastiera una sequenza di Ninteri distinti e li inserisca 
in un albero binario di ricerca (senza ribilanciamento). Il programma deve quindi utilizzare 
un’opportuna visita dell’albero per stampare gli interi della sequenza in ordine non decrescente.
Nella prima riga dell’input si trova la lunghezza Ndella sequenza; nelle successive N righe si trovano 
gli interi che compongono la sequenza. L’output contiene la sequenza ordinata degli elementi 
inseriti nell’albero, uno per riga. */

#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    
    int info;
    struct _node * left;
    struct _node * right;
} node;

node * insertTree(node *t, int v);
void simmetrica(node * t);

int main(){

    int n, el, res;
    node * tree = NULL;

    scanf("%d", &n);
    for(int i=0; i<n; i++){

        scanf("%d", &el);
        tree = insertTree(tree, el);
    }

    simmetrica(tree);

    return 0;
}

void simmetrica(node * t){

    if(t!=NULL){

        simmetrica(t->left);
        printf("%d\n", t->info);
        simmetrica(t->right);
    }
}

node * insertTree(node *t, int v){

    if(t == NULL){

        node * nuovo = malloc(sizeof(node));
        nuovo->info=v;
        nuovo->left=NULL;
        nuovo->right=NULL;

        return nuovo;
    }

    if(t->info < v){

        t->right = insertTree(t->right, v);
    }
    else{

        t->left = insertTree(t->left, v);
    }

    return t;
}
