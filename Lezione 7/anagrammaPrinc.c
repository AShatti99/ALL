/* L’anagramma principale di una stringa S e' l’anagramma di S ottenuto ordinando i suoi simboli 
individualmente. Ad esempio, l’anagramma principale di abracadabra e' aaaaabbcdrr. Notare che l’anagramma 
principale di una stringa e' unico e che stringhe diverse possono avere lo stesso anagramma principale.
Scrivere un programma che legga da tastiera una sequenza A di N stringhe di lunghezza variabile. 
Il programma deve poi raggruppare le stringhe di A aventi lo stesso anagramma principale e restituire 
le stringhe di ciascun gruppo in ordine lessicografico non decrescente. I gruppi devono essere restituiti 
in ordine lessicografico non decrescente del corrispondente anagramma principale. L’input e' formattato 
nel seguente modo:
    • La prima riga contiene la lunghezza N della sequenza. Si assuma che N sia maggiore di zero.
    • Le righe successive contengono le N stringhe che compongono la sequenza A, una per riga. Si puo' 
      assumere che le stringhe abbiano lunghezza inferiore a 20 caratteri. 
L’output deve contenere solo e soltanto un gruppo di stringhe per riga. Le stringhe dello stesso gruppo 
devono essere separate da uno spazio. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAX 20

typedef struct _string {
    
    char str[MAX];
    char anag[MAX];
} string;

int compareChar(void const *a, void const *b);
int compareAnag(void const *a, void const *b);

int main(){

    int n, i;
    scanf("%d", &n);

    string * s = (string *) malloc (n*sizeof(string));
    for(i=0; i<n; i++){

        scanf("%s", s[i].str);  

        strcpy(s[i].anag, s[i].str);
        qsort(s[i].anag, strlen(s[i].anag), sizeof(char), compareChar);     // calcoli l'anagramma
    }

    qsort(s, n, sizeof(string), compareAnag);          // ordini in base all'anagramma, se sono uguali

    for(i=0; i<n; i++){                                // in ordine lessicografico
        
        if(strcmp(s[i].anag, s[i+1].anag)==0){

            printf("%s ", s[i].str);
        }
        else{

            printf("%s\n", s[i].str);
        }
    }

    free(s);
}

int compareChar(void const *a, void const *b){

    return *(char *)a - *(char *)b;
}

int compareAnag(void const *a, void const *b){

    const string *x = a;
    const string *y = b;

    if(strcmp(x->anag, y->anag)==0){

        return strcmp(x->str, y->str);
    }

    return strcmp(x->anag, y->anag);
}
