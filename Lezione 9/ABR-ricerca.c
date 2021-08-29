/* Scrivere un programma che legga da tastiera una sequenza di N interi distinti e li inserisca 
in un albero binario di ricerca (senza ribilanciamento). Il programma entra poi in un ciclo infinito 
nel quale legge un intero i da tastiera e lo cerca nell’albero. Il ciclo termina solo se l’intero i 
inserito e' strettamente minore di 0. Se i si trova nell’albero stampa la profondita' alla quale 
l’elemento si trova (contando da 0), altrimenti stampa NO. L’input `e costituito da:
    • una riga contenente la lunghezza N della sequenza;
    • N righe contenenti gli interi che compongono la sequenza;
    • una sequenza di dimensione non nota di richieste espresse con interi.
Se i e' minore di 0, il programma termina (non ci sono piu' richieste); altrimenti i rappresenta 
il valore da cercare. L’output contiene una riga per ogni richiesta di ricerca, contenente la 
profondita' a cui l’elemento si trova (contando da 0) se esso e' presente nell’albero, NO altrimenti. */

#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    
    int info;
    struct _node * left;
    struct _node * right;
} node;

node *  insertTree(node *t, int v);
int searchTree(node *t, int v);
void printTree(node *t, int space);

int main(int argc, char const *argv[]) {
    
    int n, el, res;
    node * tree = NULL;

    scanf("%d", &n);
    for(int i=0; i<n; i++){

        scanf("%d", &el);
        tree = insertTree(tree, el);
    }

    while (1){

        scanf("%d", &el);

        if(el < 0){

            break;
        }

        res = searchTree(tree, el);
        if(res != -1){

            printf("%d\n", res);
        }
        else{

            printf("NO\n");
        }
    }
    
//    printTree(tree, 0);

    return 0;
}

int searchTree(node *t, int v){

    if(t==NULL){

        return -1;
    }

    if(t->info == v){

        return 0;
    }

    int found = -1;
    if(t->info < v){

        found = searchTree(t->right, v);
    }
    else{

        found = searchTree(t->left, v);
    }

    if(found >= 0){

        return 1 + found;
    }
    else{

        return -1;
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