/*
    Description: C file that contains the functions related to the ProductBook ADT.
*/

#include "ProductBook.h"
#include <stdlib.h>
/*
    Function: createProductBook
    Description: allocates memory for a book and all it's components.
    Returns: ProductBook pointer
*/

ProductBook* createProductBook(BookInformation* bookInfo, int stock, int price){

	ProductBook* result = malloc(sizeof(ProductBook)); // allocate memory for the book

    /*
        memory is allocated for each of the variables in ProductBook.
    */
    result->bookInfo = malloc(sizeof(BookInformation*));
    result->bookInfo = bookInfo;

    /*
     parameters are then stored
     * */
    result->stock = stock;
    result->price = price;

    return result;

}

/*
    Function: productBookIsEqual
    Description: determines whether the 2 ProductBook are equal or not, by comparing their BookInformation.
    Returns: 1 if TRUE, 0 if FALSE.
*/

int productBookIsEqual(ProductBook* productBook1, ProductBook* productBook2){
    if(bookInformationIsEqual(productBook1->bookInfo, productBook2->bookInfo)) return 1;
    return 0;
}

/*
    Function: destroyProductBook
    Description: frees all allocated memory related to ProductBook.
    Returns: -
*/

void destroyProductBook(ProductBook* book){
    destroyBookInformation(book->bookInfo);
    free(book->bookInfo);
    free(book);
}
