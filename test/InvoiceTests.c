#include <stdio.h>
#include <time.h>
#include "CUTest/CuTest.h"
#include "../src/Invoice.h"

void TestCompare(CuTest* tc){
    Cart* cart = createCart(5, 2);
    Student* student;
    Invoice* invoice1 = createInvoice(cart, student);
    //Needed for there to be a time difference between invoices
    printf("Running Invoice test please wait...\n\n");
    for (int i = 0; i < 1000000000; i++);
    Invoice* invoice2 = createInvoice(cart, student);
    CuAssertIntEquals(tc, 1, compareInvoiceDate(invoice2, invoice1));
}

CuSuite* GetInvoiceTestSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestCompare);

    return suite;
}


