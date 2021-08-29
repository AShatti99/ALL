/* Scrivere un programma che legga da tastiera un grafo diretto, una sequenza di m query, 
ciascuna composta dagli indici di due nodi del grafo e stampi, per ciascuna query, la lunghezza 
del percorso minimo che collega i rispettivi due nodi della query. Il grafo e' rappresentato nel 
seguente formato: la prima riga contiene il numero n di nodi, le successive n righe contengono,
per ciascun nodo i, con 0 ≤ i < n, il numero ni di archi uscenti da i seguito da una lista di n_i nodi 
destinazione, rappresentati con i numeri [0, n). Il percorso minimo dal nodo i al nodo j e' il percorso 
che porta da i a j che attraversa il minor numero di archi. A tale scopo si esegua una visita BFS 
del grafo a partire dal nodo i per stabilire il percorso minimo che porta al nodo j, qualora questo 
esista. L’input e' costituito da:
    • una riga contenente il numero n di nodi del grafo;
    • n righe, una per ciasun nodo i, con i ∈[0, n), nel seguente formato:
        – numero ni di archi uscenti da i;
        – lista di ni nodi destinazione, rappresentati con i numeri [0, n).
    • una riga contenente il numero m di query;
    • m righe, una per ciasuna query, contenenti l’indice del nodo di partenza e l’indice del nodo 
      di destinazione.
L’output contiene m righe contenenti ciascuna la lunghezza del percorso minimo che collega i due nodi 
della rispettiva query e -1 quando i nodi non sono collegati. */

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {

    int num_edges;
    int * edges;
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
int BFSdistancePath(edges *G, int size, int start, int end);

int main(int argc, char const *argv[]) {
    
    int n, q;
    int node1, node2;
    scanf("%d", &n);

    edges * graph = (edges *) malloc (n*sizeof(edges));

    insertGraph(graph, n);

    scanf("%d", &q);

    while (q>0){
        
        scanf("%d%d", &node1, &node2);
        printf("%d\n", BFSdistancePath(graph, n, node1, node2));
        q--;
    }
    
    return 0;
}

int BFSdistancePath(edges *G, int size, int start, int end){

    if(start == end){

        return 0;
    }

    queue q;
    int i, from, dest;
    int * distance = malloc(size*sizeof(int));

    for(i=0; i<size; i++){

        distance[i]=-1;
    }
    distance[start]=0;
    
    queue_init(&q, size);                       
    enqueue(&q, start);

    while(!queue_isEmpty(&q)){                  

        from = dequeue(&q);                                                 
        
        for(i=0; i<G[from].num_edges; i++){     

            dest = G[from].edges[i];            
            
            if(distance[dest] == -1){                 
             
                distance[dest]=distance[from]+1;    

                if(dest == end){
                    
                    int d = distance[dest];
                    free(distance);
                    queue_deinit(&q);
                    return d;
                }

                enqueue(&q, dest);              
            }
        }
    }

    queue_deinit(&q);    
    free(distance);
    return -1;
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

    free(q->values);
    q->head =0;
    q->tail = 0;
    q->size = 0;
}

int queue_isEmpty(queue *q){

    if(q->head == q->tail){

        return 1;
    }
    else{

        return 0;
    }
}