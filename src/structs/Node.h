
/*
  Header file that defines the Node ADT. Used in dynamic data structures like
  Linked Stacks and Linked Queues.
*/

#ifndef NODE_H
#define NODE_H

typedef struct node Node;

/* ~~~ Struct ~~~ */

struct node{

  int element;
  Node* next;
};

/* ~~~ Function Prototypes ~~~ */

Node* createNode(int element, Node* next);
void freeNode(Node* node);

#endif /* NODE_H*/
