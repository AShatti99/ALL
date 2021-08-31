#include <stdio.h>
#include <stdlib.h>

void quickSort(int a[], int sx, int dx);
int partition(int a[], int sx, int dx);
void swap(int *x, int *y);
int main(){

    int n, i;
    
    scanf("%d", &n);
    int * arr = (int *) malloc(n*sizeof(int));

    for(i = 0; i<n; i++){

        scanf("%d", &arr[i]);
    }
    
    quickSort(arr, 0, n-1);

    for(i = 0; i<n; i++){

        printf("%d ->", arr[i]);
    }
    puts("");

    return 0;
}

void quickSort(int a[], int sx, int dx){

    if(sx < dx){

        int px = partition(a, sx, dx);              
        quickSort(a, sx, px-1);
        quickSort(a, px+1, dx);
    }
}

int partition(int a[], int sx, int dx){

    int x = a[dx];                          
    int i = sx-1;

    for(int j = sx; j<dx; j++){

        if(a[j]<=x){                       

            i++;
            swap(&a[i], &a[j]); 
        }
    }

    swap(&a[i+1], &a[dx]);
    return i+1;
}

void swap(int *x, int *y){

    int temp =*x;
    *x = *y;
    *y = temp;
}



