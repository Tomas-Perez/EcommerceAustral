//
// Created by Agustin Bettati  on 21/5/17.
//

#ifndef ECOMMERCEAUSTRAL_SUBJECT_H
#define ECOMMERCEAUSTRAL_SUBJECT_H

#include "BookInformation.h"

typedef struct subject{
    char* name;

    int* studentIDs;
    int amountOfStudents;
    int maxCapacityOfStudents;

    BookInformation** books;
    int amountOfBooks;
    int maxCapacityOfBooks;

}Subject;

Subject* createSubject(char* name, int maxCapacityOfStudents);
void destroySubject(Subject* subject);

int studentIsEnrolled(Subject* subject, int studentID);

void addNewBook(Subject* subject, BookInformation* bookInformation);
void addStudent(Subject* subject, int studentID);

#endif //ECOMMERCEAUSTRAL_SUBJECT_H
