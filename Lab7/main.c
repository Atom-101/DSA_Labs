#include "quick.h"

int main()
{
	
	FILE* fp = fopen("10","r");
	Record arr[10]; int i=0;
	while(fscanf(fp,"%s %lld\n", arr[i].name, &arr[i].empID)!=EOF){
		i++;
	}
	iterativeQuickSort(arr,10,0);
	for(i=0;i<10;i++)
		printf("%s\t%lld\n",arr[i].name,arr[i].empID);
	
}
