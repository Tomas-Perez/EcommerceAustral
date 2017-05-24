//
// Created by tomi on 27/02/17.
//

#ifndef STRUCTURES_DOUBLENODE_H
#define STRUCTURES_DOUBLENODE_H

typedef struct doubleNode DoubleNode;

/* ~~~ Structs ~~~ */

struct doubleNode{

    DoubleNode* left;
    DoubleNode* right;
    int element;
};

/* ~~~ Function Prototypes ~~~ */

DoubleNode* createDoubleNode(int element, DoubleNode* left, DoubleNode* right);
void freeDoubleNode(DoubleNode* node);

#endif //STRUCTURES_DOUBLENODE_H
