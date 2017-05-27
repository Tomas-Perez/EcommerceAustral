#ifndef ECOMMERCEAUSTRAL_USERLOG_H
#define ECOMMERCEAUSTRAL_USERLOG_H

/*
 * Description: UserLog is an ADT used for user login in the Ecommerce system.
 */

typedef enum {STUDENT, ADMIN, PROVIDER, SUPPORT_STAFF, UNKNOWN} UserType;

typedef struct UserLog{
    UserType userType;
    int userID;
    char* username;
}UserLog;

UserLog* createUserLog(UserType userType, int userID, char* username);
void destroyUserLog(UserLog* userLog);


#endif //ECOMMERCEAUSTRAL_USERLOG_H
