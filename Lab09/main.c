#include "hash.h"
#include "parser.h"

int main(){
    FILE* fp = fopen("aliceinwonderland.txt","r");
    char* strings[30000];
    int size = 30000;
    for(int i=0;i<30000;i++){
        strings[i] = malloc(100 * sizeof(char));
    }

    parseFile(fp,strings,size);

    int c = collisionCount(strings,size,5003,5000);
  
}
