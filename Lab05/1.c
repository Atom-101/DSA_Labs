#include <stdio.h>
#include <stdlib.h>
#include "ReadRecord.h"

Record* readFile(char* filename){
	Record* array = malloc(sizeof(Record)*5);
	FILE* fileptr = fopen(filename,"r");
	//FILE* fileptr = fopen("10.txt","r");
	
	int max = 5;
	
	unsigned long long int cardnum;unsigned int month,year;
	char bankcode[5],firstname[5],lastname[5]; 
	int i=0;
	
	while(fscanf(fileptr,"\" %llu,%[^,],%u/%u,%[^,],%[^\"]\"\n",&cardnum,bankcode,&month,&year,firstname,lastname)!=EOF)
	{
		//printf("%llu\n",cardnum);
		array[i].cardnum = cardnum;
		array[i].bankcode = bankcode;
		array[i].month = month;
		array[i].year = year;
		array[i].firstname = firstname;
		array[i].lastname = lastname;
		
		if(++i>=max){
			max*=2;
			array = realloc(array, sizeof(Record)*max);
		}
	}
	return array;
}

int insertInOrder(Record* array,int pos){
	int j = pos-1;
	while(j>=0 && array[j].cardnum>array[pos].cardnum)
	{
		array[j+1] = array[j];
		j--;
	}
	return j+1;
}

void recursiveInsertionSort(Record* array,int n){
	if(n<=1)
		return;
		
	recursiveInsertionSort(array,n-1);
	
	
	Record last = array[n-1];
	int j = insertInOrder(array,n-2);
	array[j] = last;
}


	
		
		
	
