// Eliminazione nodo da un albero binario di ricerca

#include <stdio.h>
#include <stdlib.h>
#define COUNT 5

typedef struct _node{

    int info;
    struct _node *left;
    struct _node *right;
} node;

node * insertTree(node *t, int v);
node * deleteNode(node *t, int v);
node * findMinNode(node *t);
void printTree(node *t, int space);

int main(){

    int n, el;
    node * tree = NULL;

    scanf("%d", &n);
    for(int i=0; i<n; i++){

        scanf("%d", &el);
        tree = insertTree(tree, el);
    }

    printTree(tree, 0);
    puts("---------------------------------");

    while (1){
        
        scanf("%d", &el);

        if(el < 0){

            break;
        }

        tree = deleteNode(tree, el);

        printTree(tree, 0);
        puts("---------------------------------");
    }
    
}

node * deleteNode(node *t, int v){

    if(t == NULL){

        return t;
    }

    if(t->info < v){

        t->right = deleteNode(t->right, v);
    }
    else if(t->info > v){

        t->left = deleteNode(t->left, v);
    }
    else{

        // se il nodo ha un solo figlio
        if(t->left == NULL){

            node * temp = t->right;
            free(t);
            return temp;
        }
        else if(t->right == NULL){

            node * temp = t->left;
            free(t);
            return temp;
        }
        // se il nodo ha 2 figli
        else{

            // al posto del nodo corrente, ci va il minore del sottoalbero destro
            node * temp = findMinNode(t->right);    // trovalo
            
            t->info = temp->info;                   // scambia i valori
            t->right = deleteNode(t->right, t->info);
        }
    }

    return t;
}

node * findMinNode(node *t){

    node * corr = t;

    while (corr->right!=NULL){
        
        corr = corr->right;
    }

    return corr;
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
