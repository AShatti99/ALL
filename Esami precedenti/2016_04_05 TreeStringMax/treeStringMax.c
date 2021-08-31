#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{

    char s[101];
    int info;
    struct _node * left;
    struct _node * right;
} node;

node * insertLexiTree(node *t, char * s, int v);
void printTree(node *t, int space);
node * findString(node *t, char *s);
int findMax(node *t);

int main(int argc, char const *argv[]){

    int n, el;
    char str[101];
    node * tree = NULL;

    scanf("%d", &n);
    for(int i=0; i<n; i++){

        scanf("%s%d", str, &el);
        tree = insertLexiTree(tree, str, el);
    }  

    // printTree(tree, 0);

    scanf("%s", str);
    tree = findString(tree, str);           // trovo il nodo da cui iniziare la ricerca del massimo
    printf("%d\n", findMax(tree));

    return 0;
}

node * findString(node *t, char *s){

    if(t==NULL){

        return NULL;
    }

    int c = strcmp(t->s, s);

    if(!c){

        return t;
    }
    else if(c < 0){

        return findString(t->right, s);
    }
    else{

        return findString(t->left, s);
    }
}

int findMax(node *t){

    if(t==NULL){

        return -1;
    }

    int max = t->info;
    int sx = findMax(t->left);
    int dx = findMax(t->right);

    if(sx > max){

        max = sx;
    }
    
    if(dx > max){

        max = dx;
    }

    return max;
}

node * insertLexiTree(node *t, char * s, int v){

    if(t == NULL){

        node * nuovo = malloc(sizeof(node));
        strcpy(nuovo->s, s);
        nuovo->info=v;
        nuovo->left=NULL;
        nuovo->right=NULL;

        return nuovo;
    }

    if(strcmp(t->s, s)<0){

        t->right = insertLexiTree(t->right, s, v);
    }
    else{

        t->left = insertLexiTree(t->left, s, v);
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
    printf("%s\n", t->s);

    printTree(t->left, space);
}
