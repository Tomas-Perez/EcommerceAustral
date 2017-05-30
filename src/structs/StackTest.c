
/*
    Tests the static (array - based) implementation of the StaticStack.
    Could also be used with the dynamic (node - based) implementation with
    the necessary changes.
*/

#include "StaticStack.h"
#include <stdio.h>

int main(){

  StaticStack* stack = createStaticStack(10);

  if(isEmpty(stack)) printf("Stack is Empty");
  printf("\n");

  for(int i = 0;i < 20;i++){
      push(stack, i);
  }

  for(int i = 0;i < 20;i++){
      int b = pop(stack);
      printf("%d ", b);
      printf("\n");
  }

  if(isEmpty(stack)) printf("Stack is Empty");
  printf("\n");

  push(stack, 5);
  push(stack, 2);
  push(stack, 3);

  pop(stack);
  int p = peek(stack);
  printf("%d ", p);
  pop(stack);
  pop(stack);

  printf("\n");
  if(isEmpty(stack)) printf("Stack is Empty");

  return 0;
}
