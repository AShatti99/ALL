#include <stdio.h>

void insertionSort(int a[], int dim);

int main(){

    int arr[] = {2, 7, 1, 9, 3};

    insertionSort(arr, 5);

    for (int i = 0; i < 5; i++){
        
        printf("%d ->", arr[i]);
    }
    printf("\n");

    return 0;
}

void insertionSort(int a[], int dim){

    int i, j, key;
    for(i=1; i<dim; i++){

        key = a[i];
        j= i-1;

        while (j>=0 && a[j] > key){
            
            a[j+1] = a[j];
            j--;
        }
        
        a[j+1] = key;
    }
}
