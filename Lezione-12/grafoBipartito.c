/* Un grafo è bipartito se l'insieme di nodi può essere partizionato in due sottoinsiemi X e Y 
tali che ciascun arco del grafo ha una delle due estremità in X e l'altra in Y

Scrivere un programma che legga da tastiera un grafo indiretto e stampi 1 se il grafo e' bipartito, 
0 altrimenti. Il grafo `e rappresentato nel seguente formato: la prima riga contiene il numero n di nodi, 
le successive n righe contengono, per ciascun nodo i, con 0 ≤ i < n, il numero n_i di archi uscenti da i 
seguito da una lista di n_i nodi destinazione, rappresentati con i numeri [0, n). Si assuma che l’input 
contenga un grafo indiretto, e quindi che per ciascun arco da i a j esista anche l’arco da j ad i.
Un grafo bipartito e' un grafo tale che l’insieme dei suoi vertici si puo' partizionare in due 
sottoinsiemi in cui ogni vertice e' collegato solo a vertici appartenenti alla partizione opposta.
Suggerimento: un grafo e' bipartito se e solo se e' possibile colorarlo usando due colori. Colorare 
il grafo corrisponde ad assegnare a ciascun vertice un colore diverso da quello dei suoi vertici adiacenti. */

// si devono visitare tutti i vertici quindi si usa la DFS

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {

    int num_edges;
    int * edges;
    int color;
} edges;

void insertGraph(edges * G, int size);
int DFS_visit(edges * G, int size);
int DFS_colors(edges * G, int src, int c);

int main(int argc, char const *argv[]){
    
    int n;
    scanf("%d", &n);

    edges * graph = (edges *) malloc(n*sizeof(edges));

    insertGraph(graph, n);
    
    printf("%d\n", DFS_visit(graph, n));
    
    return 0;
}

int DFS_visit(edges * G, int size){

    for(int i=0; i<size; i++){

        if(G[i].color == -1){                            // se e' un nodo sorgente

            G[i].color = 0;                              // coloralo
        }

        if(!DFS_colors(G, i, !G[i].color)){              // chiama DFS_colors con il colore opposto

            return 0;
        }
    }

    return 1;
}

int DFS_colors(edges * G, int src, int c){

    for(int i=0; i<G[src].num_edges; i++){

        int dest = G[src].edges[i];

        if(G[dest].color == !c){       // se il nodo adiacente ha lo stesso colore del nodo sorgente 

            return 0;                  // (cioe' lo stesso colore in cui e' stata chiamata DFS_colors)
        }

        if(G[dest].color == -1){       // se non e' mai stato colorato

            G[dest].color = c;         // coloralo e chiama DFS_colors con dest come sorgente
            DFS_colors(G, dest, !c);   // e con il colore opposto
        }
    }

    return 1;
}


void insertGraph(edges * G, int size){

    int g;                                    // grado uscente di ogni vertice

    for(int i=0; i<size; i++){

        scanf("%d", &g);
        G[i].num_edges = g;
        G[i].edges = (int *) malloc(g*sizeof(int));
        for(int j=0; j<g; j++){

            scanf("%d", G[i].edges + j);
        }

        G[i].color = -1;
    }
}