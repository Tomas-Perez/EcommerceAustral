#ifndef ECOMMERCEAUSTRAL_COLLEGE_H
#define ECOMMERCEAUSTRAL_COLLEGE_H

#include "Subject.h"

typedef struct college{
    char* name;

    Subject** subjects;
    int amountOfSubjects;
    int maxCapacityOfSubjects;

}College;

College* createCollege(char* name, int initialCapacity);
void destroyCollege(College* college);

void addNewSubject(College* college, Subject* newSubject);

void enrollStudentInSubject(College* college, int subjectID, int studentID);
Subject* getSubjectsOfStudent(College* college, int studentID);
BookInformation* getBooksOfStudent(College* college, int studentID);

#endif //ECOMMERCEAUSTRAL_COLLEGE_H
