#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

typedef struct _node {

    int info;
    struct _node * left;
    struct _node * right;
} node;

typedef struct res{

    int maxPath;
    int minKey;
} res;

node *  insertTree(node *t, int v);
res sommaCammino(node * t);

int main(int argc, char const *argv[]) {
    
    int n, el, res;
    scanf("%d", &n);

    node * tree = NULL;
    for(int i=0; i<n; i++){

        scanf("%d", &el);
        tree = insertTree(tree, el);
    }

    if(!n){

        puts("0");
    }
    else{

        printf("%d\n", sommaCammino(tree).minKey);
    }

    return 0;
}

res sommaCammino(node * t){

    res sol, sumMax, sx, dx;

    if(t==NULL){                                // se t==NULL

        sol.maxPath=0;                          // percorso massimo e' zero
        sol.minKey=INT_MAX;                     // valore minimo e' infinito
        return sol;
    }

    if(t->left==NULL && t->right==NULL){        // se e' una foglia

        sol.maxPath=t->info;
        sol.minKey=t->info;
        return sol;
    }

    sx = sommaCammino(t->left);                 
    dx = sommaCammino(t->right);

    if(sx.maxPath > dx.maxPath){                // se cammino di sinistra > cammino di destra

        sumMax = sx;
    }
    else if(dx.maxPath > sx.maxPath){           // se cammino di destra > cammino di sinistra

        sumMax = dx;
    }
    else{                                       // se sono uguali, si controlla il valore minimo

        if(sx.minKey < sx.maxPath){

            sumMax = sx;
        }
        else{

            sumMax = dx;
        }
    }

    sumMax.maxPath = sumMax.maxPath + t->info;  // si addiziona il cammino

    if(t->info < sumMax.minKey){                // e si setta il valore minimo

        sumMax.minKey = t->info;
    }
    
    return sumMax;
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
