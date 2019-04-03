#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node* left;
    struct node* right;
    int value;
    // int balance:2;
    int height;
}TREE;

void add(TREE* t, int a);
TREE* find(TREE* t, int a);
void del(TREE* t, int a);
