#include "BookInformation.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


BookInformation* createBookInformation(char* title, char* ISBN, char* author){

	BookInformation* result = malloc(sizeof(BookInformation));


    result->title = malloc(sizeof(char)*strlen(title));
    result->ISBN = malloc(sizeof(char)*strlen(ISBN));
    result->author = malloc(sizeof(char)*strlen(author));


    strcpy(result->title, title);
    strcpy(result->ISBN, ISBN);
    strcpy(result->author, author);

    return result;

}

void destroyBookInformation(BookInformation* bookInformation){
    free(bookInformation->title);
    free(bookInformation->ISBN);
    free(bookInformation->author);
    free(bookInformation);
}

/*
    Function: bookInformationIsEqual
    Description: determines whether the 2 book infos are equal or not. Used the
    strcmp function to compare the ISBN strings of each of the book infos.

        The strcmp function is located in string.h and return 0 if the 2 strings
    are equal, -1 if the first is smaller than the second and 1 if the first is
    bigger than the second.

    Returns: 1 if TRUE, 0 if FALSE.
*/

int bookInformationIsEqual(BookInformation* bookInformation1, BookInformation* bookInformation2){
    if(strcmp(bookInformation1->ISBN, bookInformation2->ISBN) == 0) return 1;
    return 0;
}

