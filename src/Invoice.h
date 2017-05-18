#ifndef ECOMMERCEAUSTRAL_INVOICE_H
#define ECOMMERCEAUSTRAL_INVOICE_H

#include <sys/types.h>
#include "Student.h"
#include "ProductBook.h"
#include "Cart.h"

/*
 * Description: Header file that describes the Invoice ADT
 */

typedef struct Invoice{
    int totalAmount; // Final price
    long unixTime; //Struct containing the unixTime the invoice was created, used for comparing invoices
    char* date;  // String containing the date the invoice was created
    Student* student; // Student making the purchase
    ProductBook** pBooks; // List of books in the invoice
    int amountOfBooks; // amount of books
    int id; //id to identify purchases
}Invoice;

Invoice* createInvoice(Cart* cart, Student* student);
void destroyInvoice(Invoice* invoice);
int compareInvoiceDate(Invoice *invoice1, Invoice *invoice2);

#endif //ECOMMERCEAUSTRAL_INVOICE_H
