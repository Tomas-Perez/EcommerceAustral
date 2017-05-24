#ifndef ECOMMERCEAUSTRAL_CART_H
#define ECOMMERCEAUSTRAL_CART_H

#include <stdlib.h>
#include <string.h>
#include "ProductBook.h"

/*
 * Description: Header file that describes the Cart ADT
 */
typedef struct Cart{
    int value; // value of all books in the cart
    ProductBook** pBooks; // array of books
    int maxCapacity; // maximum amount of books
    int amountOfBooks; // amount of books in the cart
    int id; //id to identify purchases
}Cart;

Cart* createCart(int initialCapacity, int id);
void destroyCart(Cart* cart);
void cartAddBook(Cart *cart, ProductBook *pBook, int amount);
void cartRemoveBook(Cart *cart, ProductBook *pBook, int amount);
void cartRemoveAllBooks(Cart *cart);
int cartContainsBook(Cart *cart, ProductBook *pBook);


#endif //ECOMMERCEAUSTRAL_CART_H
