#include <stdio.h>
#include <stdlib.h>

typedef struct _node{

    int info;
    int c;
} node;

int searchTable(node **T, int key, int size);
int printCount(node **T, int key, int k, int size);

int main(int argc, char const *argv[]){
    
    int n, k;
    int i, j, h;
    scanf("%d%d", &n, &k);

    int * arr = (int *)malloc(n*sizeof(int));                   // array di input
    node ** T = (node **)malloc(n*sizeof(node *));              // tabella hash

    for(i=0; i<n; i++){                                         

        scanf("%d", &arr[i]);                                   // carica array di input
        T[i] = malloc(sizeof(node));                            // inizializza tabella hash
    } 

    i=0, j=0;
    while (j<n){                                                // vai avanti fino a n

        if(!searchTable(T, arr[j], i)){              // se l'elemento non e' gia' presente nella tabella     
                                                                
            T[i]->info = arr[j];                     // setta il valore e l'occorrenza
            T[i]->c = 1;                            
            i++;                                     // vai avanti con i
        }

        j++; 
    }

    for(i=0; i<n; i++){                              

        if(printCount(T, arr[i], k, n)==1){

            printf("%d ", arr[i]);
        }
    }

    puts("");
    
    return 0;
}

int printCount(node **T, int key, int k, int size){

    for(int i=0; i<size; i++){  

        if(T[i]->info == key && T[i]->c >= k){              

            return 1;
        }
    }

    return 0;
}

int searchTable(node **T, int key, int size){

    for(int i=0; i<size; i++){

        if(T[i]->info == key){

            T[i]->c++;
            return 1;
        }
    }

    return 0;
}
