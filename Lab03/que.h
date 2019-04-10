#include <stdio.h>
#include <stdlib.h>

#ifndef _QUE
#define _QUE
typedef struct node{
	struct node* next;
	int elem;
} Element;


typedef struct Q{
	struct node* head;
	struct node* tail;
}Queue;

Queue* newQ();

int isEmptyQ(Queue* q);

Queue* delQ(Queue* q);

Element front(Queue* q);

Queue* addQ(Queue* q, int ele);

int lengthQ(Queue* q);

#endif





