#include "BookInformation.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


BookInformation* createBookInformation(char* title, int ISBN, char* author){

	BookInformation* result = malloc(sizeof(BookInformation));


    result->title = malloc(sizeof(char)*strlen(title)+1);
    result->author = malloc(sizeof(char)*strlen(author)+1);


    strcpy(result->title, title);
    strcpy(result->author, author);
    result->ISBN = ISBN;

    return result;

}

void destroyBookInformation(BookInformation* bookInformation){
    free(bookInformation->title);
    free(bookInformation->author);
    free(bookInformation);
}

/*
    Function: bookInformationIsEqual
    Description: determines whether the 2 book infos are equal or not.

    Returns: 1 if TRUE, 0 if FALSE.
*/

int bookInformationIsEqual(BookInformation* bookInformation1, BookInformation* bookInformation2){
    if(bookInformation1->ISBN == bookInformation2->ISBN) return 1;
    return 0;
}

