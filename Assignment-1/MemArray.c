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

    free_list = (++i); memory[i+1] = _NULL;
    
    for(i=i+3;i<50*3;i+=3)
    {
        push(i);
    }
}

// int main()
// {
//     generateFreeList();
//     printf("%d", free_list);
// }