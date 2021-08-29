/* Scrivere un programma che legga da tastiera un grafo diretto e stampi il diametro del grafo. 
Il grafo `e rappresentato nel seguente formato: la prima riga contiene il numero n di nodi, 
le successive n righe contengono, per ciascun nodo i, con 0 ≤ i < n, il numero n_i di archi uscenti 
da i seguito da una lista di n_i nodi destinazione, rappresentati con i numeri [0, n). Il diametro 
di un grafo `e la lunghezza del “pi`u lungo cammino minimo” fra tutte le coppie di nodi. Il programma 
deve eseguire una visita BFS a partire da ciascun nodo i del grafo per stabilire il cammino minimo piu' 
lungo a partire da i, e quindi stampare il massimo tra tutti questi. L’input e' costituito da:
    • una riga contenente il numero n di nodi del grafo;
    • n righe, una per ciasun nodo i, con i ∈[0, n), nel seguente formato:
        – numero ni di archi uscenti da i;
        – lista di ni nodi destinazione, rappresentati con i numeri [0, n).
L’output contiene una sola riga contenente il diametro del grafo se questo `e
connesso, -1 altrimenti. */

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
int findDiameter(edges * G, int size);
int BFSdistance(edges *G, int size, int src, int * distance);
int isConnected(edges *G, int size, int * distance);

int main(int argc, char const *argv[]){
    
    int n;
    scanf("%d", &n);
    edges * graph = (edges *) malloc(n*sizeof(edges));

    insertGraph(graph, n);

    printf("%d\n", findDiameter(graph, n));
    
    return 0;
}

int findDiameter(edges * G, int size){

    int * distance = malloc(size*sizeof(int));            // array di distance che viene sovrascritto
    int i, d, maxD = BFSdistance(G, size, 0, distance);   // maxD = BFSdistance sul nodo 0 

    if(!isConnected(G, size, distance)){             // si vede se e' connesso

        return -1;                                   // se ha un nodo con distance = -1
    }

    for(i=1; i<size; i++){                           // per ogni vertice dall'1 in poi

        d = BFSdistance(G, size, i, distance);       

        if(d > maxD){                                // setta il maggiore

            maxD = d;
        }    
    }

    free(distance);
    return maxD;
}

int BFSdistance(edges *G, int size, int src, int * distance){

    queue q;
    int i, from, dest, max = 0; 
    
    queue_init(&q, size);                       
    enqueue(&q, src);
    
    for(i=0; i<size; i++){

        distance[i] = -1;
    }
    distance[src] = 0;

    while(!queue_isEmpty(&q)){                  

        from = dequeue(&q);                                            
        
        for(i=0; i<G[from].num_edges; i++){     

            dest = G[from].edges[i];            
            
            if(distance[dest] == -1){                 

                distance[dest] = distance[from]+1;                  
                enqueue(&q, dest);         

                if(distance[dest] > max){

                    max = distance[dest];
                }     
            }
        }
    }
    
    queue_deinit(&q);         
    return max;
}

int isConnected(edges *G, int size, int * distance){

    int i = 0;

    while (i<size){
        
        if(distance[i] == -1){

            return 0;
        }

        i++;
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
