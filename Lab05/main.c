#include "ReadRecord.h"
#include <time.h>

int main()
{
	double time = (double)clock();
	Record* arr = readFile("10");
	printf("Size: 10\nRead time:\t%f",-1*(time-(double)clock()));
	time = (double)clock();
	recursiveInsertionSort(arr,10);
	printf("\nSort time:\t%f\n",(double)clock()-time);	main
	
	time = (double)clock();
	arr = readFile("100");
	printf("\nSize: 100\nRead time:\t%f",-1*(time-(double)clock()));
	time = (double)clock();
	recursiveInsertionSort(arr,10);
	printf("\nSort time:\t%f\n",(double)clock()-time);	
	
	time = (double)clock();
	arr = readFile("1000");
	printf("\nSize: 1000\nRead time:\t%f",-1*(time-(double)clock()));
	time = (double)clock();
	recursiveInsertionSort(arr,10);
	printf("\nSort time:\t%f\n",(double)clock()-time);	
	
	time = (double)clock();
	arr = readFile("10000");
	printf("\nSize: 10000\nRead time:\t%f",-1*(time-(double)clock()));
	time = (double)clock();
	recursiveInsertionSort(arr,10);
	printf("\nSort time:\t%f\n",(double)clock()-time);	
	
	time = (double)clock();
	arr = readFile("100000");
	printf("\nSize: 100000\nRead time:\t%f",-1*(time-(double)clock()));
	time = (double)clock();
	recursiveInsertionSort(arr,10);
	printf("\nSort time:\t%f\n",(double)clock()-time);	
}
