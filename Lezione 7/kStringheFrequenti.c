/* Scrivere un programma che legga da tastiera due interi N e K, e una sequenza di N stringhe 
e che stampi le K stringhe piu' frequenti in essa contenute, in ordine lessicografico. Si puo' assumere che:
    • non esistano due stringhe con la stessa frequenza;
    • il valore di K sia minore o uguale al numero di stringhe distinte;
    • le stringhe contengono soltanto caratteri alfanumerici (a−z minuscoli e maiuscoli o numeri
     ,nessuno spazio o punteggiatura) e sono lunghe al piu' 100 caratteri ciascuna.
L’input e' formattato nel seguente modo: la prima riga contiene il numero N di stringhe da leggere, mentre 
la seconda riga contiene l’intero K. Seguono N righe contenenti una stringa ciascuna. L’output deve 
contenere solo e soltanto le K stringhe piu' frequenti, ordinate lessicograficamente, stampate una per riga.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct _string {

    char s[MAX];
    int freq;
} string;

int posizione(string * str, int dim, char * word);
int compareFreq(const void *a, const void *b);
int compareString(const void *a, const void *b);

int main(){

    int n, k, p;                                            
    int i=0, j=0;
    char parola[MAX];                                     // stringa di supporto

    scanf("%d %d", &n, &k);
    string * str = (string *) malloc (n*sizeof(string));

    while (i<n){
        
        scanf("%s", parola);                              // controlli se la stringa che vuoi               
        p = posizione(str, j, parola);                    // inserire e' gia' all'interno 

        if(p == -1){                                              

            strcpy(str[j].s, parola);                     // se non e' presente, la copi nella struct
            str[j].freq=0;                                // imposti la frequenza a 0
            j++;                                          // e vai avanti con la struct
        }
        else{

            str[p].freq++;                                // se e' gia' presente, aumenti la frequenza
        }                                                 // di quella stringa di 1

        i++;
    }

    qsort(str, j, sizeof(string), compareFreq);           // in ordine descrescente in base alla frequenza

    char **arrStr = (char **) malloc (k*sizeof(char *));  // ti crei un array di stringhe
    for(i=0; i<k; i++){

        arrStr[i] = (char *) malloc (MAX * sizeof(char)); // copi le prime k stringhe della struct
        strcpy(arrStr[i], str[i].s);                      // cioe' quelle con la frequenza maggiore
    }

    qsort(arrStr, k, sizeof(char *), compareString);      // ordini lessicograficamente l'array di stringhe

    for(i=0; i<k; i++){

        printf("%s\n", arrStr[i]);
    }

    free(str);                                            //

    for(i=0; i<k; i++){                                   //

        free(arrStr[i]);                                  //    FREE
    }
    
    free(arrStr);                                         //

    return 0;
}

int posizione(string * str, int dim, char * word){

    int i=0;

    while (i<dim){

        if(strcmp(str[i].s, word)==0){
            
            return i;
        }

        i++;
    }

    return -1;
}

int compareFreq(const void *a, const void *b){

    const string *x = a;
    const string *y = b;

    return y->freq - x->freq; 
}

int compareString(const void *a, const void *b){

    char * const *x = a;
    char * const *y = b;

    return strcmp(*x, *y);
}