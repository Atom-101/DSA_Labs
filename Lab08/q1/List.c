#include "List.h"

void* myalloc(int size)
{
    globalCounter+=size;
    void* ptr = malloc(size+sizeof(int));
    *((int*)ptr) = size;
    return ptr+sizeof(int);
}

void myfree(void* ptr)
{
    globalCounter-=*((int*)(ptr-sizeof(int)));
    free(ptr-sizeof(int));
}

List createList(Student studArray, int arraySize)
{
    List studList = myalloc(sizeof(struct list));
    studList->count=arraySize;
    studList->first=myalloc(sizeof(struct node));
    studList->first->next = NULL;
    Node current = studList->first;


    int i;
    for(i=0;i<arraySize-1;i++){
        current->record = studArray+i;
        current->next = myalloc(sizeof(struct node));
        current = current->next;
    }

    current->record=studArray+i;
    current->next = NULL;
    studList->last=current;

    return studList;

}

void insertInOrder(List list, Node newNode)
{
    list->count++;
    Node current = list->first;
    Node prev = list->first;
    if(list->count==1){
        list->first = newNode;
        newNode->next = NULL;
        return;
    }
    if(newNode->record->marks<current->record->marks){
        newNode->next = current;
        list->first = newNode;
        return;
    }
    current = current->next;
    while(current != NULL){
        if(current->record->marks > newNode->record->marks){
            prev->next = newNode;
            newNode->next = current;
            return;
        }
        prev = current;
        current = current->next;
    }
    prev->next = newNode;
    newNode->next = NULL;
}

List insertionSort(List list){
    List list1 = myalloc(sizeof(struct list));
    int i= list->count-1;
    Node current = list->first;
    for(;i>=0;i--){
        Node key = myalloc(sizeof(struct node));
        key->record = current->record;
        insertInOrder(list1,key);
        key = current;
        current = current->next;
        myfree(key);
    }
    myfree(list);
    return list1;
}

double measureSortingTime(List list){
    double t = (double)clock();
    insertionSort(list);
    return (double)clock()-t;
}