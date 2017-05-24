
/*
    Header file that defines the Stack ADT using an array - based implementation.
*/

#ifndef STATICSTACK_H
#define STATICSTACK_H

typedef struct staticStack StaticStack;

/* ~~~ Structs ~~~ */

struct staticStack{

  int *array; /* stores the elements of the stack */
  int top; /* points to the next available space of the stack */
  int capacity; /* keeps track of the array's length*/

};

/* ~~~ Function Prototypes ~~~ */

StaticStack* createStaticStack(int initialCapacity);
void destroyStaticStack(StaticStack* stack);
int isEmpty(StaticStack* stack);
void push(StaticStack* stack, int toPush);
int pop(StaticStack* stack);
int peek(StaticStack* stack);
int size(StaticStack* stack);


#endif // STATICSTACK_H
