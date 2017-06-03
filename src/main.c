#include <stdlib.h>
#include <stdio.h>
#include "Ecommerce/UserLog.h"
#include "Ecommerce/UserDatabase.h"
#include "Bank/Bank.h"
#include "College/College.h"
#include "Util/ScanUtil.h"
#include "Ecommerce/SupportDatabase.h"
#include "Menu/InputTool.h"


void studentMenu(UserDatabase* database, Bank* bank, SupportDatabase* supportDatabase, College* college, int userID);
void providerMenu(UserDatabase* database, College* college, int userID);
void supportStaffMenu(UserDatabase* database, SupportDatabase* supportDatabase, int userID);
void adminMenu(UserDatabase* database, Bank* bank, SupportDatabase* supportDatabase, College* college, int userID);
void registerMenu(UserDatabase* userDatabase);


UserLog* loginMenu(UserDatabase* userDatabase);

UserDatabase* userDatabaseSetup(){
	Admin* admin = createAdmin("pepe", 123, 232323);

	UserDatabase* database = createUserDatabase(10, admin);
	return database;
}

Bank* bankSetup(){
	printf("\nYou are about to create a bank. \n");
	int id=getOption("Enter bank id: ");
	char name[20];
	int rc = -1;
	while (rc!=0){
	rc = getLine ("Enter bank name: ", name, sizeof(name));
	}
	rc =-1;
	char office[20];
	while (rc!=0){
	rc = getLine ("Enter bank office name: ", office, sizeof(office));
	}
	Bank* bank = createBank( id, name, office, 10);
	return bank;
}

College* collegeSetup(){
	printf("\nYou are about to create a college. \n");
		char name[20];
		int rc = -1;
		while (rc!=0){
		rc = getLine ("Enter college name: ", name, sizeof(name));
		}

	College* college = createCollege(name, 10);
	return college;
}

SupportDatabase* supportDatabaseSetup(){
	SupportDatabase* database = newSupportDatabase(10);
	return database;
}

int main() {
    UserDatabase* userDatabase = userDatabaseSetup();
    Bank* bank = bankSetup();
    College* college = collegeSetup();
    SupportDatabase* supportDatabase = supportDatabaseSetup();
    while(1) {
        printf("1. Log in\n");
        printf("2. Register\n");
        printf("0. Exit\n");
        int choice = scanInt();
        switch (choice){
            case 1: {
                UserLog *userLog = loginMenu(userDatabase);
                if(userLog==NULL) continue;
                switch (userLog->userType) {
                    case STUDENT:
                        studentMenu(userDatabase, bank, supportDatabase, college, userLog->userID);
                        break;
                    case PROVIDER:
                        providerMenu(userDatabase, college, userLog->userID);
                        break;
                    case ADMIN:
                        adminMenu(userDatabase, bank, supportDatabase, college, userLog->userID);
                        break;
                    case SUPPORT_STAFF:
                        supportStaffMenu(userDatabase, supportDatabase, userLog->userID);
                        break;
                    case UNKNOWN:
                        exit(1); //Something went terribly wrong.
                }
            }
                break;
            case 2:
                registerMenu(userDatabase);
                break;
            case 0:
                exit(0);
            default:
                printf("Please enter one of the options\n");
        }
    }
}
