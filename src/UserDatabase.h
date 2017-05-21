#ifndef ECOMMERCEAUSTRAL_USERDATABASE_H
#define ECOMMERCEAUSTRAL_USERDATABASE_H

#include "Provider.h"
#include "Student.h"
#include "Admin.h"
#include "SupportStaff.h"
#include "UserLog.h"

/*
 * Description: UserDatabase is an ADT containing the user data for the Ecommerce system, it stores an admin, multiple
 * students, providers and supportStaff, as well as userLogs used for logging in.
 */

typedef struct UserDatabase{
    Admin* admin;
    int idGenerator;

    Student** students;
    int studentAmount;
    int studentCapacity;

    Provider** providers;
    int providerAmount;
    int providerCapacity;

    SupportStaff** supportStaff;
    int supportStaffAmount;
    int supportStaffCapacity;

    UserLog** userLogs;
    int userLogAmount;
    int userLogCapacity;

}UserDatabase;

UserDatabase* createUserDatabase(int initialCapacity, Admin *admin);

int uDatabaseAddStudent(UserDatabase* userDatabase, Student* student, char* username);
int uDatabaseAddProvider(UserDatabase* userDatabase, Provider* provider, char* username);
int uDatabaseAddSupportStaff(UserDatabase* userDatabase, SupportStaff* supportStaff, char* username);

Student* uDatabaseGetStudent(UserDatabase* userDatabase, int userID);
Provider* uDatabaseGetProvider(UserDatabase* userDatabase, int userID);
SupportStaff* uDatabaseGetSupportStaff(UserDatabase* userDatabase, int userID);

void uDatabaseRemoveStudent(UserDatabase* userDatabase, int userID);
void uDatabaseRemoveProvider(UserDatabase* userDatabase, int userID);
void uDatabaseRemoveSupportStaff(UserDatabase* userDatabase, int userID);

UserLog* login(UserDatabase* database, char* username, int password);

void destroyUserDatabase(UserDatabase* userDatabase);

#endif //ECOMMERCEAUSTRAL_USERDATABASE_H
