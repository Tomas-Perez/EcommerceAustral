
/*
    Header file that defines the Stack ADT using a node - based implementation.
*/


#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "Node.h"

typedef struct linkedStack LinkedStack;

/* ~~~ Structs ~~~ */

struct linkedStack{

  Node* top; /* points to the element on top of the stack */
  int size; /* keeps track of the size of the stack */
};

/* ~~~ Function Prototypes ~~~ */

LinkedStack* createLinkedStack();
void destroyLinkedStack(LinkedStack* stack);
int isEmpty(LinkedStack* stack);
void push(LinkedStack* stack, int toPush);
int pop(LinkedStack* stack);
int peek(LinkedStack* stack);
int size(LinkedStack* stack);

#endif // LINKEDSTACK_H
