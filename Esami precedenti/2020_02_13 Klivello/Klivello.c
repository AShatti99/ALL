#include <stdio.h>
#include <stdlib.h>

typedef struct _node {

    int info;
    int level;                                  // ogni nodo ha anche l'altezza
    struct _node * left;
    struct _node * right;
} node;

node * insertTree(node *t, int v, int lv);
void printKlevel(node *t, int k);
void printTree(node *t, int space);

int main(int argc, char const *argv[]){
    
    int n, el, lev;
    node * tree = NULL;

    scanf("%d", &n);
    for(int i=0; i<n; i++){

        scanf("%d", &el);
        tree = insertTree(tree, el, 0);
    }

    //printTree(tree, 0);

    scanf("%d", &lev);
    printKlevel(tree, lev);

    return 0;
}

void printKlevel(node *t, int k){

    if(t==NULL){

        return;
    }

    if(t->level ==k){

        printf("%d\n", t->info);
    }

    printKlevel(t->left, k);                    
    printKlevel(t->right, k);
}


node * insertTree(node *t, int v, int lv){

    if(t == NULL){

        node * nuovo = malloc(sizeof(node));
        nuovo->info=v;
        nuovo->level = lv;
        nuovo->left=NULL;
        nuovo->right=NULL;

        return nuovo;
    }

    if(t->info < v){

        t->right = insertTree(t->right, v, lv+1);
    }
    else{

        t->left = insertTree(t->left, v, lv+1);
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
    printf("%d-%d\n", t->info, t->level);

    printTree(t->left, space);
}
