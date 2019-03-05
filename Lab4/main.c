#include "List.h"
#include "cycle.h"

int main(){
    List* Ls = createList(20);
    createCycle(Ls);

    // testCyclic(Ls);
    makeCircularList(Ls);

    return 0;
}