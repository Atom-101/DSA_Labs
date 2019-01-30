#include "que.h"

Queue* newQ()
{
	Queue* q = malloc(sizeof(Queue));
	q->head = malloc(sizeof(Element));
	q->tail = -1;
	q->head->next = NULL;
	return q;
}

int isEmptyQ(Queue* q)
{
	if(q->tail==-1)
		return 1;
	else
		return 0;
}

Queue* delQ(Queue* q)
{
	
	if(q->tail!=-1)
	{
		Element* temp = q->head;
		q->head = temp->next;
		free(temp);
	}
	return q;
}

Element front(Queue* q)
{
	return *(q->head);
}

Queue* addQ(Queue* q, int ele)
{
	Element* new = malloc(sizeof(Element));
	new->next = NULL;
	new->elem = ele;
	
	//Que was empty initially
	if(q->tail==-1)
	{
		q->head = new;
		q->tail = new; 
	}
	else
	{
		q->tail->next = new;
		q->tail = new;
	}
	return q;
}

int lengthQ(Queue* q)
{
	int len = 0;
	Element* ptr = q->head;
	while(ptr)
	{
		len++;
		ptr = ptr->next;
	}
	
	return len;
}
