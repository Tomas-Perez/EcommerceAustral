#include <stdlib.h>
#include <memory.h>
#include <printf.h>
#include "College.h"

College* createCollege(char* name, int initialCapacity){
    College* newCollege = malloc(sizeof(College));

    newCollege->name = malloc(sizeof(char)* (strlen(name) + 1));
    strcpy(newCollege->name, name);


    newCollege->amountOfSubjects = 0;
    newCollege->maxCapacityOfSubjects = initialCapacity;
    newCollege->subjects = malloc(sizeof(Subject*)* initialCapacity);

    return newCollege;
}

void destroyCollege(College* college){
    for (int i = 0; i < college->amountOfSubjects; ++i) {
        destroySubject(college->subjects[i]);
    }
    free(college->subjects);
    free(college->name);
    free(college);
}

void addNewSubject(College* college, Subject* newSubject){
    if(college->amountOfSubjects == college->maxCapacityOfSubjects){
        college->subjects = realloc(college->subjects, sizeof(Subject*)*college->maxCapacityOfSubjects*2);
        college->maxCapacityOfSubjects = college->maxCapacityOfSubjects*2;
    }
    college->subjects[college->amountOfSubjects] = newSubject;
    college->amountOfSubjects++;
}

void enrollStudentInSubject(College* college, int subjectID, int studentID){
    for (int i = 0; i < college->amountOfSubjects; ++i) {
        if(college->subjects[i]->subjectID == subjectID){
            addStudentToSubject(college->subjects[i], studentID);
            return;
        }
    }
    printf("No subject was found under the ID entered.");
}
Subject* getSubjectsOfStudent(College* college, int studentID){

}
BookInformation* getBooksOfStudent(College* college, int studentID){

}
