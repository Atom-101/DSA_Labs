#include "qsort.h"

void printArray(int* studArray, int arrSize)
{
	// printing the array
	int i = 0;
	for(i=0;i<arrSize;i++)
	{
		printf("Arr[%d] is %d\n", i, studArray[i]);
	}
}

int* readData(char * fileName)
{
	FILE* fp = fopen(fileName,"r");
	int size;
	fscanf(fp,"%d\n",&size);
	int* arr = malloc(sizeof(int)*size);
	for(int i=0;i<size;i++){
		fscanf(fp," %d",arr+i);
	}
	return arr;
}

KeyStruct extractKeys(int* Ls, int lsSize, int loKey, int hiKey)
{
	int C[hiKey-loKey];
	int i,k,keysSize;
	for(i=0;i<lsSize;i++){
		C[Ls[i]-loKey]++;
	}
	for(i=0;i<hiKey-loKey;i++){
		if(C[i]>0)
			keysSize++;
	}
	int* keys = malloc(sizeof(int)*keysSize);
	for(i=0,k=0;i<hiKey-loKey;i++){
		if(C[i]>0){
			keys[k] = loKey+i;
			k++;
		}		
	}
	KeyStruct ks = malloc(sizeof(struct keyStruct));
	ks->Keys = keys;
	ks->keysSize = keysSize;
	return ks;
}

int part2Loc(int* Ls, int lo, int hi, int piv)
{
	
}

void quickSortKnownKeyRange(int * Ls, int size, int loKey, int hiKey)
{
	KeyStruct ks = extractKeys(Ls,size,loKey,hiKey);
	int Stack[10000] = {0};
	int top = 0,lo=0,hi=size-1;
	Stack[top++]=hi;
	Stack[top++]=lo;
	while(top>0){
		hi = Stack[top--];
		lo = Stack[top--];
		int piv = getPivot(Ls,size,lo,hi,ks);
		piv = part2Loc(Ls,lo,hi,piv);
		if(lo<piv-1){
			Stack[top++] = piv-1;
			Stack[top++] = lo;
		}
		if(piv+1<hi){
			Stack[top++] = hi;
			Stack[top++] = piv+1;
		}
	}

}

// int getPivot(int * Ls, int size, int lo, int hi, KeyStruct ks)
// {
// 	keysSize/2 == (int)(((lo+hi)/2)/(float)size*(ks->keysSize));
// }