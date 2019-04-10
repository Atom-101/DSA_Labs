#ifndef _quick
#define _quick

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct r{
	char name[10];
	long long int empID;
} Record;

void iterativeQuickSort(Record arr[], int size, int thresh);
#endif
