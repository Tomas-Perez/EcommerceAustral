#include "../Ecommerce/UserDatabase.h"
#include "../College/College.h"
#include "../Bank/Bank.h"
#include "../Ecommerce/SupportDatabase.h"
#include "InputTool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void createSupportStaffMenu(UserDatabase* database){
	char name[51];
		int rc = -1;
		while (rc!=0){
		rc = getLine ("Enter support staff full name, or 0 to return to previous menu: ", name, sizeof(name));
		if(rc==2) printf("50 chars maximum.\n");
		}
		if(strncmp(name, "0", 1)==0) return;
		char username[21];
			rc = -1;
			while (rc!=0){
			rc = getLine ("Enter support staff username: ", username, sizeof(username));
			if(rc==2) printf("20 chars maximum.\n");
			SupportStaff* testStaff = createSupportStaff("juan", 123, 321);
						    if(uDatabaseAddSupportStaff(database, testStaff, username) != 1){
						            printf("That username is taken, please try again.\n");
						            rc=-1;
						        }else uDatabaseRemoveSupportStaff(database, testStaff->userID);
						    destroySupportStaff(testStaff);
			}

		int password=-3;
		int confirmedPassword=-1;
				while (1){
					password = getOption ("enter numerical password: ");
					if(password<0){
						printf("invalid password.\n");
						continue;
					}confirmedPassword = getOption ("confirm your password: ");

			    if(confirmedPassword != password) printf("Your passwords didn't match, please try again.\n");
			    else break;
				}
				int phoneNumber=0;
				while(phoneNumber<1){
					phoneNumber=getOption("enter phoneNumber: ");
					if(phoneNumber<1)printf("invalid phone number. \n");
				}
				SupportStaff* newGuy = createSupportStaff(name, password, phoneNumber);
				uDatabaseAddSupportStaff(database, newGuy, username);
				pauseProgram("Support staff added successfully, press enter key to continue...");
}
void createProviderMenu(UserDatabase* database){
	char name[51];
		int rc = -1;
		while (rc!=0){
		rc = getLine ("Enter provider full name, or 0 to return to previous menu: ", name, sizeof(name));
		if(rc==2) printf("50 chars maximum.\n");
		}
		if(strncmp(name, "0", 1)==0) return;
		char username[21];
			rc = -1;
			while (rc!=0){
			rc = getLine ("Enter provider username: ", username, sizeof(username));
			if(rc==2) printf("20 chars maximum.\n");
			Provider* testProvider = createProvider("juan", 123, 321, 234, 2);
						    if(uDatabaseAddProvider(database, testProvider, username) != 1){
						            printf("That username is taken, please try again.\n");
						            rc=-1;
						        }else uDatabaseRemoveProvider(database, testProvider->userID);
						    destroyProvider(testProvider);
			}

		int password=-3;
		int confirmedPassword=-1;
				while (1){
					password = getOption ("enter numerical password: ");
					if(password<0){
						printf("invalid password.\n");
						continue;
					}confirmedPassword = getOption ("confirm the numerical password: ");

			    if(confirmedPassword != password) printf("Your passwords didn't match, please try again.\n");
			    else break;
				}
				int phoneNumber=0;
				while(phoneNumber<1){
					phoneNumber=getOption("enter phone number: ");
					if(phoneNumber<1)printf("invalid phone number. \n");
				}
				int RIF=0;
				while(RIF<1){
					RIF=getOption("enter RIF number: ");
					if(RIF<1)printf("invalid RIF number. \n");
				}
				Provider* newGuy = createProvider(name, password, phoneNumber, RIF, 10);
				uDatabaseAddProvider(database, newGuy, username);
				pauseProgram("Provider added successfully, press enter key to continue...");
}
void removeSupportMenu(){
	pauseProgram("This hasn't been implemented yet, press enter key to continue...");
}
void removeProviderMenu(){
	pauseProgram("This hasn't been implemented yet, press enter key to continue...");
}
void removeStudentMenu(){
	pauseProgram("This hasn't been implemented yet, press enter key to continue...");
}
void addSubjectMenu(){
	pauseProgram("This hasn't been implemented yet, press enter key to continue...");
}
void addCareerMenu(){
	pauseProgram("This hasn't been implemented yet, press enter key to continue...");
}

void adminMenu(UserDatabase* database, Bank* bank, SupportDatabase* supportDatabase, College* college, int userID){
	for(;;){
	int rc=-1;
			printf("%s\n", "would you like to:\n");
					printf("%s\n", "1. create support account. ");
					printf("%s\n", "2. create provider account. ");
					printf("%s\n", "3. remove support account. ");
					printf("%s\n", "4. remove provider account. ");
					printf("%s\n", "5. remove student account. ");
					printf("%s\n", "6. add a subject. ");
					printf("%s\n", "7. add a career. ");
					printf("%s\n", "0. return to main menu");
					while (rc<0 || rc>7){
						        rc = getOption ("enter option: ");
						        if (rc<0 || rc>7)printf("invalid option. m\n");
						        }
					switch(rc){
					case 1:
						createSupportStaffMenu(database);
						break;
					case 2:
						createProviderMenu(database);
						break;
					case 3:
						removeSupportMenu();
						break;
					case 4:
						removeProviderMenu();
						break;
					case 5:
						removeStudentMenu();
						break;
					case 6:
						addSubjectMenu();
						break;
					case 7:
						addCareerMenu();
						break;
					case 0:
						return;
					}
}
}
