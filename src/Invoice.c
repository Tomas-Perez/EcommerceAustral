#include <malloc.h>
#include <sys/types.h>
#include <time.h>
#include "Invoice.h"

Invoice* createInvoice(Cart* cart, Student* student){
    Invoice* result = malloc(sizeof(Invoice));
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
    struct tm *tm = localtime(&t);
    char* time = asctime(tm);
    result->date = malloc(sizeof(char)*strlen(time));
    strcpy(result->date, time);

    return result;
}

void destroyInvoice(Invoice* invoice){
    for(int i = 0; i < invoice->amountOfBooks; i++){
        destroyProductBook(invoice->pBooks[i]);
    }
    free(invoice->student);
    free(invoice);
}