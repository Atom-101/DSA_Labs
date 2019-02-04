//#include <stdlib.h>
#include <stdio.h>

#ifndef _MEM
#define _MEM

#define _NULL -1
#define _FREE_FLAG -2
extern int memory[];
extern int lists[];
extern int free_list;
extern int created_lists;

void initializeMemArray();
void generateFreeList();

#endif