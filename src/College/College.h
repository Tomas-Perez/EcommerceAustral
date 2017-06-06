#ifndef ECOMMERCEAUSTRAL_COLLEGE_H
#define ECOMMERCEAUSTRAL_COLLEGE_H

#include "Subject.h"

typedef struct college{
    char* name;

    char** availableCareers;
    int amountOfCareers;
    int maxCapacityOfCareers;

    Subject** subjects;
    int amountOfSubjects;
    int maxCapacityOfSubjects;

    int subjectIDGen;
}College;

College* createCollege(char* name, int initialCapacity);
void destroyCollege(College* college);

void addNewSubject(College* college, Subject* newSubject);
int removeSubject(College* college, int subjectID);

void addNewCareer(College* college, char* careerName);
int removeCareer(College *college, char *careerName);
ArrayOfSubjects* getCareerSubjects(College* college, char* careerName);

int enrollStudentInSubject(College* college, int subjectID, int studentID);
int withdrawStudentFromSubject(College* college, int subjectID, int studentID);

ArrayOfSubjects* getSubjectsOfStudent(College* college, int studentID);
ArrayOfBooks* getBooksOfStudent(College* college, int studentID);

#endif //ECOMMERCEAUSTRAL_COLLEGE_H
