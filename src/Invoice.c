#include <stdlib.h>
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

Invoice* createInvoice(Cart* cart, int studentID){
    Invoice* result = malloc(sizeof(Invoice));
    result->id = cart->id;
    result->totalAmount = cart->value;
    result->bookTitles = malloc(sizeof(ProductBook*)*cart->amountOfBooks);
    result->amountOfBooks = cart->amountOfBooks;
    int addedBooks = 0;
    for(int i = 0; i < cart->maxCapacity, addedBooks < cart->amountOfBooks; i++){
        if(cart->spacesTaken[i]){
            ProductBook* cartBook = cart->pBooks[i];
            result->bookTitles[addedBooks] = cartBook->bookInfo->title;
            addedBooks++;
        }
    }
    result->studentID = studentID;

    // get current date and time

    time_t t = time(NULL); //returns long with unixTime
    result->timestamp = t; //stores the unixTime
    struct tm* tm1 = localtime(&t); //parse unixTime to a struct with day, hour, etc
    char* tempDate = asctime(tm1); //parse struct tm to a string
    result->date = malloc(sizeof(char*)*strlen(tempDate)+1); //allocate memory for the string
    strcpy(result->date, tempDate); //store the date string
    return result;
}

/*
 * Function: destroyInvoice
 * Description: frees all allocated memory related to Invoice
 * Returns: -
 */

void destroyInvoice(Invoice* invoice){
    for(int i = 0; i < invoice->amountOfBooks; i++){
        free(invoice->bookTitles[i]);
    }
    free(invoice->bookTitles);
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
    int difference = invoice1->timestamp - invoice2->timestamp;
    if(difference > 0){
        return 1;
    }
    if(difference < 0){
        return -1;
    }
    return 0;
}