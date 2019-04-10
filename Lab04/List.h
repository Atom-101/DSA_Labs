#ifndef _LIST
#define _LIST

#include <stdlib.h>
#include <stdio.h>

typedef struct list{
    int size;
    struct node* head;
    struct node* tail;//for debugging
} List;

typedef struct node{
    int elem;
    struct node* next;
}Node;

List* createList(int n);
void createCycle(List* Ls);

#endif