/* Scrivere un programma che legga da tastiera un grafo indiretto e stampi 1 se il grafo e' connesso, 
0 altrimenti. Il grafo `e rappresentato nel seguente formato: la prima riga contiene il numero n 
di nodi, le successive n righe contengono, per ciascun nodo i, con 0 ≤ i < n, il numero n_i di archi 
uscenti da i seguito da una lista di ni nodi destinazione, rappresentati con i numeri [0, n). 
Si assuma che l’input contenga un grafo indiretto, e quindi che per ciascun arco da i a j esiste anche 
l’arco da j ad i. Un grafo e' connesso quando esiste un percorso tra due vertici qualunque del grafo. 
Il programma deve eseguire una visita DFS (a partire da un nodo qualunque, perche'?) del grafo 
per stabilire se questo e' connesso. L’input e' costituito da:
    • una riga contenente il numero n di nodi del grafo;
    • n righe, una per ciasun nodo i, con i ∈[0, n), nel seguente formato:
        – numero ni di archi uscenti da i;
        – lista di ni nodi destinazione, rappresentati con i numeri [0, n).
L’output contiene una riga contenente 1 se il grafo `e connesso, 0 altrimenti. */

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {

    int num_edges;
    int * edges;
    int color;
} edges;

void insertGraph(edges * G, int size);
int isConnected(edges *G, int size);
void DFS(edges * G, int src);

int main(int argc, char const *argv[]) {
    
    int n;
    scanf("%d", &n);

    edges * graph = (edges *) malloc(n*sizeof(edges));

    insertGraph(graph, n);

    printf("%d\n", isConnected(graph, n));

    return 0;
}

int isConnected(edges *G, int size){

    G[0].color = 1;
    DFS(G, 0);                   // esegui DFS che colora tutti i vertici connessi al vertice sorgente

    for(int i=0; i<size; i++){   // poi controlli per ogni vertice il colore, se e' bianco 

        if(G[i].color == 0){     // significa che fa parte di una componente sconnessa, ritorna 0

            return 0;
        }
    }

    return 1;
}

void DFS(edges * G, int src){

    for(int i=0; i<G[src].num_edges; i++){

        int dest = G[src].edges[i];

        if(!G[dest].color){

            G[dest].color = 1;
            DFS(G, dest);
        }
    }
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

        G[i].color = 0;
    }
}
