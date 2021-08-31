// Heap sort ordina un array

#include <stdio.h>
#include <stdlib.h>

void heapSort(int a[], int n);
void build_max_heap(int a[], int n);
void max_heapify(int a[], int i, int n);
void swap(int *x, int *y); 

int main(int argc, char const *argv[]){
    
    int n, j;
    scanf("%d", &n);
    int * arr = (int *) malloc (n*sizeof(int));
    
    for(j=0; j<n; j++){
        
        scanf("%d", &arr[j]);
    }

    heapSort(arr, n);

    for(j=0; j<n; j++){

        
        printf("%d ", arr[j]);

    }

    puts("");

    return 0;
}

void heapSort(int a[], int n){

    build_max_heap(a, n);

    for(int i= n-1; i>0; i--){

        swap(&a[0], &a[i]);
        max_heapify(a, 0, i);
    }
}

void build_max_heap(int a[], int n){             // esegue max-heapify su ogni nodo che 

    for(int i= (n/2)-1; i>=0; i--){              // non e' una foglia
        
        max_heapify(a, i, n);
    }
}

void max_heapify(int a[], int i, int n){

    int largest = i;                             // si inizializza come radice
    int l = 2 * i + 1;                           // figlio sinistro della radice
    int r = 2 * i + 2;                           // figlio destro della radice 
  
    if (l < n && a[l] > a[largest]) {            // se il figlio sinistro e' maggiore della radice

        largest = l;                        
    }                
    
    if (r < n && a[r] > a[largest]){             // se il figlio destro e' maggiore della radice

        largest = r;
    }                 
        
  

    if (largest != i) {                         // se largest non e' piu' la radice
        swap(&a[i], &a[largest]);               // scambia la radice con a[largest]
  
        max_heapify(a, largest, n);             // chiama ricorsivamente sul sottoalbero
    }                                           // dall'INDICE largest
}

void swap(int *x, int *y){

    int temp =*x;
    *x = *y;
    *y = temp;
}