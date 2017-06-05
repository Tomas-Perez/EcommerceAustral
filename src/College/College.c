#include <stdlib.h>
#include <memory.h>
#include "College.h"

/*
 * Function: createCollege
 * Description: allocates memory for a College and all its components.
 * Returns: College pointer
 */
College* createCollege(char* name, int initialCapacity){
    College* newCollege = malloc(sizeof(College));

    newCollege->name = malloc( sizeof(char) * (strlen(name) + 1));
    strcpy(newCollege->name, name);

    newCollege->amountOfCareers = 0;
    newCollege->maxCapacityOfCareers = initialCapacity;
    newCollege->availableCareers = malloc(sizeof(char*)*initialCapacity);

    newCollege->amountOfSubjects = 0;
    newCollege->maxCapacityOfSubjects = initialCapacity;
    newCollege->subjects = malloc(sizeof(Subject*) * initialCapacity);

    return newCollege;
}

/*
 * Function: destroyCollege
 * Description: frees all memory of a college.
 * Returns: --
 */
void destroyCollege(College* college){
    for (int i = 0; i < college->amountOfSubjects; ++i) {
        destroySubject(college->subjects[i]);
    }
    for(int i = 0; i < college->amountOfCareers; i++){
        free(college->availableCareers[i]);
    }
    free(college->subjects);
    free(college->name);
    free(college);
}

/*
 * Function: addNewSubject
 * Description: adds a subject to a college.
 * Returns: --
 */
void addNewSubject(College* college, Subject* newSubject){

    if(college->amountOfSubjects == college->maxCapacityOfSubjects){
        college->subjects = realloc(college->subjects, sizeof(Subject*)*college->maxCapacityOfSubjects*2);
        college->maxCapacityOfSubjects = college->maxCapacityOfSubjects*2;
    }

    college->subjects[college->amountOfSubjects] = newSubject;
    college->amountOfSubjects++;
}


/*
 * Function: removeSubject
 * Description: removes a subject from the college.
 * Returns: 1 if subject was removed, 0 if subject was not found.
 */
int removeSubject(College* college, int subjectID){
    for (int i = 0; i < college->amountOfSubjects; i++) {
        if(college->subjects[i]->subjectID == subjectID){
            destroySubject(college->subjects[i]);
            for (; i < college->amountOfSubjects - 1; i++) {
                college->subjects[i] = college->subjects[i+1];
            }
            college->amountOfSubjects--;
            return 1;
        }
    }
    return 0;
}

/*
 * Function: addNewCareer
 * Description: adds a career to a college.
 * Returns: --
 */
void addNewCareer(College* college, char* careerName){
    if(college->amountOfCareers == college->maxCapacityOfCareers){
        college->availableCareers = realloc(college->availableCareers, sizeof(char*)*college->maxCapacityOfCareers*2);
        college->maxCapacityOfCareers = college->maxCapacityOfCareers*2;
    }

    college->availableCareers[college->amountOfCareers] = malloc(sizeof(char)*(strlen(careerName)+1));
    strcpy(college->availableCareers[college->amountOfCareers], careerName);
    college->amountOfCareers++;
};

/*
 * Function: removeCareer
 * Description: removes a career from the college.
 * Returns: 1 if career was removed, 0 if career was not found.
 */
int removeCareer(College *college, char *careerName){
    for (int i = 0; i < college->amountOfCareers ; ++i) {
        if (strcmp(college->availableCareers[i], careerName) == 0){
            free(college->availableCareers[i]);
            for (;i < college->amountOfCareers - 1; i++){
                college->availableCareers[i] = college->availableCareers[i+1];
            }
            college->amountOfCareers--;
            return 1;
        }
    }
    return 0;
};

/*
 * Function: getCareerSubjects
 * Description: gives an array of the subjects of a career.
 * Returns: ArrayOfSubject pointer.
 */
ArrayOfSubjects* getCareerSubjects(College* college, char* careerName){
    int amountOfSubjects = 0;
    int maxCapacityOfSubjects = 10;
    Subject** subjects = malloc(sizeof(Subject*)* 10);

    for (int i = 0; i < college->amountOfSubjects; ++i) {
        if(strcmp(college->subjects[i]->career,careerName) == 0){
            if(amountOfSubjects == maxCapacityOfSubjects){
                subjects = realloc(subjects, sizeof(Subject*)* maxCapacityOfSubjects*2);
                maxCapacityOfSubjects = maxCapacityOfSubjects*2;
            }
            subjects[amountOfSubjects] = college->subjects[i];
            amountOfSubjects++;
        }
    }

    ArrayOfSubjects* array = malloc(sizeof(ArrayOfSubjects));
    array->subjects = subjects;
    array->amountOfSubjects = amountOfSubjects;

    return array;
};

/*
 * Function: enrollStudentInSubject
 * Description: enrolls a student to a certain subject of a college.
 * Returns: 1 if student was enrolled, 0 if there was no more space in subject, or the
 * subject was not found.
 */
int enrollStudentInSubject(College* college, int subjectID, int studentID){
    for (int i = 0; i < college->amountOfSubjects; i++) {
        if(college->subjects[i]->subjectID == subjectID){
            return addStudentToSubject(college->subjects[i], studentID);

        }
    }
    return 0;
}

/*
 * Function: withdrawStudentFromSubject
 * Description: removes a student from a specfic subject in a college.
 * Returns: 1 if student was removed, 0 if the subject or student was not found.
 */
int withdrawStudentFromSubject(College* college, int subjectID, int studentID){
    for (int i  = 0; i < college->amountOfSubjects; i++) {
        if(college->subjects[i]->subjectID == subjectID){
            return removeStudentFromSubject(college->subjects[i], studentID);
        }
    }
    return 0;
}

/*
 * Function: getSubjectsOfStudent
 * Description: gives an array of the subjects in which a student is enrolled.
 * Returns: ArrayOfSubject pointer.
 */
ArrayOfSubjects* getSubjectsOfStudent(College* college, int studentID){
    int amountOfSubjects = 0;
    int maxCapacityOfSubjects = 10;
    Subject** subjects = malloc(sizeof(Subject*)* 10);

    for (int i = 0; i < college->amountOfSubjects; ++i) {
        if(studentIsEnrolled(college->subjects[i], studentID) == 1){
            if(amountOfSubjects == maxCapacityOfSubjects){
                subjects = realloc(subjects, sizeof(Subject*)* maxCapacityOfSubjects*2);
                maxCapacityOfSubjects = maxCapacityOfSubjects*2;
            }
            subjects[amountOfSubjects] = college->subjects[i];
            amountOfSubjects++;
        }
    }

    ArrayOfSubjects* array = malloc(sizeof(ArrayOfSubjects));
    array->subjects = subjects;
    array->amountOfSubjects = amountOfSubjects;

    return array;
}

/*
 * Function: getBooksOfStudent
 * Description: gives an array of the books the student needs for the subjects in
 * which he is enrolled.
 * Returns: ArrayOfBooks pointer.
 */
ArrayOfBooks* getBooksOfStudent(College* college, int studentID){
    int amountOfBooks = 0;
    int maxCapacity = 10;
    BookInformation** books = malloc(sizeof(BookInformation*) * 10);

    ArrayOfSubjects* subjectsOfStudent = getSubjectsOfStudent(college, studentID);
    Subject** subjects = subjectsOfStudent->subjects;
    int amountOfSubjects = subjectsOfStudent->amountOfSubjects;

    for (int i = 0; i < amountOfSubjects; i++) {

        Subject* subject = subjects[i];
        for (int j = 0; j < subject->amountOfBooks; j++) {
            if(amountOfBooks == maxCapacity){
                books = realloc(books, sizeof(BookInformation*)* maxCapacity*2);
                maxCapacity = maxCapacity*2;
            }
            books[amountOfBooks] = subject->books[j];
            amountOfBooks++;
        }
    }

    ArrayOfBooks* array = malloc(sizeof(ArrayOfBooks));
    array->books = books;
    array->amountOfBooks = amountOfBooks;

    return array;
}
