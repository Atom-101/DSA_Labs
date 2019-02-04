#include <stdio.h>

#include "MemArray.h"
#include "MainFunctions.h"

int main()
{
    int option; initializeMemArray();
    do{
        printf("Select an option:\n1. Create a new list\n"
        "2. Insert a new element in a given list in sorted order\n"
        "3. Delete an element from a given list\n"
        "4. Count total elements excluding free list\n"
        "5. Count total elements of a list\n"
        "6. Display all list\n7. Display free list\n"
        "8. Perform defragmentation\n9. Press 0 to exit\n\n");
        scanf("%d",&option);

        switch(option){

            case 1:{ createList(); break;}
            case 2:{ insertElement(); break;}
            case 3:{ deleteElement(); break;}
            case 4:{ countElements(); break;}
            case 5:{ countListElements(); break;}
            case 6:{ displayLists(); break;}
            case 7:{ displayFreeList(); break;}
            case 8:{ defrag(); break;}
            case 0: return 0;
            default: printf("Invalid option. Please try again.\n\n");
        }

    }while(1);

}
