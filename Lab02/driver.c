/* driver.c */
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(int argc, char *argv[])
{
	// Create a file pointer and open the file read as command line argument.
	FILE * fileptr = fopen(argv[1], "r");
	// Declare a pointer to a linked list (head) and allocate memory to it.
	struct linkedList * head = (struct linkedList *) malloc (sizeof	(struct linkedList));
	// In a loop read the file and insert elements into the linkedList.
	//while (!feof(fileptr))
	int temp;
	while(fscanf(fileptr, "%d", &temp) !=EOF)
	{
	// read the next element and store into the temp variable.
	// insert temp into the linked list.
		insertFirst(head,temp);
	}
	// close the file pointer
	fclose(fileptr);
	// print the linked list.
	printList(head);
	// delete the first element of the linked list.
	deleteFirst(head);
	// print the linked list again to check if delete was successful.
	printList(head);
	// print the linked list to a new file.
	delete(head,12);
	//printf("\n A");
	printList(head);
	//fileptr = fopen("out.txt",'w');

}
