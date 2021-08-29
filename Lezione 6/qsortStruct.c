/* Scrivere un programma che utilizzi la funzione qsort per ordinare un vettore di punti del piano 
cartesiano. Ciascun punto e' formato da una coppia di coordinate (x, y). I punti devono essere ordinati 
per ascissa crescente. A parita' di ascissa, si ordini per ordinata decrescente. La prima riga dell’input 
contiene il numero N dei punti. Le righe successive contengono le coordinate dei punti, una coppia per riga 
(ascissa e ordinata separate da uno spazio). L’output contiene la sequenza ordinata dei punti, un punto per 
riga (ascissa e ordinata separate da uno spazio), ordinati per ascissa crescente. A parita' di ascissa, 
l’ordinamento e' per ordinata decrescente */

#include <stdio.h>
#include <stdlib.h>

typedef struct _point {

    int x;
    int y;
} point;

int compare (const void *a, const void *b); 

int main(){

    int n, i;
    scanf("%d", &n);

    point * p = (point *) malloc (n * sizeof(point));
    for(i=0; i<n; i++){

        scanf("%d%d", &p[i].x, &p[i].y);
    }

    qsort(p, n, sizeof(point), compare);

    for(i=0; i<n; i++){

        printf("%d %d\n", p[i].x, p[i].y);
    }

    free(p);

    return 0;
}

int compare (const void *a, const void *b){
  
    const point * j = a;
    const point * k = b;

    if(j->x == k->x){

        return k->y - j->y;
    }

    return j->x - k->x;
}