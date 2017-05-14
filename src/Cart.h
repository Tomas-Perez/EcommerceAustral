#ifndef ECOMMERCEAUSTRAL_CART_H
#define ECOMMERCEAUSTRAL_CART_H

#include <malloc.h>
#include <mem.h>
#include "ProductBook.h"

typedef struct Cart{
    int value;
    ProductBook** pBooks;
    int maxCapacity;
    int* spacesTaken;
    int amountOfBooks;
}Cart;

Cart* createCart(int initialCapacity);
void destroyCart(Cart* cart);
void cartAddBook(Cart *cart, ProductBook *pBook, int amount);
void cartRemoveBook(Cart *cart, ProductBook *pBook, int amount);
void cartGrow(Cart* cart);
int cartContainsBook(Cart *cart, ProductBook *pBook);


#endif //ECOMMERCEAUSTRAL_CART_H
