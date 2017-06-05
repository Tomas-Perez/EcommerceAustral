#ifndef ECOMMERCEAUSTRAL_SUBJECT_H
#define ECOMMERCEAUSTRAL_SUBJECT_H

#include "BookInformation.h"

typedef struct subject{
    char* name;
    int subjectID;

    char* career;

    int* studentIDs;
    int amountOfStudents;
    int maxCapacityOfStudents;

    BookInformation** books;
    int amountOfBooks;
    int maxCapacityOfBooks;
}Subject;

typedef struct arrayOfSubjects{
    Subject** subjects;
    int amountOfSubjects;
}ArrayOfSubjects;

Subject* createSubject(char* name,int subjectID, char* career,int maxCapacityOfStudents);
void destroySubject(Subject* subject);

int studentIsEnrolled(Subject* subject, int studentID);

void addNewBook(Subject* subject, BookInformation* bookInformation);
int addStudentToSubject(Subject* subject, int studentID);
int removeStudentFromSubject(Subject* subject, int studentID);

#endif //ECOMMERCEAUSTRAL_SUBJECT_H
