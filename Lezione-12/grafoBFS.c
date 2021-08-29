/*
GRAFO INDIRETTO:
11                      11 elementi
4 1 2 3 5               nodo 0 ha 4 archi uscenti 1, 2, 3, 5
2 0 2
2 0 1
3 0 4 6
2 3 7
3 0 6 7
2 3 5
2 4 5 
2 9 10              //  
2 8 10              //  componente sconnessa
2 8 9               //  

Visita BFS: cammini minimi 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _node{

    int num_edges;          // numero di archi che escono dal vertice v
    int * edges;            // array di vertici adiacenti a v
    int color;              // 0 -> bianco, 1 -> nero
    int dist;               // distanza dalla sorgente    
    int pred;               // nome del vertice da cui v e' stato scoperto
} edges;

typedef struct _queue {     // coda definita come un array

    int * values;           // valori coda
    int size;               // dimensione array
    int head;               // primo elemeneto della coda
    int tail;               // ultimo elemento della coda
} queue;

void queue_init(queue * q, int capacity);       // inizializzazione coda
void queue_deinit(queue * q);                   // liberare memoria allocata
void enqueue(queue *q, int v);                  // inserimento nella coda 
int dequeue(queue *q);                          // estrai il primo elemento dalla coda 
int queue_isEmpty(queue *q);                    // verificare se la coda e' vuota

void insertGraph(edges * G, int size);
void BFS(edges *G, int size, int src);

int main(int argc, char const *argv[]){
    
    int n;                                                 // numero elementi grafo;
    scanf("%d", &n);

    edges * graph = (edges *) malloc (n*sizeof(edges));

    insertGraph(graph, n);                                  // input 
    BFS(graph, n, 0);

    for(int i=0; i<n; i++){

        printf("%d -> color: %d, precursor: %d, distance: %d\n", i, graph[i].color, graph[i].pred, graph[i].dist);
    }

    return 0;
}


void BFS(edges *G, int size, int src){  // src = vertice sorgente

    queue q;
    int i, from, dest;              

    G[src].color = 1;               // la visita parte dalla sorgente, quindi si setta a 1 il suo colore
    G[src].dist = 0;                // la distanza della sorgente e' 0 (predecessore sorgente -1)

    queue_init(&q, size);                       // si inizializza la coda
    enqueue(&q, src);                           // si inserisce nella coda la sorgente

    while(!queue_isEmpty(&q)){                  // fino a che la coda non e' vuota

        from = dequeue(&q);                     // si estrae dalla coda v                            
        
        for(i=0; i<G[from].num_edges; i++){     // si esamina array adiacenza di v

            dest = G[from].edges[i];            // per ciascun vertice adiacente...
            
            if(!G[dest].color){                 // ... se non e' mai stato incontrato

                G[dest].color = 1;              // settalo a 1
                G[dest].dist=G[from].dist+1;    // distanza del nodo adiacente e' la distanza di v + 1
                G[dest].pred=from;              // imposta come predecessore v
                enqueue(&q, dest);              // si inserisce nella coda
            }
        }
    }
    queue_deinit(&q);                           // si libera la memoria
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
        G[i].dist = -1;
    }
}

void queue_init(queue * q, int capacity){               // inizializzazione coda

    q->values = malloc(capacity * sizeof(int));         // si crea l'array della coda
    q->size = capacity;  

    q->head = 0;                                       // si setta la testa
    q->tail = 0;                                       // si setta la coda
}

void enqueue(queue *q, int v){

    q->values[q->tail++] = v;                           // q[tail+1] = v
}

int dequeue(queue *q){
    
    return q->values[q->head++];  
}

void queue_deinit(queue * q){

    q->head =0;
    q->tail = 0;
    free(q->values);
}

int queue_isEmpty(queue *q){

    if(q->head == q->tail){

        return 1;
    }
    else{

        return 0;
    }
}