#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Ecommerce/UserDatabase.h"
#include "../Util/ScanUtil.h"
#include "../College/College.h"

UserLog* loginMenu(UserDatabase* userDatabase){
    int choice = 1;
    do {
        printf("Please enter your username:\n");
        char *username = scanChar();
        printf("Please enter your password:\n");
        int password = scanInt();
        UserLog *userLog = login(userDatabase, username, password);
        switch (userLog->userType){
            case STUDENT:
            case PROVIDER:
            case ADMIN:
            case SUPPORT_STAFF:
                return userLog;
            case UNKNOWN:
                if(userLog->userID == -1){
                    printf("The username does not exist.\n");
                    printf("Press 0 to return to main menu, any other number to try again.\n");
                    choice = scanInt() == 0 ? 0 : 1;
                }
        }
    } while (choice);
return NULL;
}

void registerMenu(UserDatabase* userDatabase, College* college){
    registerUser:
    printf("Please enter a username, or 0 to return to maim menu:\n");
    char * username = scanChar();
    if(strncmp(username, "0", 1)==0) return;
    Student* testStudent = createStudent("juan", 123, 321, "123", 5);
    if(uDatabaseAddStudent(userDatabase, testStudent, username) != 1){
            printf("That username is taken, please try again.\n");
            destroyStudent(testStudent);
            goto registerUser;
        }else uDatabaseRemoveStudent(userDatabase, testStudent->userID);
    destroyStudent(testStudent);
    enterPassword:
    printf("Please enter a numerical password:\n");
    int password = scanInt();
    printf("Please confirm your password:\n");
    int confirmedPassword = scanInt();
    if(confirmedPassword != password) {
        printf("Your password didn't match, please try again.\n");
        goto enterPassword;
    }
    printf("Please enter your full name:\n");
    char* name = scanChar();
    printf("Please enter your phone number:\n");
    int phoneNumber = scanInt();
    while(phoneNumber <= 0){
        printf("Please enter a valid number.\n");
        phoneNumber = scanInt();
    }
    printf("available careers are: \n");
    for(int i=0; i< college->amountOfCareers; i++){
printf("%d. %s.\n", i+1, college->availableCareers[i]);
    }
    printf("Please enter your career.\n");
    int selectedCareer = scanInt();
        while(selectedCareer <1 || selectedCareer>college->amountOfCareers){
            printf("Please enter a valid career.\n");
            phoneNumber = scanInt();
        }
    Student* student = createStudent(name, password, phoneNumber, college->availableCareers[selectedCareer-1], 5);
    if(uDatabaseAddStudent(userDatabase, student, username) != 1){
        printf("That username is taken, please try again.\n");
        destroyStudent(student);
        goto registerUser;
    }
}
