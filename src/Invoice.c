#include <malloc.h>
#include <sys/types.h>
#include <time.h>
#include "Invoice.h"

/*
 * Description: C file containing the functions related to the Invoice ADT
 */

/*
 * Function: createInvoice
 * Description: allocates memory for an Invoice and all its components.
 * Returns: Invoice pointer
 */

Invoice* createInvoice(Cart* cart, Student* student){
    Invoice* result = malloc(sizeof(Invoice));
    result->id = cart->id;
    result->totalAmount = cart->value;
    result->pBooks = malloc(sizeof(ProductBook*)*cart->amountOfBooks);
    result->amountOfBooks = cart->amountOfBooks;
    int addedBooks = 0;
    for(int i = 0; i < cart->maxCapacity, addedBooks < cart->amountOfBooks; i++){
        if(cart->spacesTaken[i]){
            ProductBook* cartBook = cart->pBooks[i];
            result->pBooks[addedBooks] = createProductBook(cartBook->title, cartBook->stock, cartBook->stock);
            addedBooks++;
        }
    }
    result->student = malloc(sizeof(Student));
    result->student = student;

    // get current date and time

    time_t t = time(NULL);
    result->tm = t;
    struct tm* tm1 = localtime(&t);
    char* tempDate = asctime(tm1);
    result->date = malloc(sizeof(char*)*strlen(tempDate));
    strcpy(result->date, tempDate);
    return result;
}

/*
 * Function: destroyInvoice
 * Description: frees all allocated memory related to Invoice
 * Returns: -
 */

void destroyInvoice(Invoice* invoice){
    for(int i = 0; i < invoice->amountOfBooks; i++){
        destroyProductBook(invoice->pBooks[i]);
    }
    free(invoice->student);
    free(invoice);
}

/*
 * Function: compareInvoiceDate
 * Description: compares two invoices by date.
 * Returns: 1 if Invoice1 > Invoice2
 *          -1 if Invoice1 < Invoice2
 *          0 if Invoice1 == Invoice2
 */
int compareInvoiceDate(Invoice *invoice1, Invoice *invoice2){
    double difference = difftime(invoice1->tm, invoice2->tm);
    if(difference > 0){
        return 1;
    }
    if(difference < 0){
        return -1;
    }
    return 0;
}