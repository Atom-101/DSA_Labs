#include "quick.h"
#include "insert.h"
#include "heap.h"
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
	Record arr3[10000];
	memcpy(&arr1,&arr,sizeof(arr));
	memcpy(&arr2,&arr,sizeof(arr));
	memcpy(&arr3,&arr,sizeof(arr));
	
	double tQ = (double)clock();
	iterativeQuickSort(arr,10000,0);
	tQ = (double)clock()-tQ;
	
	double tI = (double)clock();
	insertionSort(arr1,10000);
	tI = (double)clock() -tI;

	double tM = (double)clock();
	iterativeQuickSort(arr2,10000,50);
	for(i=0;i<10000;i+=50){
		insertionSort(arr2+i,50);
	}
	insertionSort(arr2+(i-50),10000-(i-50));
	tM = (double)clock() - tM;

	double tH = (double)clock();;
	heapSort(arr3,10000);
	tH = (double)clock() - tH;



	// for(i=0;i<10;i++)
	// 	printf("%s\t%lld\n",arr[i].name,arr[i].empID);

	// for(i=0;i<10;i++)
	// 	printf("%s\t%lld\n",arr3[i].name,arr3[i].empID);

	printf("\nTime Quick:\t%lf",tQ);
	printf("\nTime Insertion:\t%lf",tI);
	printf("\nTime Mixed:\t%lf",tM);
	printf("\nTime Heap:\t%lf\n\n",tH);
	
}
