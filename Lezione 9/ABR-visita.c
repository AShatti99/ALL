/* Scrivere un programma che legga da tastiera una sequenza di N interi distinti e li inserisca 
in un albero binario di ricerca (senza ribilanciamento). Il programma deve visitare opportunamente 
l’albero e restituire la sua altezza. Nella prima riga dell’input si trova la lunghezza N 
della sequenza; nelle successive N righe si trovano gli interi che compongono la sequenza.
L’output contiene unicamente l’altezza dell’albero. */

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {

    int info;
    int height;
    struct _node * left;
    struct _node * right;
} node;

node *  insertTree(node *t, int v);
int heightTree(node * t);

int main(int argc, char const *argv[]){
    
    int n, el, res;
    node * tree = NULL;

    scanf("%d", &n);
    for(int i=0; i<n; i++){

        scanf("%d", &el);
        tree = insertTree(tree, el);
    }

    printf("%d\n", tree->height);               // altezza radice quindi altezza albero

    return 0;
}

node * insertTree(node *t, int v){

    if(t == NULL){

        node * nuovo = malloc(sizeof(node));
        nuovo->info=v;
        nuovo->height=1;
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

    int hLeft= t->left == NULL ? -1 : t->left->height;    
    int hRight= t->right == NULL ? -1 : t->right->height; 

    if(hLeft > hRight){                                               

        t->height=hLeft +1;
    }
    else{

        t->height=hRight +1;
    }

    return t;
}

