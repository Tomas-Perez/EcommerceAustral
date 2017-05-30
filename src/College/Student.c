#include "Student.h"
#include <stdlib.h>

Student* createStudent(char* name, int password, int phoneNumber, char* career,int initialCapacity){
    Student* result = malloc(sizeof(Student));

    result->name = malloc(sizeof(char)*(strlen(name)+1));
    strcpy(result->name, name);

    result->password = password;
    result->phoneNumber = phoneNumber;

    result->career = malloc(sizeof(char)*(strlen(name)+1));
    strcpy(result->career,career);

    result->maxCapacityOfPayments = initialCapacity;
    result->maxCapacityOfBooks = initialCapacity;

    return result;
}

void studentAddBook(Student* student, ProductBook* book){
    if (student->amountOfBooks == student->maxCapacityOfBooks){
        student->books = realloc(student->books, sizeof(ProductBook*)*student->maxCapacityOfBooks*2);
        student->maxCapacityOfBooks = student->maxCapacityOfBooks*2;
    }

    student->books[student->amountOfBooks] = book;
    student->amountOfBooks++;

};

void addPayment(Student* student, Payment* payment){
    if (student->amountOfPayments == student->maxCapacityOfPayments){
        student->purchaseHistory = realloc(student->purchaseHistory, sizeof(Payment*)*student->maxCapacityOfPayments*2);
        student->maxCapacityOfPayments = student->maxCapacityOfPayments*2;
    }

    student->purchaseHistory[student->amountOfPayments] = payment;
    student->amountOfPayments++;
};

void studentRemoveBook(Student* student, int bookISBN){
    for (int i = 0; i < student->amountOfBooks; i++) {
        if(student->books[i]->bookInfo->ISBN == bookISBN){
            for (;i < student->amountOfBooks ; i++) {
                student->books[i] = student->books[i+1];
            }
            student->amountOfBooks--;
        }
    }
};


void removePayment(Student* student, int paymentID){
    for (int i = 0; i < student->amountOfPayments; i++) {
        if(student->purchaseHistory[i]->paymentMethod->paymentID == paymentID){
            for (;i < student->amountOfPayments ; i++) {
                student->purchaseHistory[i] = student->purchaseHistory[i+1];
            }
            student->amountOfPayments--;
        }
    }
};


void destroyStudent(Student* student){
    free(student->career);
    free(student->name);
    free(student);
}