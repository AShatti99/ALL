#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{
    
    char s[101];
    struct _node * left;
    struct _node * right;
} node;

node * insertLexiTree(node *t, char * s);
void visit(node *t);
int findLexiMin(node * t);
int prefix(char * s, char * z);
void printTree(node *t, int space);
int main(int argc, char const *argv[]){ 

    int n;
    char str[100];
    scanf("%d", &n);
    node * tree = NULL;

    for(int i=0; i<n; i++){

        scanf("%s", str);
        tree = insertLexiTree(tree, str);
    }  
    
    // printTree(tree, 0);

    visit(tree);

    return 0;
}

void visit(node *t){                            // visita simmetrica

    if(t!=NULL){

        visit(t->left);

        if(findLexiMin(t)==1){                  

            printf("%s\n", t->s);
        }
        
        visit(t->right);
    }
}

int findLexiMin(node * t){

    char str[101];                  // str valore temporaneo
    node * temp = t;

    strcpy(str, t->s);

    while (temp->left!=NULL){       // cerchi l'ultimo elemento che sara' all'estremo sinistro
        
        temp= temp->left;
    }

    return prefix(temp->s, str);    // ritorna prefix
}

int prefix(char * s, char * z){

    int dim1= strlen(s);
    int dim2= strlen(z);

    if(dim1 <= dim2){                           // |u| <= |v|

        for(int i=0; i<dim1; i++){              // continua fino alla lunghezza di |u|

            if(s[i]==z[i]){

                i++;
            }
            else{

                return 0;                       // se un carattere e' diverso ritorna 0
            }
        }
        
        return 1;                               // se sei qui significa che e' un prefisso
    }

    return 0;
}


node * insertLexiTree(node *t, char * s){

    if(t == NULL){

        node * nuovo = malloc(sizeof(node));
        strcpy(nuovo->s, s);
        nuovo->left=NULL;
        nuovo->right=NULL;

        return nuovo;
    }

    if(strcmp(t->s, s)<0){

        t->right = insertLexiTree(t->right, s);
    }
    else{

        t->left = insertLexiTree(t->left, s);
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
