#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <malloc.h>
#include <mem.h>
#include "Cart.h"
#include "Student.h"
#include "Invoice.h"

int main() {
    /*
    Cart* cart = createCart(5, 2);
    Student student = {5};
    Invoice* invoice1 = createInvoice(cart, &student);
    for (int i = 0; i < 1000000000; i++);
    Invoice* invoice2 = createInvoice(cart, &student);
    printf("%f", difftime(invoice1->tm, invoice2->tm));
    printf("%s", invoice1->date);
    printf("%s", invoice2->date);
     */
    /*
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char* timeVar = asctime(tm);
    char* savedTime = malloc(sizeof(char)*strlen(timeVar));
    strcpy(savedTime, asctime(tm));


    for (int i = 0; i < 1000000000; i++);
    time_t t1 = mktime(tm);
    time_t t2 = time(NULL);
    printf("%s\n", savedTime);
    struct tm *tm2 = localtime(&t2);
    char* timeVar2 = asctime(tm2);

    printf("%s\n", timeVar2);
    printf("%f", difftime(t1, t2));
     */

    return 0;
}
