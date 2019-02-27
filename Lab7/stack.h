#ifndef _stack
#define _stack

#include <stdio.h>
#include <stdlib.h>
#include "quick.h"

typedef struct s{
	struct s* next;
	struct s* prev;
	int id;
} stackNode;

typedef struct S{
	stackNode* top;
	int size;
}Stack;

Stack* createStack();
void push(Stack* s, int id);
int pop(Stack* s);


#endif
