#include "insert.h"

void insertionSort(Record arr[], int size)
{
    int i,j;
    for(i=1;i<size;i++){
        Record key = arr[i];
        for(j=i-1;j>=0;j--){
            if(arr[j].empID<key.empID)
                break;
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
}