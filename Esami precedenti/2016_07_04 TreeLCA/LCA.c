#include <stdio.h>
#include <stdlib.h>

typedef struct _node {

    int info;
    struct _node * left;
    struct _node * right;
} node;

node *  insertTree(node *t, int v);
int LCA(node *t, int x, int y);

int main(){

    int n, el;
    int a, b;
    scanf("%d", &n);

    node * tree = NULL;
    for(int i=0; i<n; i++){

        scanf("%d", &el);
        tree = insertTree(tree, el);
    }

    scanf("%d%d", &a, &b);
    printf("%d\n", LCA(tree, a, b));
}

int LCA(node *t, int x, int y){

    if(t->info > x && t->info > y){           // se la radice e' piu' grande sia di x che di y

        return LCA(t->left, x, y);                      // continua la ricerca a sinistra
    }
    else if(t->info < x && t->info < y){      // se la radice e' piu' piccola si di x che di y

        return LCA(t->right, x, y);                     // continua la ricerca a destra
    }
    else{                                    // se sono separati, o uno e' figlio dell'altro

        return t->info;                                 // ritorna la radice
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
