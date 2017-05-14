#include "../test/CUTest/CuTest.h"
#include "../src/ProductBook.h"


void TestCreateProductBook(CuTest *tc) {
    ProductBook* book = createProductBook("Math", 10, 0);
    char* actual = book->title;
    char* expected = "Math";
    CuAssertStrEquals(tc, expected, actual);
}

CuSuite* CreateProductGetSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestCreateProductBook);
    return suite;
}