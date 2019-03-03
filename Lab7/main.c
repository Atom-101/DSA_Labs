#include "quick.h"
#include "insert.h"
#include <string.h>
#include <time.h>
int main()
{
	
	FILE* fp = fopen("10000","r");
	Record arr[10000]; int i=0;
	while(fscanf(fp,"%s %lld\n", arr[i].name, &arr[i].empID)!=EOF){
		i++;
	}
	Record arr1[10000];
	Record arr2[10000];
	memcpy(arr1,&arr,sizeof(arr));
	memcpy(&arr2,&arr,sizeof(arr));
	
	double tQ = (double)clock();
	iterativeQuickSort(arr,10000,0);
	tQ = (double)clock()-tQ;
	
	double tI = (double)clock();
	insertionSort(arr1,10000);
	tI = (double)clock() -tI;

	double tM = (double)clock();
	iterativeQuickSort(arr2,10000,150);
	for(i=0;i<10000;i+=150){
		insertionSort(arr2+i,150);
	}
	insertionSort(arr2+(i-150),10000-(i-150));
	tM = (double)clock() - tM;

	// for(i=0;i<10;i++)
	// 	printf("%s\t%lld\n",arr[i].name,arr[i].empID);

	// for(i=0;i<10;i++)
	// 	printf("%s\t%lld\n",arr2[i].name,arr2[i].empID);

	printf("\nTime Q:\t%lf",tQ);
	printf("\nTime I:\t%lf",tI);
	printf("\nTime M:\t%lf\n\n",tM);
	
}
