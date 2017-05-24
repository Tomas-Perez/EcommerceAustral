/*
    Header file that defines the node -  based implementation of a List
    with centinel nodes.
*/

#ifndef STRUCTURES_LINKEDLIST_H
#define STRUCTURES_LINKEDLIST_H

#include "DoubleNode.h"

typedef struct linkedList LinkedList;

/* ~~~ Structs ~~~ */

struct linkedList{

    int position; /* Keeps track of the current views relative position in the List */
    DoubleNode* current; /* Ppints to the current element in view of the List */
    DoubleNode* first; /* Centinel node */
    DoubleNode* last; /* Centinel node */
    int size; /* Keeps track of the list's size */
};

/* ~~~ Function Prototypes ~~~ */

LinkedList* createLinkedList();
void freeLinkedList(LinkedList* list);
int size(LinkedList* list);
int isEmpty(LinkedList* list);
void forward(LinkedList* list);
void backwards(LinkedList* list);
int getActual(LinkedList* list);
int getPosition(LinkedList* list);
void goFirst(LinkedList* list);
void goBack(LinkedList* list);
void goTo(LinkedList* list, int positionToGo);
void addNext(LinkedList* list, int toAdd);
void addBefore(LinkedList* list, int toAdd);
int removeS(LinkedList* list);

#endif //STRUCTURES_LINKEDLIST_H
