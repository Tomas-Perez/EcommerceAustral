//
// Created by Agustin Bettati  on 21/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include <printf.h>
#include "Subject.h"

/*
 * Function: createSubject
 * Description: allocates memory for a Subject and all its components.
 * Returns: Subject pointer
 */
Subject* createSubject(char* name, int maxCapacityOfStudents){
    Subject* newSubject = malloc(sizeof(Subject));

    newSubject->name = malloc(sizeof(char)*(strlen(name)+1));
    strcpy(newSubject->name, name);

    newSubject->amountOfStudents = 0;
    newSubject->amountOfBooks = 0;
    newSubject->maxCapacityOfStudents = maxCapacityOfStudents;
    newSubject->maxCapacityOfBooks = 10;

    newSubject->books = malloc(sizeof(BookInformation*)* 10);
    newSubject->studentIDs = malloc(sizeof(int)*maxCapacityOfStudents);

    return newSubject;
}

/*
 * Function: destroySubject
 * Description: frees all memory of a subject.
 * Returns: --
 */
void destroySubject(Subject* subject){
    free(subject->books);
    free(subject->name);
    free(subject->studentIDs);
    free(subject);
}

/*
 * Function: studentIsEnrolled
 * Description: determines if a student is present in the subject.
 * Returns: 1 if True, 0 if False.
 */
int studentIsEnrolled(Subject* subject, int studentID){
    for (int i = 0; i < subject->amountOfStudents; ++i) {
        if(subject->studentIDs[i] == studentID){
            return 1;
        }
    }
    return 0;
}

/*
 * Function: addNewBook
 * Description: adds a book to the list of books of a subject.
 * Returns: --
 */
void addNewBook(Subject* subject, BookInformation* bookInformation){
    if(subject->amountOfBooks == subject->maxCapacityOfBooks){
        subject->books = realloc(subject->books, sizeof(BookInformation*)*subject->maxCapacityOfBooks*2);
        subject->maxCapacityOfBooks = subject->maxCapacityOfBooks*2;
    }
    subject->books[subject->amountOfBooks] = bookInformation;
    subject->amountOfBooks++;

}

/*
 * Function: addNewBook
 * Description: adds a student to the subject if there is free space.
 * Returns: --
 */
void enrollStudent(Subject* subject, int studentID){
    if(subject->amountOfStudents == subject->maxCapacityOfStudents){
        printf("The subject %s has reached its maximum amount of students. \n", subject->name);
    }
    else{
        subject->studentIDs[subject->amountOfStudents] = studentID;
        subject->amountOfStudents++;
    }
}

