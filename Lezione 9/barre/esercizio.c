#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // - infinito

int cut_rod(int p[], int n, int * sol);

int main(int argc, char const *argv[]){
    
    int n, i, res1, res2;
    scanf("%d", &n);

    int * prezzo = (int *) malloc (n*sizeof(int));

    for(i=0; i<n; i++){

        scanf("%d", &prezzo[i]);
    }

    res1 = cut_rod(prezzo, n, &res2);

    if(n-res2 == 0){

        printf("%d\n%d\n", res1, res2);
    }
    else{

        printf("%d\n%d %d\n", res1, res2, n-res2);
    }
    
    return 0;
}

int cut_rod(int p[], int n, int *sol){

    int j, i;
    int * r = (int *) malloc ((n+1)*sizeof(int));         // ricavi
    int * s = (int *) malloc ((n+1)*sizeof(int));         // soluzione
    r[0] = 0;
    
    for(j=1; j<=n; j++){

        int q = INT_MIN;
        for(i=0; i<j; i++){

            if(q < p[i] + r[j-i-1]){

                q = p[i] + r[j-i-1];
                s[j] = i+1;
            }
        }

        r[j] = q;
    }

    *sol = s[n];
    return r[n];
}
