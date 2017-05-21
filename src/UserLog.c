#include <stdlib.h>
#include <string.h>
#include "UserLog.h"

/*
 * Description: Contains all functions related to UserLog.
 */

UserLog* createUserLog(UserType userType, int userID, char* username){
    UserLog* result = malloc(sizeof(UserLog));

    result->userType = userType;
    result->userID = userID;

    result->username = malloc(sizeof(char)*strlen(username)+1);
    strcpy(result->username, username);

    return result;
}

void destroyUserLog(UserLog* userLog){
    free(userLog->username);
    free(userLog);
}