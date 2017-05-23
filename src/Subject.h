#ifndef ECOMMERCEAUSTRAL_SUBJECT_H
#define ECOMMERCEAUSTRAL_SUBJECT_H

#include "BookInformation.h"

typedef struct subject{
    char* name;
    int subjectID;

    int* studentIDs;
    int amountOfStudents;
    int maxCapacityOfStudents;

    BookInformation** books;
    int amountOfBooks;
    int maxCapacityOfBooks;

}Subject;

Subject* createSubject(char* name,int subjectID,int maxCapacityOfStudents);
void destroySubject(Subject* subject);

int studentIsEnrolled(Subject* subject, int studentID);

void addNewBook(Subject* subject, BookInformation* bookInformation);
void addStudentToSubject(Subject *subject, int studentID);

#endif //ECOMMERCEAUSTRAL_SUBJECT_H
