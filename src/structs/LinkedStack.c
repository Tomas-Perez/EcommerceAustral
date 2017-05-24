
/*
  C file which implements the function prototypes defined in LinkedStack.h
*/

#include "LinkedStack.h"
#include <stdlib.h>

/*
    Function: createLinkedStack
    Description: allocates a Stack in memory.
    Parameters: -
    Returns: pointer pointing the used memory address
*/

LinkedStack* createLinkedStack(){
    LinkedStack* result = malloc(sizeof(LinkedStack));
    result->size = 0;
    return result;
}

/*
    Function: destroyLinkedStack
    Description: frees a Stack in memory.
    Parameters: LinkedStack pointer
    Returns: -
*/

void destroyLinkedStack(LinkedStack* stack){
    for(int i = 0; i < stack->size; i++){
        Node* newTop = stack->top->next;
        freeNode(stack->top);
        stack->top = newTop;
    }
    free(stack);
}

/*
    Function: size
    Description: returns the size of the Stack
    Parameters: LinkedStack pointer
    Returns: integer representing the size of the Stack.
*/

int size(LinkedStack* stack){
    return stack->size;
}

/*
    Function: isEmpty
    Description: determines wether a Stack is empty or not.
    Parameters: LinkedStack pointer
    Returns: 1 if TRUE, 0 if FALSE.
*/

int isEmpty(LinkedStack* stack){
    if(stack->top == 0) return 1;
    return 0;
}

/*
    Function: push
    Description: adds an item on top of the Stack.
    Parameters: LinkedStack pointer, int toPush.
    Returns: -
*/

void push(LinkedStack* stack, int toPush){
    if(stack->size == 0) stack->top = createNode(toPush, NULL);
    else{
        Node* newTop = createNode(toPush, stack->top);
        stack->top = newTop;
    }
    stack->size++;
}

/*
    Function: pop
    Description: takes an item from the top of the Stack. If the Stack is empty,
    the program exits. Frees the Node removed from the Stack.
    Parameters: LinkedStack pointer.
    Returns: integer from the top of the Stack.
*/

int pop(LinkedStack* stack){
    if(isEmpty(stack)) exit(2);
    else{
        Node* top = stack->top;
        int toReturn = top->element;
        stack->top = stack->top->next;
        stack->size--;
        freeNode(top);
        return toReturn;
    }
}

/*
    Function: push
    Description: shows the item at the top of the Stack. If the Stack is empty,
    the program exits.
    Parameters: LinkedStack pointer.
    Returns: integer from the top of the Stack.
*/

int peek(LinkedStack* stack){
    if(isEmpty(stack)) exit(2);
    return stack->top->element;
}
