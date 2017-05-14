#include <stdio.h>
#include "../test/CUTest/CuTest.h"

/**
 * Test setup
 */

void RunAllTests(void) {
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();

    // CuSuiteAddSuite(suite, );
    CuSuiteAddSuite(suite, CreateProductGetSuite());
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}

int main(void) {
    RunAllTests();
}
