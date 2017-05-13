
/*
    Description: Header file that describes the ProductBook ADT.
*/

#ifndef PRODUCTBOOK_H
#define PRODUCTBOOK_H

typedef struct productBook ProductBook;

struct productBook{

    char* title; // book title
    int stock; // books in stock
};


ProductBook* createProductBook(char* title, int stock);
void destroyProductBook(ProductBook* book);
int productBookIsEqual(ProductBook* book1, ProductBook* book2);

#endif
