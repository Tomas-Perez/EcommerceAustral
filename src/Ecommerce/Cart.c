#include "Cart.h"

/*
 * Description: C file that contains the functions related to the Cart ADT
 */

/*
 * Function: cartGrow
 * Description: doubles the size of the book and spacesTaken arrays in the cart.
 * Returns: -
 */
static void cartGrow(Cart* cart){
    cart->pBooks = realloc(cart->pBooks, sizeof(ProductBook*) * (cart->maxCapacity*2));
    cart->maxCapacity *= 2;
}

/*
 * Function: createCart
 * Description: allocates memory for a cart and all it's components
 * Returns: Cart pointer
 */

Cart* createCart(int initialCapacity, int id){
    Cart* result = malloc(sizeof(Cart));
    result->id = id;
    result->value = 0;
    result->amountOfBooks = 0;
    result->maxCapacity = initialCapacity;
    result->pBooks = malloc(sizeof(ProductBook*)*initialCapacity);
    return result;
}

/*
 *  Function: destroyCart
 *  Description: frees all allocated memory related to Cart.
 *  Returns: -
*/

void destroyCart(Cart* cart){
    for(int i = 0; i < cart->amountOfBooks; i++){
        destroyProductBook(cart->pBooks[i]);
    }
    free(cart->pBooks);
    free(cart);
}

/*
 *  Function: cartAddBook
 *  Description: adds a specified amount of a given ProductBook to the cart.
 *      A ProductBook will never be duplicated, instead if a ProductBook already exists in the cart,
 *      the function will add the specified amount to its stock in the cart.
 *      If the array is full, it resizes it, if not it inserts it in the first available
 *  spot signaled by the "spacesTaken" array.
 *  Returns: -
*/

void cartAddBook(Cart *cart, ProductBook *pBook, int amount){
    int bookIndex = cartContainsBook(cart, pBook);
    if(bookIndex == -1){
        if(cart->amountOfBooks == cart->maxCapacity){
            cartGrow(cart);
        }
        cart->pBooks[cart->amountOfBooks] = createProductBook(pBook->bookInfo, amount, pBook->price);
        cart->value += pBook->price * amount;
        cart->amountOfBooks++;
    } else {
        cart->pBooks[bookIndex]->stock += amount;
        cart->value += pBook->price * amount;
    }
}

/*
 *  Function: cartRemoveBook
 *  Description: removes a specified amount of a given ProductBook from the cart.
 *      It will only completely remove a book if its stock in the cart reaches 0 or lower.
 *  Returns: -
 */

void cartRemoveBook(Cart *cart, ProductBook *pBook, int amount){
    int bookIndex = cartContainsBook(cart, pBook);
    if(bookIndex != -1){
        ProductBook* cartBook = cart->pBooks[bookIndex];
        int previousStock = cartBook->stock;
        cartBook->stock -= amount;
        if(cartBook->stock <= 0){
            destroyProductBook(cartBook);
            for(int i = bookIndex; i < cart->amountOfBooks - 1; i++){
                cart->pBooks[i] = cart->pBooks[i+1];
            }
            cart->value -= pBook->price * previousStock;
            cart->amountOfBooks--;
        } else {
            cart->value -= pBook->price * amount;
        }
    }
}



/*
 * Function: cartContainsBook
 * Description: searches for a given book in the cart and returns its position.
 * Returns: index of the given book, -1 if the book it's not present in the cart.
 */
int cartContainsBook(Cart *cart, ProductBook *pBook){
    for(int i = 0; i < cart->amountOfBooks; i++){
        if(productBookIsEqual(cart->pBooks[i], pBook)){
            return i;
        }
    }
    return -1;
}

/*
 * Function: cartRemoveAllBooks
 * Description: removes all books from the cart.
 * Returns: -
 */

void cartRemoveAllBooks(Cart *cart){
    for(int i = 0; i < cart->amountOfBooks; i++){
        destroyProductBook(cart->pBooks[i]);
    }
    cart->amountOfBooks = 0;
    cart->value = 0;
}