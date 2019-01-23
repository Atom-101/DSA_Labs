#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main(int argc, char *argv[])
{
	// Create a file pointer and open the file read as command line argument.
	FILE * fileptr = fopen(argv[1], "r");
	// Declare a pointer to a linked list (head) and allocate memory to it.
	struct linkedList * stack = (struct linkedList *) malloc (sizeof	(struct linkedList));
	// In a loop read the file and insert elements into the linkedList.
	//while (!feof(fileptr))
	int temp;
	while(fscanf(fileptr, "%d", &temp) !=EOF)
	{
	// read the next element and store into the temp variable.
	// insert temp into the linked list.
		push(stack,temp);
	}
	// close the file pointer
	fclose(fileptr);
	
	printf("\n");
	while(stack->first != NULL)
	{
		printf("%d,",pop(stack));
	}

}
