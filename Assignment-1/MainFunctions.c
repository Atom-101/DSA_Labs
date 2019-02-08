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

    //Head of new created list is current head of free
    lists[created_lists] = free_list;
    
    //If the last element of free_list is reached, make free_list=-1
    //else pop it
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

    //Pop free_list stack
    int free_loc = free_list;
    if(memory[free_list+1] == _NULL){
        free_list = -1;
    }
    else{
        pop();

    }
    
    printf("\nEnter the key value: ");
    scanf("%d",&inp);
    
    //Insert into empty list
    if(lists[id]==-1){
        lists[id]=free_loc;
        memory[free_loc] = _NULL;
        memory[free_loc+1] = inp;
        memory[free_loc+2] = _NULL;
        printf("\nSUCCESS\n");
        return;
    }

    //Insert as first element of list
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

    //Insert within list
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

    //Insert as last elemnet of list
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

    //Empty list
    if(lists[id] ==-1)
        printf("\nERROR: SELECTED LIST IS EMPTY\n");

    //Check whether list has only 1 element or
    //if the first element of list is to be deleted
    int ptr=lists[id];
    if(inp == memory[ptr+1]){
        if(memory[ptr+2]==_NULL){
            lists[id]=-1;
            push(ptr);
            printf("\nSUCCESS\n");
            return;
        }
        else{
            lists[id] = memory[ptr+2];
            memory[memory[ptr+2]] = _NULL;
            push(ptr);
            printf("\nSUCCESS\n");
            return;
        }
    }

    //Traverse list to find element in sorted list
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
    //Iterate over all generated non empty lists and count their elements
    int count = 0;
    if(created_lists == -1){
        printf("\nERROR: NO LISTS EXIST");
        return;
    }
    for(int i =0;i<5;i++)
    {
        //List empty or not created
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
    //Take a list index as input and count the number of elements in it
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
    //Iterate over lists and display contents of each list
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
    while(ptr!=_NULL)
    {
        if(memory[ptr+1]!=_NULL)
            printf("%d,",ptr);
        else
            printf("%d",ptr);
        ptr = memory[ptr+1];
    }
    printf("]\n");
}
void defrag()
{
    // for(int i=2;i<50*3;i+=3)
    // {
    //     if(memory[i] ==_FREE_FLAG)
    //     {
    //         int j = i+3;
    //         for(;memory[j]==_FREE_FLAG && j<50*3;j+=3);
    //         if(j>=50*3){
    //             printf("\nSUCCESS\n");
    //             generateFreeList();
    //             return;
    //         }
    //         //move
    //         //copy to new loc
    //         memory[i-2] = memory[j-2];
    //         memory[i-1] = memory[j-1];
    //         memory[i] = memory[j];
    //         //change addresses
    //         if(memory[i-2]!=_NULL){
    //             int prev = memory[i-2];
    //             memory[prev+2] = i-2;
    //         }
    //         if(memory[i]!=_NULL){
    //             int next = memory[i];
    //             memory[next] = i-2;
    //         }
    //         //reset list head
    //         if(memory[i-2]==_NULL){
    //             for(int k=0; k<created_lists;k++){
    //                 if(lists[k]==j-2){
    //                     lists[k] = i-2;
    //                     break;
    //                 }
    //             }
    //         }
    //         //apply free flag to previous loc
    //         memory[j] = _FREE_FLAG;
    //     }
    // }
    
    
    //Declare a new memory and populate it with
    //defragmented version of old memory
    int memory1[50*3];
    for(int i=0;i<150;i++)
        memory1[i]= memory[i];
    for(int i=0;i<150;i++)
        memory[i] = 0;
    int free_loc;
    generateFreeList();
    displayFreeList();
    for(int i = 0;i<=created_lists;i++){
        int ptr = lists[i];
        if(lists[i]==-1)
            continue;
        int top_new;
        free_loc = free_list;
        pop();

        memory[free_loc+1] = memory1[ptr+1];
        memory[free_loc] = _NULL;
        memory[free_loc+2] = _NULL;
        lists[i] = free_loc;
        top_new = free_loc;
        
        ptr = memory1[ptr+2];

        while(ptr!=_NULL){
            free_loc = free_list;
            pop();
            memory[top_new+2] = free_loc;
            memory[free_loc] = top_new;
            memory[free_loc+1] = memory1[ptr+1];
            memory[free_loc+2] = _NULL;
            
            top_new = free_loc;
            ptr = memory1[ptr+2];
        }
    }
    printf("\nSUCCESS\n");
}