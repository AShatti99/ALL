#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct _node{
    
    int info;
    struct _node * left;
    struct _node * right;
} node;

node *  insertTree(node *t, int v);
int findSecondMax(node * t);
void printTree(node *t, int space);

int main(int argc, char const *argv[]) {
    
    int n, el;
    node * tree = NULL;

    scanf("%d", &n);
    for(int i=0; i<n; i++){

        scanf("%d", &el);
        tree = insertTree(tree, el);
    }

    printf("%d\n", findSecondMax(tree));

    return 0;
}

int findSecondMax(node * t){

    node * prev = NULL;               // nodo precedente
    node * corr = t;                  // nodo corrente

    while (corr->right!=NULL){        // vai sempre a destra finche' puoi ovvero finche' non trovi il max
        
        prev = corr;
        corr = corr->right;
    }

    if(corr->left==NULL && corr->right==NULL){  // se corr e' una foglia 

        return prev->info;                      // allora il secondo max e' precedente 
    }
    else{                             // altrimenti:

        corr = corr->left;            // vai a sinistra (a destra non puoi andare, senno' ci saresti gia')

        while (corr->right!=NULL){    // continui di nuovo fino a destra finche' puoi
            
            corr= corr->right;
        }

        return corr->info;            // ritorni corr
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

#define COUNT 5
void printTree(node *t, int space){

   if(t==NULL){

       return;
    }
    space += COUNT;

    printTree(t->right, space);

    printf("\n");
    for(int i= COUNT; i<space; i++){

        printf(" ");
    }
    printf("%d\n", t->info);

    printTree(t->left, space);
}

