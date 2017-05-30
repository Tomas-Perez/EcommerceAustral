#include <stdio.h>
#include "CUTest/CuTest.h"
#include "../src/Ecommerce/SupportDatabase.h"
#include "../src/Ecommerce/SupportStaff.h"

void TestSupportDatabaseAddMessage(CuTest *tc){
    SupportDatabase* database = newSupportDatabase(1);
    SupportMessage* message = newSupportMessage("Is this a test?", 1232);
    addMessage(database, message);
    CuAssertIntEquals(tc, 1, database->messageAmount);
    addMessage(database, message);
    CuAssertIntEquals(tc, 2, database->messageAmount);
    removeMessage(database, message->id);
    CuAssertIntEquals(tc, 1, database->messageAmount);
}

void TestSupportDatabaseGetMessage(CuTest *tc){
    SupportDatabase* database = newSupportDatabase(10);
    SupportMessage* message = newSupportMessage("Clearly Googleable question", 3421);
    SupportMessage* message2 = newSupportMessage("Is this where I'm supposed to ask a question?", 1324);
    SupportMessage* message3 = newSupportMessage("Generic Question", 3421);
    addMessage(database, message);
    addMessage(database, message2);
    addMessage(database, message3);
    SupportMessage** questions = getMessagesByUser(database, 3421);
    CuAssertIntEquals(tc, 3421, questions[0]->studentID);
    CuAssertIntEquals(tc, 3421, questions[1]->studentID);
    answerQuestion(1234, message2, "It is");
    SupportMessage** answers = getMessagesBySupportStaff(database, 1234);
    CuAssertIntEquals(tc, 1234, answers[0]->supportStaffID);
}

void TestSupportStaffAnswerQuestion(CuTest *tc){
    SupportDatabase* database = newSupportDatabase(10);
    SupportMessage* message = newSupportMessage("Will this question be answered?", 8675);
    addMessage(database, message);
    answerQuestion(5412, message, "It will");
    CuAssertIntEquals(tc, 5412, message->supportStaffID);
    CuAssertIntEquals(tc, 1, message->isAnswered);
}

CuSuite* GetSupportTestSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestSupportDatabaseAddMessage);
    SUITE_ADD_TEST(suite, TestSupportDatabaseGetMessage);
    SUITE_ADD_TEST(suite, TestSupportStaffAnswerQuestion);

    return suite;
}