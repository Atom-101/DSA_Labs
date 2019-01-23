#include <stdlib.h>
#include "Stack.h"

int pop(struct linkedList* head)
{
	int ele = (head->first)->element;
	deleteFirst(head);
	return ele;
}

void push(struct linkedList* head, int ele)
{
	insertFirst(head,ele);
}
