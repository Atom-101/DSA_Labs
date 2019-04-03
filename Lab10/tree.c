#include "tree.h"

void add(TREE* t, int a){
    if(t->left != NULL && t->value>a){
        add(t->left,a);
    }
    else if(t->right != NULL && t->value<a){
        add(t->right,a);
    }

    t->height++;
    if((t->left->height)-(t->right->height)>=2){
        rotate(t,)
    }
    
}
TREE* find(TREE* t, int a);
void del(TREE* t, int a);