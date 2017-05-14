#ifndef ECOMMERCEAUSTRAL_INVOICE_H
#define ECOMMERCEAUSTRAL_INVOICE_H

#include "Student.h"
#include "ProductBook.h"
#include "Cart.h"

/*
 * Description: Header file that describes the Invoice ADT
 */

typedef struct Invoice{
    int totalAmount; // Final price
    char* date;  // String containing the date the invoice was created
    Student* student; // Student making the purchase
    ProductBook** pBooks; // List of books in the invoice
    int amountOfBooks; // amount of books
}Invoice;

Invoice* createInvoice(Cart* cart, Student* student);
void destroyInvoice(Invoice* invoice);

#endif //ECOMMERCEAUSTRAL_INVOICE_H
