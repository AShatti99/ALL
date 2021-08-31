/* Il programma deve leggere una sequenza di N coppie (stringa - valore). Le stringhe sono distinte 
di lunghezza al piu' 100 caratteri. Deve essere costruito un albero binario di ricerca non bilanciato
nel quale inserire le coppie in base al valore. Il programma dato in input una stringa s, la deve
cercare nell'albero. Sia U il nodo con la stringa uguale alla stringa in input, il programma deve
restituire la stringa e il valore del figlio destro di U. Se U e' una foglia restituire solo -1*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{

    char s[101];
    int info;
    struct _node * left;
    struct _node * right;
} node;

node * insertTree(node *t, char * s, int v);
node * findNode(node *t, char * s);

int main(int argc, char const *argv[])
{
    int n, el;
    char str[101];
    node * tree = NULL;

    scanf("%d", &n);
    for(int i=0; i<n; i++){

        scanf("%s%d", str, &el);
        tree = insertTree(tree, str, el);
    }  

    scanf("%s", str);
    tree = findNode(tree, str);

    if(tree->right!=NULL){

        printf("%s %d\n", tree->right->s, tree->right->info);
    }
    else{

        puts("-1");
    }
    
    return 0;
}

node * findNode(node *t, char * s){

    if(t==NULL){

        return NULL;
    }

    if(!strcmp(t->s, s)){

        return t;
    }

    node * sx = findNode(t->left, s);
    if(sx!=NULL){

        return sx;
    }

    node * dx = findNode(t->right, s);
    if(dx!=NULL){

        return dx;
    }

    return NULL;
}

node * insertTree(node *t, char * s, int v){

    if(t == NULL){

        node * nuovo = malloc(sizeof(node));
        strcpy(nuovo->s, s);
        nuovo->info=v;
        nuovo->left=NULL;
        nuovo->right=NULL;

        return nuovo;
    }

    if(t->info < v){

        t->right = insertTree(t->right, s, v);
    }
    else{

        t->left = insertTree(t->left, s, v);
    }

    return t;
}

