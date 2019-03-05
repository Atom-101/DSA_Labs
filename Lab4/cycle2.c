#include "cycle.h"

/**Link reversal**/
void testCyclic(List* Ls){
    if(Ls->size==0){
        printf("Empty list");
        return;
    }    
    Node* prev = NULL;
    Node* next = NULL;
    Node* current = Ls->head;
    while(current!=NULL){
        //Reverse
        next = current->next;
        current->next = prev;

        //Advance
        prev=current;
        current=next;        

        if(current==Ls->head){
            printf("Cyclic\n");
            return;
        }
    }
    printf("Linear\n");
}