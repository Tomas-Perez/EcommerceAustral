#ifndef ECOMMERCEAUSTRAL_INVOICE_H
#define ECOMMERCEAUSTRAL_INVOICE_H

#include <sys/types.h>
#include "Cart.h"

/*
 * Description: Header file that describes the Invoice ADT
 */

typedef struct Invoice{
    int totalAmount; // Final price
    long timestamp; //unixTime the invoice was created, used for comparing invoices
    char* date;  // String containing the date the invoice was created
    int studentID; // Student making the purchase
    char** bookTitles; // List of books in the invoice
    int amountOfBooks; // amount of books
    int id; //id to identify purchases
}Invoice;

Invoice* createInvoice(Cart* cart, int studentID);
void destroyInvoice(Invoice* invoice);
int compareInvoiceDate(Invoice *invoice1, Invoice *invoice2);

#endif //ECOMMERCEAUSTRAL_INVOICE_H
