#include "hash.h"
#include <string.h>

int hashFunction(char* string, int baseNumber, int tableSize){
    int n = strlen(string);
    int hash_key = 0;
    for(int i=0;i<n;i++){
        hash_key += (int)string[i];
    }

    hash_key %= baseNumber;
    hash_key %= tableSize;
    return hash_key;
}

int collisionCount(char* strings[], int size, int baseNumber, int tableSize){
    int collision_count = 0;
    // unsigned long long int check = 0;
    // u_int64_t check = 0;
    uint64_t check[tableSize/64+1];
    for(int i=0;i<tableSize/64+1;i++){
        check[i] = 0;
    }
    FILE* fp = fopen("Debug.txt","w");
    for(int i=0;i<size;i++){
        int key = hashFunction(strings[i],baseNumber,tableSize);
        
        fprintf(fp,"\nKey-%d: %d\n",i,key);
        int id = key/64;
        int position = key%64;
        uint64_t flag = 1;
        flag = flag<<position;
        
        if(check[id] & flag)
            collision_count++;
        else
            check[id] = check[id] | flag;

        // For tableSize upto 64
        // // Check key-th bit of check
        // if((check>>key)&1){
        //     collision_count++;
        // }
        // // Flip key-th bit of check
        // else{
        //     check = check^(1<<key);
        // }
    }

    return collision_count;
}

