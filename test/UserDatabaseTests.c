
#include "CUTest/CuTest.h"
#include "../src/UserDatabase.h"

void TestCreateDatabase(CuTest* tc){
    Admin* admin = createAdmin("admin", 1234, 456946);
    UserDatabase* database = createUserDatabase(5, admin);

    CuAssertIntEquals(tc, 0, admin->userID);
}

void TestAdd(CuTest* tc){
    Admin* admin = createAdmin("admin", 1234, 456946);
    UserDatabase* database = createUserDatabase(1, admin);

    Student* one = createStudent(1234);
    int addResult = uDatabaseAddStudent(database, one, "one");
    Student* resultOne = uDatabaseGetStudent(database, 1);

    CuAssertIntEquals(tc, 1234, resultOne->password);
    CuAssertIntEquals(tc, 1, addResult);

    SupportStaff* two = createSupportStaff(153);
    addResult = uDatabaseAddSupportStaff(database, two, "two");
    SupportStaff* resultTwo = uDatabaseGetSupportStaff(database, 2);
    resultOne = uDatabaseGetStudent(database, 1);
    CuAssertIntEquals(tc, 153, resultTwo->password);
    CuAssertIntEquals(tc, 1234, resultOne->password);
    CuAssertIntEquals(tc, 1, addResult);

    Provider* three = createProvider(689);
    addResult = uDatabaseAddProvider(database, three, "three");
    Provider* resultThree = uDatabaseGetProvider(database, 3);
    resultOne = uDatabaseGetStudent(database, 1);
    resultTwo = uDatabaseGetSupportStaff(database, 2);
    CuAssertIntEquals(tc, 153, resultTwo->password);
    CuAssertIntEquals(tc, 1234, resultOne->password);
    CuAssertIntEquals(tc, 689, resultThree->password);
    CuAssertIntEquals(tc, 1, addResult);

    Provider* three2 = createProvider(596);
    addResult = uDatabaseAddProvider(database, three2, "three");
    Provider* resultThree2 = uDatabaseGetProvider(database, 4);

    CuAssertIntEquals(tc, 0, addResult);

    Student* three3 = createStudent(265);
    addResult = uDatabaseAddStudent(database, three3, "three");
    Provider* resultThree3 = uDatabaseGetProvider(database, 4);

    CuAssertIntEquals(tc, 0, addResult);

    SupportStaff* three4 = createSupportStaff(265);
    addResult = uDatabaseAddSupportStaff(database, three4, "three");
    Provider* resultThree4 = uDatabaseGetProvider(database, 4);

    CuAssertIntEquals(tc, 0, addResult);

    resultOne = uDatabaseGetStudent(database, 1);
    resultTwo = uDatabaseGetSupportStaff(database, 2);
    resultThree = uDatabaseGetProvider(database, 3);

    CuAssertIntEquals(tc, 153, resultTwo->password);
    CuAssertIntEquals(tc, 1234, resultOne->password);
    CuAssertIntEquals(tc, 689, resultThree->password);
    CuAssertIntEquals(tc, 4, database->idGenerator);
    CuAssertTrue(tc, resultThree2 == NULL);
    CuAssertTrue(tc, resultThree3 == NULL);
    CuAssertTrue(tc, resultThree4 == NULL);
}

void TestRemove(CuTest* tc){
    Admin* admin = createAdmin("admin", 1234, 456946);
    UserDatabase* database = createUserDatabase(1, admin);

    Student* student1 = createStudent(123);
    Student* student2 = createStudent(123);
    Student* student3 = createStudent(123);
    Student* student4 = createStudent(123);

    Provider* provider5 = createProvider(2665);
    Provider* provider6 = createProvider(2665);
    Provider* provider7 = createProvider(2665);
    Provider* provider8 = createProvider(2665);

    SupportStaff* supportStaff9 = createSupportStaff(659);
    SupportStaff* supportStaff10 = createSupportStaff(659);
    SupportStaff* supportStaff11 = createSupportStaff(659);
    SupportStaff* supportStaff12 = createSupportStaff(659);

    uDatabaseAddStudent(database, student1, "student1");
    uDatabaseAddStudent(database, student2, "student2");
    uDatabaseAddStudent(database, student3, "student3");
    uDatabaseAddStudent(database, student4, "student4");


    uDatabaseAddProvider(database, provider5, "provider5");
    uDatabaseAddProvider(database, provider6, "provider6");
    uDatabaseAddProvider(database, provider7, "provider7");
    uDatabaseAddProvider(database, provider8, "provider8");
    /*
    uDatabaseAddSupportStaff(database, supportStaff9, "supportStaff9");
    uDatabaseAddSupportStaff(database, supportStaff10, "supportStaff10");

    uDatabaseAddSupportStaff(database, supportStaff11, "supportStaff11");
    uDatabaseAddSupportStaff(database, supportStaff12, "supportStaff12");
     */
}

CuSuite* GetUDatabaseTestSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestCreateDatabase);
    SUITE_ADD_TEST(suite, TestAdd);
    SUITE_ADD_TEST(suite, TestRemove);

    return suite;
}