#include "cycle.h"

/**Hare and tortoise**/
void testCyclic(List* Ls){
    Node* hare = Ls->head;
    Node* tort = Ls->head;
    if(Ls->size==0){
        printf("Empty list");
        return;
    }
    while(1){
        if(hare->next==NULL || tort->next==NULL){
            printf("Linear");
            return;
        }
        if(hare==tort || hare->next==tort){
            printf("Cyclic");
            return;
        }
        hare = hare->next->next;
        tort = tort->next;
    }
}