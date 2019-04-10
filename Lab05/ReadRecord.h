#include <stdio.h>
#include <stdlib.h>

#ifndef rr
#define rr

typedef struct record{
	unsigned long long int cardnum;
	char* bankcode;
	unsigned int month;
	unsigned int year;
	char* firstname;
	char* lastname;
} Record;

Record* readFile(char* filename);
void recursiveInsertionSort(Record* array,int n);

#endif
	
