#include "List.h"
#include <time.h>

List* createList(int n){
    List* Ls  = malloc(sizeof(List));
    srand(time(0));
    Node *new,*top;
    for(int i=0;i<n;i++){
        new = malloc(sizeof(Node));
        new->elem = rand();
        if(Ls->size==0){
            Ls->head = new;
            top = new;
            Ls->size++;
            continue;
        }
        top->next = new;
        top=new;
        Ls->size++;
    }
    top->next=NULL;
    Ls->tail = top;
    return Ls;
}

void createCycle(List* Ls){
    if(rand()<=RAND_MAX/2)
        return;
    int r = (int)((float)rand()/RAND_MAX)*(Ls->size);
    Node *rnode,*current=Ls->head;
    for(int i=1;i<r;i++){
        current=current->next;
    }
    rnode = current;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = rnode;
}

