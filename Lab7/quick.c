#include "quick.h"

void swap(Record[],int,int);
int partition(Record[],int,int);

void iterativeQuickSort(Record arr[],int size, int thresh)
{
	Stack* s = createStack();
	
	int low = 0;
	int high = size-1;
	push(s,low);
	push(s,high);
	
	while(s->size>0)
	{
		high = pop(s);
		low = pop(s);
		
		if(high-low+1<thresh)
			continue;
		int p = partition(arr,low,high);
		
		// For elements before pivot
		push(s,low);
		push(s,p-1);
		
		// For elements after pivot
		push(s,p+1);
		push(s,high);
	}
}

int partition(Record arr[], int low,int high)
{
	Record pivot = arr[high];
	int i = low-1;
	
	for(int j=low;j<=high-1;j++)
	{
		if(arr[j].empID<=pivot.empID){
			i++;
			swap(arr,i,j);
		}
	}
	
	swap(arr,i+1,high);
	return i+1;
}

void swap(Record arr[], int a, int b)
{
	Record t = arr[a];
	arr[a] = arr[b];
	arr[b] = t;
}






















