
/*
  .c file which implements the function prototypes defined in Node.h
*/


#include "Node.h"
#include <stdlib.h>

/*
  createNode(): allocates a Node in memory and return a pointer to said Node.
*/
Node* createNode(int element, Node* next){

    Node* result = malloc(sizeof(Node));
    result->element = element;
    result->next = next;
    return result;
}


/*
    freeNode(): deallocates the Node from memory.
*/

void freeNode(Node* node){

    free(node);
}
