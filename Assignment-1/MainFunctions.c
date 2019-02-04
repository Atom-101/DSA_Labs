#include "MainFunctions.h"
#include "MemArray.h"
#include "FreeList.h"

void createList()
{
    int inp;
    if(free_list == -1){
        printf("\nFAILURE: MEMORY NOT AVAILABLE");
        return;
    }
    
    created_lists++;
    if(created_lists>5){
        printf("\nFAILURE: MAX NUMBER OF LISTS EXCEEDED");
        created_lists--;
        return;
    }
    printf("\nThe sequence number of the newly created list is: %d",created_lists);
    printf("\nEnter key value to be inserted in the newly created list-%d: ",created_lists);
    scanf("%d",&inp);

    lists[created_lists] = free_list;
    
    if(memory[free_list+1] == _NULL){
        free_list = -1;
    }
    else{
        pop();

    }

    memory[lists[created_lists]] = _NULL;
    memory[lists[created_lists]+1] = inp;
    memory[lists[created_lists]+2] = _NULL;
}
void insertElement()
{
    if(free_list == -1){
        printf("\nFAILURE: MEMORY NOT AVAILABLE\n");
        return;
    }


    int id,inp;
    printf("\nList you want to insert in: ");
    scanf("%d",&id);
    if(id>created_lists){
        printf("\nERROR: LIST DOES NOT EXIST\n");
        return;
    }

    int free_loc = free_list;
    if(memory[free_list+1] == _NULL){
        free_list = -1;
    }
    else{
        pop();

    }
    
    printf("\nEnter the key value: ");
    scanf("%d",&inp);
    
    if(lists[id]==-1){
        lists[id]=free_loc;
        memory[free_loc] = _NULL;
        memory[free_loc+1] = inp;
        memory[free_loc+2] = _NULL;
        printf("\nSUCCESS\n");
        return;
    }

    int prev = lists[id];
    int ptr = memory[prev+2];
    if(inp<memory[prev+1]){
        memory[free_loc]=_NULL;
        memory[free_loc+1]=inp;
        memory[free_loc+2]=prev;
        memory[prev]=free_loc;
        lists[id] = free_loc;
        printf("\nSUCCESS\n");
        return;
    }

    while(ptr!=_NULL)
    {
        if(inp<memory[ptr+1]){
            memory[prev+2] = free_loc;
            memory[free_loc] = prev;
            memory[free_loc+1] = inp;
            memory[free_loc+2] = ptr;
            memory[ptr] = free_loc;
            printf("\nSUCCESS\n");
            return;
        }
        prev = ptr;
        ptr = memory[ptr+2];
    }

    memory[prev+2] = free_loc;
    memory[free_loc] = prev;
    memory[free_loc+1] = inp;
    memory[free_loc+2] = _NULL;

}
void deleteElement()
{
    int id,inp;
    printf("\nList you want to delete from: ");
    scanf("%d",&id);
    printf("\nEnter the key value: ");
    scanf("%d",&inp);

    if(lists[id] ==-1)
        printf("\nERROR: SELECTED LIST IS EMPTY\n");

    int ptr=lists[id];
    if(inp == memory[ptr+1] && memory[ptr+2]==_NULL){
        lists[id]=-1;
        push(ptr);
        printf("\nSUCCESS\n");
        return;
    }

    while(ptr!=_NULL && inp>=memory[ptr+1])
    {
        if(inp==memory[ptr+1]){
            int prev = memory[ptr];
            int next = memory[ptr+2]; 
            memory[prev+2] = next;
            memory[next] = prev;
            push(ptr);
            printf("\nSUCCESS\n");
            return;
        }
        ptr = memory[ptr+2];
    }
    printf("\nFAILURE: ELEMENT NOT FOUND\n");
}
void countElements()
{
    int count = 0;
    if(created_lists == -1){
        printf("\nERROR: NO LISTS EXIST");
        return;
    }
    for(int i =0;i<5;i++)
    {
        if(lists[i] ==-1)
            continue;

        int ptr = lists[i];
        
        while(ptr!=_NULL)
        {
            count++;
            ptr = memory[ptr+2];
        }
        
    }

    printf("\nTotal number of nodes in all lists are %d\n", count);
}
void countListElements()
{
    int count =0,id;
    printf("\nEnter the list number: ");
    scanf("%d",&id);

    if(lists[id]==-1){
        printf("\nERROR: SELECTED LIST IS EMPTY");
        return;
    }
    
    int ptr = lists[id];
    while(ptr!=_NULL)
    {
        count++;
        ptr = memory[ptr+2];
    }

    printf("\nTotal number of nodes in list %d are %d\n", id,count);
}
void displayLists()
{  
    if(created_lists == -1){
        printf("\nERROR: NO LISTS EXIST");
        return;
    }
    for(int i =0;i<5;i++)
    {
        if(lists[i] ==-1)
            continue;
        
        printf("\nElements in list-%d are:\n",i);
        printf("key\tnext\tprev\n");
        int ptr = lists[i];
        
        do
        {
            printf("%d\t%d\t%d\n",memory[ptr+1],memory[ptr+2],memory[ptr]);
            ptr = memory[ptr+2];
        }while(ptr!=_NULL);
        
    }


}
void displayFreeList()
{
    if(free_list==-1){
        printf("\nERROR: MEMORY FULL");
        return;
    }
    int ptr = free_list;
    printf("[");
    do{
        printf("%d,",ptr);
        ptr = memory[ptr+1];
    }while(ptr!=_NULL);
    printf("]\n");
}
void defrag()
{

}