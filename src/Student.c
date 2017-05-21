#include "Student.h"
#include <stdlib.h>

Student* createStudent(int password){
    Student* result = malloc(sizeof(Student));
    result->password = password;
}

void destroyStudent(Student* student){

}