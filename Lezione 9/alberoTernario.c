/* Scrivere un programma che riceva in input una sequenza di Ninteri positivi e costruisca un albero 
ternario di ricerca non bilanciato. L’ordine di inserimento dei valori nell’albero deve coincidere 
con quello della sequenza. Ogni nodo in un albero ternario di ricerca pu`o avere fino a tre figli:
figlio sinistro, figlio centrale e figlio destro. L’inserimento di un nuovo valore avviene partendo 
dalla radice dell’albero e utilizzando la seguente regola. Il valore da inserire viene confrontato 
con la chiave del nodo corrente. Ci sono tre possibili casi in base al risultato del confronto:
    1. se il valore `e minore della chiave del nodo corrente, esso viene inserito ricorsivamente 
    nel sottoalbero radicato nel figlio sinistro;
    2. se il valore `e divisibile per la chiave del nodo corrente, esso viene inserito ricorsivamente 
    nel sottoalbero radicato nel figlio centrale;
    3. in ogni altro caso il valore viene inserito ricorsivamente nel sottoalbero radicato nel figlio 
    destro.
Il programma deve stampare il numero di nodi dell’albero che hanno tre figli. La prima riga contiene 
la lunghezza Ndella sequenza. Le N righe successive contengono ciascuna un elemento da inserire 
nell’albero. L’output `e costituito da una singola riga che contiene il numero di nodi dell’albero che 
hanno tre figli */

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {

    int info;
    int height;
    struct _node * sx;
    struct _node * cx;
    struct _node * dx;
} node;

node * insertTree(node *t, int v);
int ternario(node * t);

int main(int argc, char const *argv[]){
    
    int n, el;
    node * tree = NULL;

    scanf("%d", &n);
    for(int i=0; i<n; i++){

        scanf("%d", &el);
        tree = insertTree(tree, el);
    }

    printf("%d\n", ternario(tree));

    return 0;
}

int ternario(node * t){

    if(t==NULL || t->height==0){                                // caso base1: no nodo o foglia

        return 0;
    }

    if(t->height==1){                                           // caso base2: nodo altezza 1

        if(t->sx!=NULL && t->cx!=NULL && t->dx!=NULL){          

            return 1;                                           
        }                              
        else{

            return 0;
        }
    }

    int s = 0;
    if(t->sx!=NULL && t->cx!=NULL && t->dx!=NULL){

        s = 1;
    }
    
    return s + ternario(t->sx) + ternario(t->cx) + ternario(t->dx);    // s = s + ternario()
}

node * insertTree(node *t, int v){

    if(t==NULL){

        node * nuovo = malloc(sizeof(node));
        nuovo->info=v;
        nuovo->height=0;
        nuovo->sx=NULL;
        nuovo->cx=NULL;
        nuovo->dx=NULL;

        return nuovo;
    }

    if(v < t->info){

        t->sx=insertTree(t->sx, v);
    }
    else if(v%t->info==0){

        t->cx=insertTree(t->cx, v);
    }
    else{

        t->dx=insertTree(t->dx, v);
    }

    int hsx= t->sx == NULL ? -1 : t->sx->height;    
    int hcx= t->cx == NULL ? -1 : t->cx->height;
    int hdx= t->dx == NULL ? -1 : t->dx->height; 

    if(hsx > hdx && hsx > hcx){                                               

        t->height=hsx +1;
    }
    else if(hcx > hsx && hcx > hdx){

        t->height=hcx +1;
    }
    else{

        t->height=hdx +1;
    }

    return t;
}