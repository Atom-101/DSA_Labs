#include "MergeSort.h"

void merge(Element Ls1[],int sz1, Element Ls2[], int sz2, Element Ls[])
{
	int i,j,k; i=j=k=0;
	
	while(i<sz1 && j<sz2){
		if(Ls1[i].cgpa<=Ls2[j].cgpa){
			Ls[k] = Ls1[i];
			i++;
		}
		else{
			Ls[k] = Ls2[j];
			j++;
		}
		k++;
	}
	
	while(i<sz1){
		Ls[k] = Ls1[i];
		i++;k++;
	}
	
	while(j<sz2){
		Ls[k] = Ls2[j];
		j++;k++;
	}
	
}

void mergeSort(Element* Ls,int size)
{
	if(size<=1)
		return;

	Element* left = malloc(sizeof(Element)*size/2);
	Element* right = malloc(sizeof(Element)*(size-size/2));
	
	for(int i = 0;i<size;i++){
		if(i<size/2)
			left[i] = Ls[i];
		else
			right[i-size/2] = Ls[i];
	}
	
	mergeSort(left,size/2);
	mergeSort(right,size-size/2);
	
	merge(left,size/2,right,size-size/2,Ls);
}

void iterMergeSort(Element* Ls, int size)
{
	int k,i,j;
	
	
	for(k=1;k<size;k*=2)
	{
		for(i=0;i<size-1;i+=2*k){
			int l = i;
			int r = i+k;
			int r_size = i+2*k-1>=size?(size)-(i+k):k;
			
			if(r>=size)
				break;
			
			Element* left = malloc(sizeof(Element)*k);
			Element* right = malloc(sizeof(Element)*r_size);
			
			
			for(j=0;j<k;j++)
				left[j] = Ls[i+j];
			for(j=0;j<r_size;j++)
				right[j] = Ls[i+k+j];
			
			merge(left,k,right,r_size,Ls+i);
		}
	}
}









		
