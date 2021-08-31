// max-heapify CONSERVA la proprieta' di max heap

#include <stdio.h>
#include <stdlib.h>

void max_heapify(int a[], int i, int n);
void swap(int *x, int *y); 

int main(int argc, char const *argv[]){
    
    int n, j;
    int k=1;
    scanf("%d", &n);
    int * arr = (int *) malloc (n*sizeof(int));
    
    for(j=0; j<n; j++){
        
        scanf("%d", &arr[j]);
    }

    max_heapify(arr, 0, n);


    for(j=0; j<n; j++){

        
        printf("%d ", arr[j]);

        if(j+1==k){

            puts("");
            k=k*2+1;
        }
    }

    puts("");

    return 0;
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