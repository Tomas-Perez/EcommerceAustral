#include "Student.h"
#include <stdlib.h>

/*
 * Function: createStudent
 * Description: allocates memory for a Student and all its components.
 * Returns: Student pointer
 */
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

    result->amountOfBooks = 0;
    result->amountOfPayments = 0;

    result->purchaseHistory = malloc(sizeof(Payment*)*result->maxCapacityOfPayments);
    result->books = malloc(sizeof(ProductBook*)*result->maxCapacityOfBooks);

    return result;
}

/*
 * Function: studentAddBook
 * Description: adds a book to a student.
 * Returns: --
 */
void studentAddBook(Student* student, ProductBook* book){
    if (student->amountOfBooks == student->maxCapacityOfBooks){
        student->books = realloc(student->books, sizeof(ProductBook*)*student->maxCapacityOfBooks*2);
        student->maxCapacityOfBooks = student->maxCapacityOfBooks*2;
    }

    student->books[student->amountOfBooks] = book;
    student->amountOfBooks++;

};

/*
 * Function: addPayment
 * Description: adds a payment to a student.
 * Returns: --
 */
void addPayment(Student* student, Payment* payment){
    if (student->amountOfPayments == student->maxCapacityOfPayments){
        student->purchaseHistory = realloc(student->purchaseHistory, sizeof(Payment*)*student->maxCapacityOfPayments*2);
        student->maxCapacityOfPayments = student->maxCapacityOfPayments*2;
    }

    student->purchaseHistory[student->amountOfPayments] = payment;
    student->amountOfPayments++;
};

/*
 * Function: studentRemoveBook.
 * Description: removes a book from the student.
 * Returns: 1 if book was removed, 0 if book was not found.
 */
int studentRemoveBook(Student* student, int bookISBN){
    for (int i = 0; i < student->amountOfBooks; i++) {
        if(student->books[i]->bookInfo->ISBN == bookISBN){
            for (;i < student->amountOfBooks ; i++) {
                student->books[i] = student->books[i+1];
            }
            student->amountOfBooks--;
            return 1;
        }
    }
    return 0;
};

/*
 * Function: removePayment
 * Description: removes a payment from the student.
 * Returns: 1 if payment was removed, 0 if payment was not found.
 */
int removePayment(Student* student, int paymentID){
    for (int i = 0; i < student->amountOfPayments; i++) {
        if(student->purchaseHistory[i]->paymentMethod->paymentID == paymentID){
            for (;i < student->amountOfPayments ; i++) {
                student->purchaseHistory[i] = student->purchaseHistory[i+1];
            }
            student->amountOfPayments--;
            return 1;
        }
    }
    return 0;
};

/*
 * Function: destroyStudent
 * Description: frees all memory of a student.
 * Returns: --
 */
void destroyStudent(Student* student){
    for(int i = 0; i < student->amountOfPayments; i++){
        destroyPayment(student->purchaseHistory[i]);
    }
    for(int i = 0; i < student->amountOfBooks; i++){
        destroyProductBook(student->books[i]);
    }
    free(student->books);
    free(student->purchaseHistory);
    free(student->career);
    free(student->name);
    free(student);
}