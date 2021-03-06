
#include "CUTest/CuTest.h"
#include "../src/Ecommerce/UserDatabase.h"

void TestCreateDatabase(CuTest* tc){
    Admin* admin = createAdmin("admin", 1234, 456946);
    UserDatabase* database = createUserDatabase(5, admin);

    CuAssertIntEquals(tc, 0, admin->userID);
}

void TestAdd(CuTest* tc){
    Admin* admin = createAdmin("admin", 1234, 456946);
    UserDatabase* database = createUserDatabase(1, admin);

    Student* one = createStudent("student", 1234, 34423, "it", 4);
    int addResult = uDatabaseAddStudent(database, one, "one");
    Student* resultOne = uDatabaseGetStudent(database, 1);

    CuAssertIntEquals(tc, 1234, resultOne->password);
    CuAssertIntEquals(tc, 1, addResult);

    SupportStaff* two = createSupportStaff("two", 153, 45456);
    addResult = uDatabaseAddSupportStaff(database, two, "two");
    SupportStaff* resultTwo = uDatabaseGetSupportStaff(database, 2);
    resultOne = uDatabaseGetStudent(database, 1);
    CuAssertIntEquals(tc, 153, resultTwo->password);
    CuAssertIntEquals(tc, 1234, resultOne->password);
    CuAssertIntEquals(tc, 1, addResult);


    Provider* three = createProvider("provider", 689, 2342, 3435, 4);
    addResult = uDatabaseAddProvider(database, three, "three");
    Provider* resultThree = uDatabaseGetProvider(database, 3);
    resultOne = uDatabaseGetStudent(database, 1);
    resultTwo = uDatabaseGetSupportStaff(database, 2);
    CuAssertIntEquals(tc, 153, resultTwo->password);
    CuAssertIntEquals(tc, 1234, resultOne->password);
    CuAssertIntEquals(tc, 689, resultThree->password);
    CuAssertIntEquals(tc, 1, addResult);

    Provider* three2 = createProvider("provider", 596, 2342, 3435, 4);
    addResult = uDatabaseAddProvider(database, three2, "three");
    Provider* resultThree2 = uDatabaseGetProvider(database, 4);

    CuAssertIntEquals(tc, 0, addResult);

    Student* three3 = createStudent("student", 265, 34423, "it", 4);
    addResult = uDatabaseAddStudent(database, three3, "three");
    Provider* resultThree3 = uDatabaseGetProvider(database, 4);

    CuAssertIntEquals(tc, 0, addResult);

    SupportStaff* three4 = createSupportStaff("three4", 265, 45126);
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

    Student* student1 = createStudent("student", 1234, 34423, "it", 4);
    Student* student2 = createStudent("student", 1234, 34423, "it", 4);
    Student* student3 = createStudent("student", 1234, 34423, "it", 4);
    Student* student4 = createStudent("student", 1234, 34423, "it", 4);

    Provider* provider5 = createProvider("provider", 689, 2342, 3435, 4);
    Provider* provider6 = createProvider("provider", 689, 2342, 3435, 4);
    Provider* provider7 = createProvider("provider", 689, 2342, 3435, 4);
    Provider* provider8 = createProvider("provider", 689, 2342, 3435, 4);

    SupportStaff* supportStaff9 = createSupportStaff("supportStaff9", 659, 2202163);
    SupportStaff* supportStaff10 = createSupportStaff("supportStaff10", 659, 69950);
    SupportStaff* supportStaff11 = createSupportStaff("supportStaff00", 659, 65926);
    SupportStaff* supportStaff12 = createSupportStaff("supportStaff10", 659, 3266);

    uDatabaseAddStudent(database, student1, "student1");
    uDatabaseAddStudent(database, student2, "student2");
    uDatabaseAddStudent(database, student3, "student3");
    uDatabaseAddStudent(database, student4, "student4");

    CuAssertIntEquals(tc, 1, student1->userID);
    CuAssertIntEquals(tc, 2, student2->userID);
    CuAssertIntEquals(tc, 3, student3->userID);
    CuAssertIntEquals(tc, 4, student4->userID);

    uDatabaseAddProvider(database, provider5, "provider5");
    uDatabaseAddProvider(database, provider6, "provider6");
    uDatabaseAddProvider(database, provider7, "provider7");
    uDatabaseAddProvider(database, provider8, "provider8");

    CuAssertIntEquals(tc, 5, provider5->userID);
    CuAssertIntEquals(tc, 6, provider6->userID);
    CuAssertIntEquals(tc, 7, provider7->userID);
    CuAssertIntEquals(tc, 8, provider8->userID);

    uDatabaseAddSupportStaff(database, supportStaff9, "supportStaff9");
    uDatabaseAddSupportStaff(database, supportStaff10, "supportStaff10");
    uDatabaseAddSupportStaff(database, supportStaff11, "supportStaff11");
    uDatabaseAddSupportStaff(database, supportStaff12, "supportStaff12");

    CuAssertIntEquals(tc, 9, supportStaff9->userID);
    CuAssertIntEquals(tc, 10, supportStaff10->userID);
    CuAssertIntEquals(tc, 11, supportStaff11->userID);
    CuAssertIntEquals(tc, 12, supportStaff12->userID);

    Provider* resultSix = uDatabaseGetProvider(database, 6);

    CuAssertIntEquals(tc, 689, resultSix->password);
    CuAssertIntEquals(tc, 13, database->userLogAmount);
    CuAssertIntEquals(tc, 4, database->providerAmount);

    uDatabaseRemoveProvider(database, 6);
    Provider* resultSixRmv = uDatabaseGetProvider(database, 6);
    CuAssertTrue(tc, resultSixRmv == NULL);
    CuAssertIntEquals(tc, 12, database->userLogAmount);
    CuAssertIntEquals(tc, 3, database->providerAmount);

    uDatabaseRemoveProvider(database, 6);
    uDatabaseRemoveProvider(database, 6);
    uDatabaseRemoveProvider(database, 6);

    Student* result3 = uDatabaseGetStudent(database, 3);

    CuAssertIntEquals(tc, 1234, result3->password);
    CuAssertIntEquals(tc, 12, database->userLogAmount);
    CuAssertIntEquals(tc, 4, database->studentAmount);

    uDatabaseRemoveStudent(database, 3);
    Student* result3Rmv = uDatabaseGetStudent(database, 3);
    CuAssertTrue(tc, result3Rmv == NULL);
    CuAssertIntEquals(tc, 11, database->userLogAmount);
    CuAssertIntEquals(tc, 3, database->studentAmount);

    uDatabaseRemoveStudent(database, 3);
    uDatabaseRemoveStudent(database, 3);
    uDatabaseRemoveStudent(database, 3);

    SupportStaff* result9 = uDatabaseGetSupportStaff(database, 9);

    CuAssertIntEquals(tc, 659, result9->password);
    CuAssertIntEquals(tc, 11, database->userLogAmount);
    CuAssertIntEquals(tc, 4, database->supportStaffAmount);

    uDatabaseRemoveSupportStaff(database, 9);
    SupportStaff* result9Rmv = uDatabaseGetSupportStaff(database, 9);
    CuAssertTrue(tc, result9Rmv == NULL);
    CuAssertIntEquals(tc, 10, database->userLogAmount);
    CuAssertIntEquals(tc, 3, database->supportStaffAmount);

    uDatabaseRemoveSupportStaff(database, 9);
    uDatabaseRemoveSupportStaff(database, 9);
    uDatabaseRemoveSupportStaff(database, 9);
}

void TestAddRemove(CuTest* tc){
    Admin* admin = createAdmin("admin", 1234, 456946);
    UserDatabase* database = createUserDatabase(1, admin);

    Student* student1 = createStudent("student", 1234, 34423, "it", 4);
    Student* student2 = createStudent("student", 1234, 34423, "it", 4);

    Provider* provider3 = createProvider("provider", 689, 2342, 3435, 4);
    Provider* provider4 = createProvider("provider", 689, 2342, 3435, 4);

    SupportStaff* supportStaff5 = createSupportStaff("supportStaff5", 659, 56956);
    SupportStaff* supportStaff6 = createSupportStaff("supportStaff6", 659, 956526);


    uDatabaseAddStudent(database, student1, "student1");
    uDatabaseAddStudent(database, student2, "student2");

    uDatabaseAddProvider(database, provider3, "provider3");
    uDatabaseAddProvider(database, provider4, "provider4");

    uDatabaseAddSupportStaff(database, supportStaff5, "supportStaff5");
    uDatabaseAddSupportStaff(database, supportStaff6, "supportStaff6");

    CuAssertIntEquals(tc, 7, database->userLogAmount);

    CuAssertIntEquals(tc, 2, database->studentAmount);
    uDatabaseRemoveStudent(database, 1);
    uDatabaseRemoveStudent(database, 2);
    CuAssertIntEquals(tc, 0, database->studentAmount);

    CuAssertIntEquals(tc, 2, database->providerAmount);
    uDatabaseRemoveProvider(database, 3);
    uDatabaseRemoveProvider(database, 4);
    CuAssertIntEquals(tc, 0, database->providerAmount);

    CuAssertIntEquals(tc, 2, database->supportStaffAmount);
    uDatabaseRemoveSupportStaff(database, 5);
    uDatabaseRemoveSupportStaff(database, 6);
    CuAssertIntEquals(tc, 0, database->supportStaffAmount);

    CuAssertIntEquals(tc, 1, database->userLogAmount);

    Student* student7 = createStudent("student", 1234, 34423, "it", 4);
    Student* student8 = createStudent("student", 1234, 34423, "it", 4);
    uDatabaseAddStudent(database, student7, "student7");
    uDatabaseAddStudent(database, student8, "student8");
    CuAssertIntEquals(tc, 2, database->studentAmount);

    Provider* provider9 = createProvider("provider", 689, 2342, 3435, 4);
    Provider* provider10 = createProvider("provider", 689, 2342, 3435, 4);
    uDatabaseAddProvider(database, provider9, "provider9");
    uDatabaseAddProvider(database, provider10, "provider10");
    CuAssertIntEquals(tc, 2, database->providerAmount);

    SupportStaff* supportStaff11 = createSupportStaff("supportStaff11", 659, 126599);
    SupportStaff* supportStaff12 = createSupportStaff("supportStaff12", 659, 26599);
    uDatabaseAddSupportStaff(database, supportStaff11, "supportStaff11");
    uDatabaseAddSupportStaff(database, supportStaff12, "supportStaff12");
    CuAssertIntEquals(tc, 2, database->supportStaffAmount);

    CuAssertIntEquals(tc, 7, database->userLogAmount);
}



void TestLogin(CuTest* tc){
    Admin* admin = createAdmin("admin", 1234, 456946);
    UserDatabase* database = createUserDatabase(1, admin);
    Student* student1 = createStudent("student1", 123, 34423, "it", 4);
    Student* student2 = createStudent("student2", 123, 34423, "it", 4);

    Provider* provider3 = createProvider("provider3", 689, 2342, 3435, 4);
    Provider* provider4 = createProvider("provider4", 2665, 2342, 3435, 4);

    SupportStaff* supportStaff5 = createSupportStaff("supportStaff5", 659, 6596);
    SupportStaff* supportStaff6 = createSupportStaff("supportStaff6", 659, 6599);

    uDatabaseAddStudent(database, student1, "student1");
    uDatabaseAddStudent(database, student2, "student2");
    uDatabaseAddProvider(database, provider3, "provider3");
    uDatabaseAddProvider(database, provider4, "provider4");
    uDatabaseAddSupportStaff(database, supportStaff5, "supportStaff5");
    uDatabaseAddSupportStaff(database, supportStaff6, "supportStaff6");

    UserLog* student2Log = login(database, "student2", 123);
    CuAssertIntEquals(tc, STUDENT, student2Log->userType);
    CuAssertIntEquals(tc, 2, student2Log->userID);
    CuAssertStrEquals(tc, "student2", student2Log->username);

    UserLog* provider4Log = login(database, "provider4", 2665);
    CuAssertIntEquals(tc, PROVIDER, provider4Log->userType);
    CuAssertIntEquals(tc, 4, provider4Log->userID);
    CuAssertStrEquals(tc, "provider4", provider4Log->username);

    UserLog* supportStaff6Log = login(database, "supportStaff6", 659);
    CuAssertIntEquals(tc, SUPPORT_STAFF, supportStaff6Log->userType);
    CuAssertIntEquals(tc, 6, supportStaff6Log->userID);
    CuAssertStrEquals(tc, "supportStaff6", supportStaff6Log->username);

    UserLog* adminLog = login(database, "admin", 1234);
    CuAssertIntEquals(tc, ADMIN, adminLog->userType);
    CuAssertIntEquals(tc, 0, adminLog->userID);
    CuAssertStrEquals(tc, "admin", adminLog->username);

    UserLog* wrongPasswordLog = login(database, "student1", 656);
    CuAssertIntEquals(tc, UNKNOWN, wrongPasswordLog->userType);
    CuAssertIntEquals(tc, -2, wrongPasswordLog->userID);
    CuAssertStrEquals(tc, "unknown", wrongPasswordLog->username);

    wrongPasswordLog = login(database, "provider4", 65941);
    CuAssertIntEquals(tc, UNKNOWN, wrongPasswordLog->userType);
    CuAssertIntEquals(tc, -2, wrongPasswordLog->userID);
    CuAssertStrEquals(tc, "unknown", wrongPasswordLog->username);

    wrongPasswordLog = login(database, "supportStaff6", 10236);
    CuAssertIntEquals(tc, UNKNOWN, wrongPasswordLog->userType);
    CuAssertIntEquals(tc, -2, wrongPasswordLog->userID);
    CuAssertStrEquals(tc, "unknown", wrongPasswordLog->username);

    UserLog* wrongUsernameLog = login(database, "student54", 656);
    CuAssertIntEquals(tc, UNKNOWN, wrongUsernameLog->userType);
    CuAssertIntEquals(tc, -1, wrongUsernameLog->userID);
    CuAssertStrEquals(tc, "unknown", wrongUsernameLog->username);

    uDatabaseRemoveStudent(database, 2);

    UserLog* student2RMVLog = login(database, "student2", 123);
    CuAssertIntEquals(tc, UNKNOWN, student2RMVLog->userType);
    CuAssertIntEquals(tc, -1, student2RMVLog->userID);
    CuAssertStrEquals(tc, "unknown", student2RMVLog->username);

    uDatabaseRemoveSupportStaff(database, 6);

    UserLog* supportStaff6RMVLog = login(database, "supportStaff6", 659);
    CuAssertIntEquals(tc, UNKNOWN, supportStaff6RMVLog->userType);
    CuAssertIntEquals(tc, -1, supportStaff6RMVLog->userID);
    CuAssertStrEquals(tc, "unknown", supportStaff6RMVLog->username);

    uDatabaseRemoveProvider(database, 4);
    UserLog* provider4RMVLog = login(database, "provider4", 2665);
    CuAssertIntEquals(tc, UNKNOWN, provider4RMVLog->userType);
    CuAssertIntEquals(tc, -1, provider4RMVLog->userID);
    CuAssertStrEquals(tc, "unknown", provider4RMVLog->username);

    destroyUserDatabase(database);
}

CuSuite* GetUDatabaseTestSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestCreateDatabase);
    SUITE_ADD_TEST(suite, TestAdd);
    SUITE_ADD_TEST(suite, TestRemove);
    SUITE_ADD_TEST(suite, TestAddRemove);
    SUITE_ADD_TEST(suite, TestLogin);

    return suite;
}
