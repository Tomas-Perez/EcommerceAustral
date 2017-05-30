#include <stdio.h>
#include "CUTest/CuTest.h"
#include "../src/Ecommerce/Invoice.h"
#include "../src/College/Student.h"

void TestCompare(CuTest* tc){
    Cart* cart = createCart(5, 2);
    Invoice* invoice1 = createInvoice(cart, 323);
    //Needed for there to be a time difference between invoices
    printf("Running Invoice test please wait...\n\n");
    for (int i = 0; i < 1000000000; i++);
    Invoice* invoice2 = createInvoice(cart, 233);
    CuAssertIntEquals(tc, 1, compareInvoiceDate(invoice2, invoice1));
}

CuSuite* GetInvoiceTestSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestCompare);

    return suite;
}

void RunInvoiceTest(void) {
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();

    CuSuiteAddSuite(suite, GetInvoiceTestSuite());

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}

int main(void) {
    RunInvoiceTest();
}



