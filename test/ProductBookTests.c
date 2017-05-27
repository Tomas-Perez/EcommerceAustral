#include "../test/CUTest/CuTest.h"
#include "../src/Ecommerce/ProductBook.h"


void TestCreateProductBook(CuTest *tc) {
    BookInformation* bookInfo = createBookInformation("Math", 546, "Euler");
    ProductBook* book = createProductBook(bookInfo, 10, 0);
    char* actual = book->bookInfo->title;
    char* expected = "Math";
    CuAssertStrEquals(tc, expected, actual);
}

CuSuite* CreateProductGetSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestCreateProductBook);
    return suite;
}