/* Si consideri il quadrante positivo del piano cartesiano. Un punto colorato sul piano e' caratterizzato 
da una tripla (x, y, c), dove x, y e c sono valori interi non negativi. Il primo intero della tripla 
caratterizza l’ascissa del punto, il secondo intero l’ordinata, il terzo intero e' il colore assegnato 
al punto. Sia A un insieme di N punti colorati. Lo scopo del programma e' quello di rispondere a una 
sequenza di interrogazioni sui punti di A. Un’interrogazione e' definita da due coppie〈(x1, y1); (x2, y2),  
dove x1 < x2 e y1 < y2, che identificano un rettangolo R:

    R={(u, v) ∈ N2 | x1 ≤ u ≤ x2 ∧ y1 ≤ v ≤ y2}

Data un’interrogazione R, si vuole calcolare il numero di colori distinti dei punti di A che ricadono 
in R (i punti sul perimetro del rettangolo devono essere considerati nel conteggio). Scrivere un programma 
che legga da tastiera una sequenze A di N punti colorati e un insieme Q di M interrogazioni, e stampi 
la risposta a ciascuna interrogazione su una riga distinta. Nel caso non vi siano punti all’interno 
del rettangolo stampare 0. L’input e' formattato nel seguente modo:

    • Le prime due righe contengono i due interi N e M, rispettivamente. Si assuma che N >0 ed M >0.
    • Seguono N righe, contenenti i punti colorati, uno per riga. Ogni punto e' definito da 3 interi, 
      separati da uno spazio, che rappresentano, nell’ordine, i valori x, y e c.
    • Le ultime M righe contengono le interrogazioni, disposte una per riga. Ogni interrogazione e' definita 
      da 4 interi, separati da uno spazio, che rappresentano, nell’ordine, i valori x1, y1, x2, y2. 
      Si assuma che x1 < x2 e y1 < y2. 

L’output deve contenere solo e soltanto gli interi di risposta alle interrogazioni, uno per riga. */


#include <stdio.h>
#include <stdlib.h>

typedef struct _point{

    int x;
    int y;
    int c;
} point;

int compare(const void *a, const void *b);

int main(){

    int n, m, i, j;
    int x1, y1, x2, y2;
    int c, last;
    scanf("%d%d", &n, &m);

    point * p = (point *) malloc (n * sizeof(point));
    for(i=0; i<n; i++){

        scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].c);
    }

    qsort(p, n, sizeof(point), compare);          // in ordine crescente in base al colore (leggi giu')

    for(j=0; j<m; j++){

        c=0, last=-1;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        
        for(i=0; i<n; i++){

            if(x1 <= p[i].x && y1 <= p[i].y && x2 >= p[i].x && y2 >= p[i].y && last != p[i].c){

                last=p[i].c;                      // in questo modo per contare i colori uguali
                c++;                              // una sola volta, ci si basa sull'ultimo colore trovato
            }                                      
        }
        
        printf("%d\n", c);
    }

    free(p);

    return 0;
}

int compare(const void *a, const void *b){

    const point *x = a;
    const point *y = b;

    return x->c - y->c;
}




    

