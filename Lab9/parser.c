#include "parser.h"

void parseFile(FILE* fptr, char* strings[], int size){
    int i=0;
    // In %*[^a-zA-Z] , '*' signifies, discard all characters that
    // are not a-z or A-Z. Then it reads a space and then the string to be stored
    while(fscanf(fptr,"%*[^a-zA-Z]%[a-zA-Z]",strings[i])!=EOF){
        // fscanf(fptr,"%[^a-zA-Z]",NULL);
        i++;
        if(i>=size)
            break;
    }

    printf("\nNumber of strings read: %d\n",i);
}