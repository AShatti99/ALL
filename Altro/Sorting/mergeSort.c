#include <stdio.h>
#include <stdlib.h> 

void mergeSort(int a[], int sx, int dx);
void merge(int a[], int sx, int dx, int cen);

int main(){

    int arr[] = {3, 7, 2, 9, 4};

    mergeSort(arr, 0, 4);

    for(int i=0; i<5; i++){

        printf("%d ->", arr[i]);
    }
    printf("\n");
    
    return 0;
}


void mergeSort(int a[], int sx, int dx){

    if(sx < dx){

        int cen = (sx + dx)/2;

        // printf("A\n");
        mergeSort(a, sx, cen);
        // printf("B\n");
        mergeSort(a, cen+1, dx);

        // printf("C\n");
        merge(a, sx, dx, cen);
    }
}

void merge(int a[], int sx, int dx, int cen){

    int i, j, k;
    int n1 = cen - sx + 1;
    int n2 = dx - cen;

    int * L = (int *) malloc (n1 * sizeof(int));
    int * R = (int *) malloc (n2 * sizeof(int));

    for(i=0; i<n1; i++){

        L[i] = a[sx + i];
    }

    for(j=0; j<n2; j++){

        R[j] = a[cen + j + 1];
    }

    i=0, j=0, k=sx;

    while (i < n1 && j < n2){
        
        if(L[i] <= R[j]){

            a[k] = L[i];
            i++;
        }
        else{

            a[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1){
        
        a[k] = L[i];
        i++, k++;
    }

    while (j < n2){
        
        a[k] = R[j];
        j++, k++;
    }
    
    free(L), free(R);
}

