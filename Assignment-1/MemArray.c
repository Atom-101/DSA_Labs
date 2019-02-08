#include "MemArray.h"
#include "FreeList.h"

int memory[50*3] = {0};
int lists[5] = {-1,-1,-1,-1,-1};
int free_list = -1;
int created_lists = -1;

void initializeMemArray()
{
    for(int i=2;i<50*3;i+=3)
        memory[i] = _FREE_FLAG;
    generateFreeList();
}

void generateFreeList()
{
    int i;
    for(i=50*3-1; i>=0; i-=3)
    {
        if(memory[i] == _NULL)
        {
            break;
        }
    }
    free_list = 50*3-3; memory[50*3-2] = _NULL;
    
    for(int j=50*3-6;j>=i;j-=3)
    {
        push(j);
    }
}

// int main()
// {
//     generateFreeList();
//     printf("%d", free_list);
// }