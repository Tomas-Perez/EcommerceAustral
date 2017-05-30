
/*
    Description: Header file that describes the ProductBook ADT.
*/

#ifndef PRODUCTBOOK_H
#define PRODUCTBOOK_H

#include "../College/BookInformation.h"

typedef struct productBook ProductBook;

struct productBook{
    BookInformation* bookInfo; // book information
    int stock; // books in stock
    int price; // book price
};


ProductBook* createProductBook(BookInformation* bookInfo, int stock, int price);
void destroyProductBook(ProductBook* book);
int productBookIsEqual(ProductBook* book1, ProductBook* book2);

#endif
