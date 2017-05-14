#include "Cart.h"

Cart* createCart(int initialCapacity){
    Cart* result = malloc(sizeof(Cart));
    result->value = 0;
    result->amountOfBooks = 0;
    result->maxCapacity = initialCapacity;
    result->pBooks = malloc(sizeof(ProductBook*)*initialCapacity);
    result->spacesTaken = malloc(sizeof(int)*initialCapacity);
    memset(result->spacesTaken, 0, sizeof(int)*initialCapacity);
}

void destroyCart(Cart* cart){
    for(int i = 0; i < cart->maxCapacity; i++){
        if(cart->spacesTaken[i]) destroyProductBook(cart->pBooks[i]);
    }
    free(cart->pBooks);
    free(cart->spacesTaken);
    free(cart);
}

void cartAddBook(Cart *cart, ProductBook *pBook, int amount){
    int bookIndex = cartContainsBook(cart, pBook);
    if(bookIndex == -1){
        if(cart->amountOfBooks == cart->maxCapacity){
            cartGrow(cart);
            cart->pBooks[cart->maxCapacity] = createProductBook(pBook->title, amount, pBook->price);
            cart->value += pBook->price * amount;
            cart->spacesTaken[cart->maxCapacity] = 1;
        } else {
            for(int i = 0; i < cart->maxCapacity; i++){
                if(!cart->spacesTaken[i]){
                    cart->pBooks[i] = createProductBook(pBook->title, amount, pBook->price);
                    cart->spacesTaken[i] = 1;
                    cart->value += pBook->price * amount;
                    break;
                }
            }
        }
    } else {
        cart->pBooks[bookIndex]->stock += amount;
        cart->value += pBook->price * amount;
    }
    cart->amountOfBooks++;
}

void cartRemoveBook(Cart *cart, ProductBook *pBook, int amount){
    int bookIndex = cartContainsBook(cart, pBook);
    if(bookIndex != -1){
        ProductBook* cartBook = cart->pBooks[bookIndex];
        int previousStock = cartBook->stock;
        cartBook->stock -= amount;
        if(cartBook->stock <= 0){
            cart->spacesTaken[bookIndex] = 0;
            destroyProductBook(cartBook);
            cart->value -= pBook->price * previousStock;
            cart->amountOfBooks--;
        } else {
            cart->value -= pBook->price * amount;
        }
    }
}

void cartGrow(Cart* cart){
    int cartCapacity = cart->maxCapacity;
    cart->maxCapacity = cartCapacity*2;
    cart->pBooks = realloc(cart->pBooks, sizeof(ProductBook*)*(cart->maxCapacity));
    cart->spacesTaken = realloc(cart->spacesTaken, sizeof(int)*(cart->maxCapacity));
    for(int i = cartCapacity; i < cart->maxCapacity; i++){
        cart->spacesTaken[i] = 0;
    }
}

int cartContainsBook(Cart *cart, ProductBook *pBook){
    for(int i = 0; i < cart->maxCapacity; i++){
        if(cart->spacesTaken[i]){
            if(productBookIsEqual(cart->pBooks[i], pBook)){
                return i;
            }
        }
    }
    return -1;
}