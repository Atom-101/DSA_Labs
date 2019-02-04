#include "MemArray.h"
#include "FreeList.h"


void push(int i)
{
    memory[i+1] = free_list;
    free_list = i;

}

void pop()
{
    free_list = memory[free_list+1];

}

// int main()
// {
//    //initializeMemArray();
   
//    for(int i=4; i>0; i--)
//     {
//         printf("%d\t",lists[i]);

//     } 
// }