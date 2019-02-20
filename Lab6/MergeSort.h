#ifndef _1
#define _1
#include <stdio.h>
#include <stdlib.h>

typedef struct e{
	char name[10];
	float cgpa;
}Element;

void mergeSort(Element* Ls,int size);
void iterMergeSort(Element* Ls,int size);

#endif


