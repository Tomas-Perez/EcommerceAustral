#ifndef ECOMMERCEAUSTRAL_CART_H
#define ECOMMERCEAUSTRAL_CART_H

#include <malloc.h>
#include <mem.h>
#include "ProductBook.h"

/*
 * Description: Header file that describes the Cart ADT
 */
typedef struct Cart{
    int value; // value of all books in the cart
    ProductBook** pBooks; // array of books
    int maxCapacity; // maximum amount of books
    int* spacesTaken; // boolean array that mirrors the pBooks array, 0 means the pBooks index is empty, 1 means its full
    int amountOfBooks; // amount of books in the cart
}Cart;

Cart* createCart(int initialCapacity);
void destroyCart(Cart* cart);
void cartAddBook(Cart *cart, ProductBook *pBook, int amount);
void cartRemoveBook(Cart *cart, ProductBook *pBook, int amount);
void cartRemoveAllBooks(Cart *cart);
void cartGrow(Cart* cart);
int cartContainsBook(Cart *cart, ProductBook *pBook);


#endif //ECOMMERCEAUSTRAL_CART_H
