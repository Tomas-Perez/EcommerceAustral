/*
    Description: C file that contains the functions related to the ProductBook ADT.
*/

#include "ProductBook.h"
#include <stdlib.h>
#include <string.h>

/*
    Function: createProductBook
    Description: allocates memory for a book and all it's components.
    Returns: ProductBook pointer
*/

ProductBook* createProductBook(char* title, int stock){

	ProductBook* result = malloc(sizeof(ProductBook)); // allocate memory for the book

    /*
        memory is allocated for each of the variables in ProductBook.
    */
    result->title = malloc(sizeof(char)*strlen(title));
   // result->stock = malloc(sizeof(int));

    /*
     parameters are then stored
     * */
    strcpy(result->title, title);
    result->stock = stock;

    return result;

}

/*
    Function: productBookIsEqual
    Description: determines whether the 2 ProductBook are equal or not. Used the
    strcmp function to compare the title strings of each of the books.

        The strcmp function is located in string.h and return 0 if the 2 strings
    are equal, -1 if the first is smaller than the second and 1 if the first is
    bigger than the second.

    Returns: 1 if TRUE, 0 if FALSE.
*/

int productBookIsEqual(ProductBook* productBook1, ProductBook* productBook2){
    if(strcmp(productBook1->title, productBook2->title) == 0) return 1;
    return 0;
}

/*
    Function: destroyProductBook
    Description: frees all allocated memory related to ProductBook.
    Returns: -
*/

void destroyProductBook(ProductBook* book){
    free(book->title);
    free(book);
}
