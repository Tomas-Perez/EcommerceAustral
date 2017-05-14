#ifndef ECOMMERCEAUSTRAL_INVOICE_H
#define ECOMMERCEAUSTRAL_INVOICE_H

#include "Student.h"
#include "ProductBook.h"
#include "Cart.h"

typedef struct Invoice{
    int totalAmount;
    char* date;
    Student* student;
    ProductBook** pBooks;
    int amountOfBooks;
}Invoice;

Invoice* createInvoice(Cart* cart, Student* student);
void destroyInvoice(Invoice* invoice);

#endif //ECOMMERCEAUSTRAL_INVOICE_H
