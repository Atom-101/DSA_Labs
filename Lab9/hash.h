#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int hashFunction(char* string, int baseNumber, int tableSize);
int collisionCount(char* strings[], int size, int baseNumber, int tableSize);