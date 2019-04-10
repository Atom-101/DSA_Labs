#include "heap.h"

void maxHeapify(Record arr[],int i,int size)
{
    int largest=i;
    int left = 2*i;
    int right = 2*i+1;
    if(left<size && arr[left].empID>arr[i].empID)
        largest = left;
    if(right<size && arr[right].empID>arr[largest].empID)
        largest = right;
    Record temp = arr[largest];
    arr[largest] = arr[i];
    arr[i] = temp;
    if(largest!=i)
        maxHeapify(arr,largest,size);
}

void buildMaxHeap(Record arr[],int size)
{
    int i = size/2-1;
    for(;i>=0;i--){
        maxHeapify(arr,i,size);
    }

}

void heapSort(Record arr[],int size)
{
    buildMaxHeap(arr,size);
    // Record sorted[size];
    int j = size-1;
    for(int i=0;i<size-1;i++){
        Record temp = arr[0];
        arr[0] = arr[j];
        arr[j] = temp;
        j--;
        maxHeapify(arr,0,j);
    }

}

