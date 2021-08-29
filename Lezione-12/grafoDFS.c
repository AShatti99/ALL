/*
GRAFO DIRETTO:
9               9 elementi
2 1 3           il nodo 0 ha come archi uscenti 1 e 3
3 2 3 4
1 4
2 2 5
1 5
1 2
3 5 7 8         seconda sorgente
1 3
0
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct _node{

    int num_edges;          // numero di archi che escono dal vertice v
    int * edges;            // array di vertici adiacenti a v
    int color;              // 0 -> bianco, 1 -> nero
    int start;              // distanza dalla sorgente
    int end;    
    int pred;               // nome del vertice da cui v e' stato scoperto
} edges;

void insertGraph(edges * G, int size);
void DFS(edges * G, int src);
int time =0;                                // variabile globale

int main(int argc, char const *argv[]){
    
    int n, c, i;                                               // numero elementi grafo;
    scanf("%d", &n);

    edges * graph = (edges *) malloc (n*sizeof(edges));

    insertGraph(graph, n);                                  // input 
    
    for(i=0; i<n; i++){                                     // Per ogni nodo...

        if(!graph[i].color){                                // se il colore e' 0
            
            graph[i].color = 1;                             // settalo a 1
            DFS(graph, i);                                  // chiama DFS
        }
    }
    
    for(i=0; i<n; i++){

        printf("%d -> color: %d, precursor: %d, begin: %d, end: %d\n", i, graph[i].color, graph[i].pred, graph[i].start, graph[i].end);
    }

    return 0;
}

void DFS(edges * G, int src){

    int dest;
    time++;
    G[src].start = time;

    for(int i=0; i<G[src].num_edges; i++){    // si scorrono tutti i vertici adiacenti al vertici sorgente

        dest = G[src].edges[i];               // si legge l'i-esimo vertice

        if(!G[dest].color) {                  // si e' gia' incontrano l'i-esimo vertice? 

            G[dest].color = 1;                // se si, settalo come scoperto e rieffettua la chiamata
            G[dest].pred = src;
            DFS(G, dest);             // con nodo sorgente dest
        }
    }
    time++;
    G[src].end=time;
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
        G[i].pred = -1;
        G[i].start = -1;
        G[i].end = -1;
    }
}