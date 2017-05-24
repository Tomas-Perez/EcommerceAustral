
/*
  Description: C file which implements the function prototypes defined in StaticStack.h

*/

#include "StaticStack.h"
#include <stdlib.h>

/*
    Function: createStaticStack
    Description: allocates a Stack in memory.
    Parameters: integer representing the initial capacity of the Stack.
    Returns: pointer pointing the used memory address
*/

StaticStack* createStaticStack(int initialCapacity){
  StaticStack* result = malloc(sizeof(StaticStack));
  result->array = malloc(sizeof(int)*initialCapacity);
  result->top = 0;
  result->capacity = initialCapacity;
  return result;
}

/*
    Function: destroyStaticStack
    Description: frees a Stack in memory.
    Parameters: StaticStack pointer
    Returns: -
*/

void destroyStaticStack(StaticStack* stack){
  free(stack->array);
  free(stack);
}

/*
    Function: size
    Description: returns the size of the Stack
    Parameters: StaticStack pointer
    Returns: integer representing the size of the Stack.
*/

int size(StaticStack* stack){
  return stack->top;
}

/*
    Function: isEmpty
    Description: determines wether a Stack is empty or not.
    Parameters: StaticStack pointer
    Returns: 1 if TRUE, 0 if FALSE.
*/

int isEmpty(StaticStack* stack){
  if(stack->top == 0) return 1;
  return 0;
}

static void grow(Stack* stack){
  stack->capacity = stack->capacity*2;
  stack->array = realloc(stack->array, sizeof(int)*stack->capacity*2);
}

/*
    Function: push
    Description: adds an item on top of the Stack.
    Parameters: StaticStak pointer, int toPush.
    Returns: -
*/

void push(StaticStack* stack, int toPush){
  if(stack->top == stack->capacity) grow(stack);
  stack->array[stack->top] = toPush;
  stack->top++;
}

/*
    Function: pop
    Description: takes an item from the top of the Stack. If the Stack is empty,
    the program exits.
    Parameters: StaticStack pointer.
    Returns: integer from the top of the Stack.
*/

int pop(StaticStack* stack){
  if(isEmpty()) exit(2);
  else{
    int result = stack->array[stack->top-1];
    stack->top--;
    return result;
  }
}

/*
    Function: push
    Description: shows the item at the top of the Stack. If the Stack is empty,
    the program exits.
    Parameters: StaticStack pointer.
    Returns: integer from the top of the Stack.
*/

int peek(StaticStack* stack){
  if(isEmpty()) exit(2);
  else return stack->array[stack->top-1];
}
