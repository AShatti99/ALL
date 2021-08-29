#include <stdio.h>
#include <stdlib.h>

typedef struct _node {

    int info;
    int Nsx;
    int Ndx;
    struct _node * left;
    struct _node * right;
} node;

node *  insertTree(node *t, int v);
void visitaSxDx(node *t);
void visitaSimmetrica(node * t);

int main(int argc, char const *argv[]){
    
    int n, el;

    node * tree = NULL;
    scanf("%d", &n);
    for(int i=0; i<n; i++){

        scanf("%d", &el);
        tree = insertTree(tree, el);
    }

    visitaSxDx(tree);
    visitaSimmetrica(tree);

    return 0;
}

void visitaSxDx(node *t){

    if(t->left==NULL && t->right==NULL){        // quando arriva alla foglia, setta sx e dx

        t->Ndx = 0;
        t->Nsx = 0;
        return;
    }

    if(t->left!=NULL){                          // se non e' una foglia, continua la visita

        visitaSxDx(t->left);                    
        t->Nsx = t->left->Nsx + 1;              // e aumenta + 1 il numero dei nodi a sinistra
    }

    if(t->right!=NULL){                         // se non e' una foglia, continua la visita

        visitaSxDx(t->right);   
        t->Ndx = t->right->Ndx + 1;             // e aumenta + 1 il numero dei nodi a sinistra
    }
}

void visitaSimmetrica(node * t){

    if(t!=NULL){

        visitaSimmetrica(t->left);

        if(t->Nsx > t->Ndx){

            printf("%d\n", t->info);
        }

        visitaSimmetrica(t->right);
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
