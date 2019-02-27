#include "stack.h"

Stack* createStack()
{
	Stack* s = malloc(sizeof(Stack));
	s->size = 0;
	s->top = NULL;
	return s;
	
}
void push(Stack* s, int id)
{
	stackNode* node = malloc(sizeof(stackNode));
	node->id = id;
	node->next = NULL;
	node->prev = s->top;
	
	if(s->size == 0){
		s->top = node;
		s->size++;
	}
	else{
		s->top->next = node;
		s->top = node;
		s->size++;
	}
		
}
int pop(Stack* s)
{
	int id = s->top->id;
	stackNode* node  = s->top;
	s->top = s->top->prev;
	if(s->top != NULL)
		s->top->next = NULL;
	free(node);	
	s->size--;
	return id;
}
