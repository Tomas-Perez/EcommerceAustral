
/*
    Description: C file that contains the functions prototyped in LinkedList.h

        This implementation of the Linked List uses 2 Centinel Nodes, one in the
    front and one in the back to solve certain difficulties present when neither
    of these nodes exist.

*/


#include "LinkedList.h"
#include <stdlib.h> /* manage memory dinamically */

/*
    Function: createLinkedList
    - Description: allocates a Linked List in memory.
    - Parameters: -
    - Returns: pointer referencing the memory address used.
*/

LinkedList* createLinkedList(){

    LinkedList* list = malloc(sizeof(LinkedList));
    list->size = 0;
    list->position = -1;
    list->first = createDoubleNode(0, NULL, list->last);
    list->last = createDoubleNode(0, list->first, NULL);
    list->current = NULL;
    return list;
}

/*
    Function: freeLinkedList
    - Description: frees a Linked List from memory.
    - Parameters: LinkedList pointer.
    - Returns: -
*/

void freeLinkedList(LinkedList* list){

    int size = list->size;
    goFirst(list);
    for(int i = 0;i < size;i++){
        removeS(list);
    }

    freeDoubleNode(list->first);
    freeDoubleNode(list->last);
    free(list);
}

/*
    Function: size
    - Description: returns the amount of items (size) contained in the Linked List
    - Parameters: LinkedList pointer.
    - Returns: integer representing the Linked List's size.
*/

int size(LinkedList* list){

    return list->size;
}

/*
    Function: isEmpty
    - Description: determines wether a Linked List is empty or not.
    - Parameters: Linked List pointer
    - Returns: 1 if condition is TRUE, 0 if condition is FALSE.
*/

int isEmpty(LinkedList* list){

    if(list->size == 0) return 1;
    return 0;
}

/*
    Function: forward
    - Description: moves the current view one place forward
    - Parameters: LinkedList pointer.
    - Returns: -
*/

void forward(LinkedList* list){

    if(list->size != 0 && list->current->right != list->last){
        list->current = list->current->right;
    }
}

/*
    Function: backwards
    - Description: moves the current view one place backward.
    - Parameters: LinkedList pointer.
    - Returns: -
*/

void backwards(LinkedList* list){

    if(list->size != 0 && list->current->left != list->first){
        list->current = list->current->left;
    }
}

/*
    Function: getActual
    - Description: returns the item currently in view.
    - Parameters: LinkedList pointer.
    - Returns: an integer (depends on what the list is holding)
*/

int getActual(LinkedList* list){

    if(isEmpty(list)) exit(2); /* if the Linked List is empty, nothing can be returned*/
    return list->current->element;
}

/*
    Function: getPosition
    - Description: returns the position in the Linked List of the current view.
    - Parameters: LinkedList pointer.
    - Returns: an integer representing the position.
*/

int getPosition(LinkedList* list){

    if(isEmpty(list)) return -1;
    return list->position;
}

/*
    Function: goFirst
    - Description: sets the current view in the first place of the Linked List
    The Linked List must have a size > 0 else, it does nothing..
    - Parameters: LinkedList pointer.
    - Returns: -
*/

void goFirst(LinkedList* list){

    if(list->size != 0){
        list->current = list->first->right;
    }
}

/*
    Function: goBack
    - Description: sets the current view in the last place of the Linked List.
    The Linked List must have a size > 0 else, it does nothing.
    - Parameters: LinkedList pointer.
    - Returns: -
*/

void goBack(LinkedList* list){

    if(list->size != 0){
        list->current = list->last->left;
    }
}

/*
    Function: goTo
    - Description: moves the current view to the desired position in the Linked List.
    The position wished must be smaller than the List's size.
    - Parameters: LinkedList pointer, integer position.
    - Returns: -
*/

void goTo(LinkedList* list, int positionToGo){

    if(positionToGo >= list->size){
        while(list->position != positionToGo){
            if(list->position < positionToGo){
                forward(list);
            }else{
                backwards(list);
            }
        }
    }
}

/*
    ~~~ Static Function ~~~
    Function: addWhenEmpty
    - Description: adds an item to the List. It is only used if the Linked List's
    size == 0.
    - Parameters: LinkedList pointer, integer toAdd.
    - Returns: -
*/

static void addWhenEmpty(LinkedList* list, int toAdd){
    DoubleNode* add = createDoubleNode(toAdd, list->first, list->last);
    list->last->left = add;
    list->first->right = add;
    list->current = add;
}

/*
    Function: addNext
    - Description: adds an item in the Linked List next to the one in the current
    view. The current view is not changed..
    - Parameters: LinkedList pointer, integer toAdd.
    - Returns: -
*/

void addNext(LinkedList* list, int toAdd){

    if(isEmpty(list)){
        addWhenEmpty(list, toAdd);
    }else {
        DoubleNode *newRight = list->current->right;
        DoubleNode *add = createDoubleNode(toAdd, list->current, newRight);
        list->current->right = add;
        newRight->left = add;
    }
    list->size++;
}

/*
    Function: addBefore
    - Description: adds an item to the Linked List before the one in the current
    vew. The current view is not changed.
    - Parameters: LinkedList pointer, int toAdd.
    - Returns: -
*/

void addBefore(LinkedList* list, int toAdd){

    if(isEmpty(list)){
        addWhenEmpty(list, toAdd);
    }else {
        DoubleNode *newLeft = list->current->left;
        DoubleNode *add = createDoubleNode(toAdd, newLeft, list->current);
        list->current->left = add;
        newLeft->right = add;
    }
    list->size++;
}

/*
    Function: removeS
    - Description: removes the item curently in view. The current view will shift
    right or left depending which one is available. If the two options are available,
    the current view will shift to the right. Frees the removed DoubleNode
    from memory.
    - Parameters: LinkedList pointer.
    - Returns: integer with the current view.
*/

int removeS(LinkedList* list){

    if(isEmpty(list)){
        exit(2);
    }else{
        DoubleNode* before = list->current->left;
        DoubleNode* after = list->current->right;
        int toReturn = list->current->element;
        before->right = after;
        after->left = before;
        freeDoubleNode(list->current);
        list->size--;
        if(isEmpty(list)) list->current = list->first;
        else if(after != list->last) list->current = after;
        else list->current = before;
    }
}
