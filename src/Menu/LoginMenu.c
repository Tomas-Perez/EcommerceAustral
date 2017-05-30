#include <stdio.h>
#include <stdlib.h>
#include "../Ecommerce/UserDatabase.h"
#include "../Util/ScanUtil.h"

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
                    printf("Press 0 to exit, any other number to try again.\n");
                    choice = scanInt() == 0 ? 0 : 1;
                }
        }
    } while (choice);
    exit(0);
}

void registerMenu(UserDatabase* userDatabase){
    registerUser:
    printf("Please enter your username:\n");
    char * username = scanChar();
    printf("Please enter your password:\n");
    int password = scanInt();
    printf("Please confirm your password:\n");
    int confirmedPassword = scanInt();
    if(confirmedPassword != password) {
        printf("Your password didn't match, please try again.\n");
        goto registerUser;
    }
    printf("Please enter your phone number:\n");
    int phoneNumber = scanInt();
    while(phoneNumber <= 0){
        printf("Please enter a valid number.\n");
        phoneNumber = scanInt();
    }
    printf("Please enter your career.\n");
    char* career = scanChar();
    Student* student = createStudent(username, password, phoneNumber, career, 5);
    if(uDatabaseAddStudent(userDatabase, student, username) != 1){
        printf("That username is taken, please try again.\n");
        destroyStudent(student);
        goto registerUser;
    }
}