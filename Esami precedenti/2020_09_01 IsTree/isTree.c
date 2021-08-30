#include <stdio.h>
#include <stdlib.h>

typedef struct _edges{

    int num_edges;
    int * edges;
    int color;
    int pred;
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
int queue_isEmpty(queue *q); 

void insertGraph(edges * G, int size);
int isTree(edges * G, int size, int src);

int main(){

    int n;
    scanf("%d", &n);
    edges * graph = (edges *) malloc(n*sizeof(edges));

    insertGraph(graph, n);

    printf("%d\n", isTree(graph, n, 0));

}

int isTree(edges * G, int size, int src){

    queue q;
    int i, from, dest;              

    G[src].color = 1;
    G[src].pred = -1;

    queue_init(&q, size);                       
    enqueue(&q, src);                           

    while(!queue_isEmpty(&q)){                  

        from = dequeue(&q);                                                 
        
        for(i=0; i<G[from].num_edges; i++){     

            dest = G[from].edges[i];            
            
            if(!G[dest].color){                 

                G[dest].color = 1;              
                G[dest].pred = from;
                enqueue(&q, dest);              
            }
            else{                                       // se e' gia' colorato

                if(G[from].pred!=dest){                     // se dest non e' padre di from, esci

                    return 0;
                }
            }
        }
    }

    queue_deinit(&q);  
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

        G[i].color = 0;
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
