#include "cycle.h"

void makePureCircle(List* Ls,Node* ptr2){
    Node* ptr1 = Ls->head;
    Node* freeptr;
    while(ptr1!=ptr2){
        freeptr = ptr1;
        ptr1= ptr1->next;
        ptr2= ptr2->next;
        free(freeptr);
    }
    Ls->head = ptr1;
}


List* makeCircularList(List* Ls){
    Node* hare = Ls->head;
    Node* tort = Ls->head;
    if(Ls->size==0){
        printf("Empty list");
        return;
    }
    while(1){
        if(hare->next==NULL){
            printf("Linear");
            hare->next=Ls->head;
            return;
        }
        if(tort->next==NULL){
            printf("Linear");
            tort->next=Ls->head;
            return;
        }
        if(hare==tort){
            printf("Cyclic");
            makePureCircle(Ls,hare);
            return;
        }
        hare = hare->next->next;
        tort = tort->next;
    }
    return Ls;
}