#include <stdio.h>

void selectionSort(int a[], int dim);
void swap(int *x, int *y);

int main(){

    int arr[] = {2, 7, 1, 9, 3};

    selectionSort(arr, 5);

    for (int i = 0; i < 5; i++){
        
        printf("%d ->", arr[i]);
    }
    printf("\n");

    return 0;
}

void selectionSort(int a[], int dim){

    int i, j, min;

    for(i=0; i<dim-1; i++){

        min = i;
        for(j = i+1; j<dim; j++){

            if(a[j] < a[min]){

                min = j;
            }

        }

        swap(&a[min], &a[i]);
    }
}

void swap(int *x, int *y){

    int temp = *x;
    *x = *y;
    *y = temp;
}
