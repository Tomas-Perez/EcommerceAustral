//
// Created by tomi on 27/02/17.
//

#include "DoubleNode.h"
#include <stdlib.h>

DoubleNode* createDoubleNode(int element, DoubleNode* left, DoubleNode* right){

    DoubleNode* node = malloc(sizeof(DoubleNode));
    node->element = element;
    node->left = left;
    node->right = right;
    return node;
}

void freeDoubleNode(DoubleNode* doubleNode){

    free(doubleNode);
}