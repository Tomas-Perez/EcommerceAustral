#include <stdio.h>
#include "CUTest/CuTest.h"
#include "../src/Ecommerce/ProductBook.h"
#include "../src/Ecommerce/Cart.h"

void TestCartAddBook(CuTest *tc){
    BookInformation* information = createBookInformation("Math", 51566, "Euler");
    ProductBook* book = createProductBook(information, 10, 0);
    Cart* cart = createCart(1, 1);

    cartAddBook(cart, book, 5);
    CuAssertIntEquals(tc, 1, cart->amountOfBooks);

    cartAddBook(cart, book, 2);
    CuAssertIntEquals(tc, 1, cart->amountOfBooks);

}

void TestCartRemoveBook(CuTest *tc){
    BookInformation* information = createBookInformation("Math", 51566, "Euler");
    ProductBook* book = createProductBook(information, 10, 0);
    Cart* cart = createCart(1, 1);
    cartAddBook(cart, book, 5);
    CuAssertIntEquals(tc, 1, cart->amountOfBooks);

    cartRemoveBook(cart, book, 3);
    CuAssertIntEquals(tc, 1, cart->amountOfBooks);

    ProductBook* cartMathBook = cart->pBooks[0];
    CuAssertIntEquals(tc, 2, cartMathBook->stock);

    cartRemoveBook(cart, book, 2);
    CuAssertIntEquals(tc, 0, cart->amountOfBooks);
}

void TestCartRemoveAllBooks(CuTest *tc){
    BookInformation* information1 = createBookInformation("Math", 1245, "Euler");
    ProductBook* book1 = createProductBook(information1, 10, 0);
    BookInformation* information2 = createBookInformation("Chemistry", 3453, "Someone Else");
    ProductBook* book2 = createProductBook(information2, 6, 0);
    BookInformation* information3 = createBookInformation("Statistics", 12345, "Flash");
    ProductBook* book3 = createProductBook(information3, 8, 0);

    Cart* cart = createCart(1, 1);
    cartAddBook(cart, book1, 5);
    cartAddBook(cart, book2, 5);
    cartAddBook(cart, book3, 5);

    CuAssertIntEquals(tc, 3, cart->amountOfBooks);

    int actual1 = cartContainsBook(cart, book1);
    int actual2 = cartContainsBook(cart, book2);
    int actual3 = cartContainsBook(cart, book3);

    CuAssertIntEquals(tc, 0, actual1);
    CuAssertIntEquals(tc, 1, actual2);
    CuAssertIntEquals(tc, 2, actual3);


    cartRemoveAllBooks(cart);
    CuAssertIntEquals(tc, 0, cart->amountOfBooks);

    actual1 = cartContainsBook(cart, book1);
    actual2 = cartContainsBook(cart, book2);
    actual3 = cartContainsBook(cart, book3);

    CuAssertIntEquals(tc, -1, actual1);
    CuAssertIntEquals(tc, -1, actual2);
    CuAssertIntEquals(tc, -1, actual3);
}

void TestCartContainsBook(CuTest *tc) {
    BookInformation* information = createBookInformation("Math", 43541, "Euler");
    ProductBook* book = createProductBook(information, 10, 0);
    Cart* cart = createCart(1, 1);
    int actual = cartContainsBook(cart, book);
    CuAssertIntEquals(tc, -1, actual);

    cartAddBook(cart, book, 2);
    actual = cartContainsBook(cart, book);
    CuAssertIntEquals(tc, 0, actual);
}

CuSuite* GetCartTestSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestCartContainsBook);
    SUITE_ADD_TEST(suite, TestCartAddBook);
    SUITE_ADD_TEST(suite, TestCartRemoveBook);
    SUITE_ADD_TEST(suite, TestCartRemoveAllBooks);

    return suite;
}