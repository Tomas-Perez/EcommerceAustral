


#include "CUTest/CuTest.h"
#include "../src/College/College.h"

void TestCollegeEnrollmentOfStudentInCollege(CuTest* tc){
    College* college = createCollege("Austral", 10);
    Subject* algebra = createSubject("Algebra II",1, 10);

    addNewSubject(college, algebra);

    enrollStudentInSubject(college,1, 202);
    //enrolls a student of id 202

    CuAssertIntEquals(tc, 1, studentIsEnrolled(algebra, 202));
}

void TestCollegeGetSubjectsOfStudent(CuTest* tc){
    College* college = createCollege("Austral", 10);

    Subject* algebra = createSubject("Algebra II",1, 10);
    addNewSubject(college, algebra);

    Subject* analisis = createSubject("Analisis III", 2, 10);
    addNewSubject(college, analisis);

    // student id 202 enrolls in 2 subjects.
    enrollStudentInSubject(college,1, 202);
    enrollStudentInSubject(college,2,202);

    CuAssertIntEquals(tc, 2, getSubjectsOfStudent(college,202)->amountOfSubjects);
}

void TestCollegeGetBooksOfStudent(CuTest* tc){

    College* college = createCollege("Austral", 10);

    Subject* algebra = createSubject("Algebra II",1, 10);
    addNewSubject(college, algebra);
    addNewBook(algebra, createBookInformation("Subespacios", 3003, "Sears"));

    Subject* analisis = createSubject("Analisis III", 2, 10);
    addNewSubject(college, analisis);
    addNewBook(analisis, createBookInformation("Derivadas", 101, "Chang"));

    // student id 202 enrolls in 2 subjects.
    enrollStudentInSubject(college,1, 202);
    enrollStudentInSubject(college,2,202);

    CuAssertIntEquals(tc, 2, getBooksOfStudent(college,202)->amountOfBooks);

}




CuSuite* GetCollegeTestSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestCollegeEnrollmentOfStudentInCollege);
    SUITE_ADD_TEST(suite, TestCollegeGetSubjectsOfStudent);
    SUITE_ADD_TEST(suite, TestCollegeGetBooksOfStudent);
    return suite;
}

