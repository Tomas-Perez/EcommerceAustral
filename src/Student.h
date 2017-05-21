#ifndef ECOMMERCEAUSTRAL_STUDENT_H
#define ECOMMERCEAUSTRAL_STUDENT_H

typedef struct Student{
    int userID;
    int password;
}Student;

Student* createStudent(int password); //Testing database
void destroyStudent(Student* student);

#endif //ECOMMERCEAUSTRAL_STUDENT_H
