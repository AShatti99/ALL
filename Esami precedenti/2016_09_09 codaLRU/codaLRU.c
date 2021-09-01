#include <stdio.h>
#include <stdlib.h>

typedef struct _queue{

    int key;
    struct _queue * next;
} queue;

void insHead(queue **Q, int x);
queue * update(queue **Q, int x, int * size, int * sizeMax);
void print(queue *Q);

int main(){

    int dim=0, dimMax;
    int e, el;
    scanf("%d", &dimMax);

    queue * Q = NULL;

    scanf("%d", &e);
    while (e!=0){
        
        if(e==1){

            scanf("%d", &el);
            Q = update(&Q, el, &dim, &dimMax);
        }
        else{

            print(Q);
        }

        scanf("%d", &e);
    }
    
    return 0;
}

queue * update(queue **Q, int x, int * size, int * sizeMax){

    if(*Q==NULL){                                                

        insHead(Q, x);                          // se la coda e' vuota, inserisci in testa
        *size = *size +1;                       // ed aumenta size

        return *Q;
    }
                                                // allora la coda non e' vuota:
    if((*Q)->key !=x){                          // se il primo elemento e' diverso da x (perche' in tal caso non devi fare niente)
                                             
        queue * prec = NULL;
        queue * corr = *Q;

        while (corr->next!=NULL){           // vai avanti fino ad arrivare all'ultimo elemento
                                                   
            if(corr->key == x){             // se hai trovato l'elemento  

                if(corr->next==NULL){              // se e' l'ultimo elemento

                    prec->next=NULL;                    // allora setta il precedente come ultimo
                }
                else{                              

                    prec->next=corr->next;         // altrimenti l'elemento e' in mezzo
                }

                corr->next=(*Q);                   // posizionalo in testa e ritorna
                (*Q) = corr;

                return (*Q);                       
            }

            prec = corr;                   // se non hai trovato l'elemento allora scorri
            corr = corr->next;
        }
    
        *size = *size + 1;                 // se sei arrivato qui, significa che non hai trovato
                                           // l'elemento e quindi lo devi inserire          

        if(*size > *sizeMax){              // se size e' piu' grande di sizeMax

            if(prec==NULL){                     // se prec e' NULL (quindi sizeMax e' 1)

                (*Q)->key=x;                        // setta la testa con x

                return (*Q);                        // e ritorna, perche' non devi inserire
            }
            else{

                prec->next=NULL;                // altrimenti setta il precedente come ultimo
                free(corr);                     // ed elimina il vecchio ultimo elemento
            }
        }

        insHead(Q, x);                      // inserisci l'elemento
    }   
    
    return *Q;
}

void insHead(queue **Q, int x){

    queue * nuovo = malloc(sizeof(queue));
    nuovo->key = x;
    nuovo->next = (*Q);

    (*Q) = nuovo;
}

void print(queue *Q){

    queue * temp = Q;

    while (temp!=NULL){
        
        printf("%d ", temp->key);
        temp = temp->next;
    }

    puts("$");
}
