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
			rc = getLine ("Enter provider username, or 0 to return to previous menu: ", username, sizeof(username));
			if(strncmp(name, "0", 1)==0) return;
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
void removeUserMenu(UserDatabase* database){
	int rc=-1;
	char username[21];
	UserLog* userLog;
	int found =0;
				rc = -1;
				while (1){
				rc = getLine ("Enter student username, or 0 to return to previous menu: ", username, sizeof(username));
				if(strncmp(username, "0", 1)==0) return;
				if(rc==2){
					printf("20 chars maximum.\n");
					continue;
				}
				for(int i=0; i<database->userLogAmount; i++){
					if(database->userLogs[i]->username==username){
						userLog = database->userLogs[i];
						found=1;
						break;
					}
				}if(found==0){
					printf("User not found.");
				}else break;
				}int certainty=-1;
				printf("are you sure you want to remove %s??", userLog->username);
									while (certainty<0 || certainty>1){
										certainty = getOption ("enter 1 if you are, otherwise 0: ");
										        if (certainty<0 || certainty>1)printf("invalid option. m\n");
										        }if(certainty==0)return;
			switch (userLog->userType) {
			                    case STUDENT:
			                    	for(int i = 0; i < database->studentAmount; i++){
			                    	        if(database->students[i]->userID == userLog->userID){
			                    	        	uDatabaseRemoveStudent(database, userLog->userID);
			                    	        	pauseProgram("Student removed successfully, press enter key to continue...");
			                    	        	return;
			                    	        }
			                    	}
			                        break;
			                    case PROVIDER:
			                    	for(int i = 0; i < database->providerAmount; i++){
			                    	        if(database->providers[i]->userID == userLog->userID){
			                    	        	uDatabaseRemoveProvider(database, userLog->userID);
			                    	        	pauseProgram("Provider removed successfully, press enter key to continue...");
			                    	        	return;
			                    	        }
			                    	}
			                        break;
			                    case ADMIN:
			                    	pauseProgram("You can't remove an admin, admins are gods, press enter key to continue...");
			                        return;
			                    case SUPPORT_STAFF:
			                    	for(int i = 0; i < database->supportStaffAmount; i++){
			                    	        if(database->supportStaff[i]->userID == userLog->userID){
			                    	        	uDatabaseRemoveSupportStaff(database, userLog->userID);
			                    	        	pauseProgram("Provider removed successfully, press enter key to continue...");
			                    	        	return;
			                    	        }
			                    	}
			                        break;
			                    case UNKNOWN:
			                        break; //Something went terribly wrong.
			}
	pauseProgram("There was an error while removing the user, press enter key to continue...");
}
void addSubjectMenu(College* college){
	printf("You are about to add a subject to a career: \n");
	printf("available careers are: \n");
	    for(int i=0; i< college->amountOfCareers; i++){
	printf("%d. %s.\n", i+1, college->availableCareers[i]);
	    }
	    int selectedCareer=0;
	    while(selectedCareer<1||selectedCareer>college->amountOfCareers){
	    	selectedCareer=getOption("Please select a career: ");
	    	if(selectedCareer<1||selectedCareer>college->amountOfCareers) printf("Please select a valid career.\n");;
	    }
	int rc=-1;
	char subjectName[21];
	while (rc!=0){
	rc = getLine ("Enter subject name: ", subjectName, sizeof(subjectName));
	if(rc==2)printf("20 chars maximum.\n");
	}
    int maxStudents=0;
    while(maxStudents<1||maxStudents>100){
    	maxStudents=getOption("Please enter student capacity: ");
    	if(maxStudents<1||maxStudents>100) printf("Between 1 and 100 students please.\n");;
    }
	Subject* newSubject=createSubject(subjectName, college->availableCareers[selectedCareer-1], maxStudents);
	addNewSubject(college, newSubject);
	pauseProgram("Subject added successfully, press enter key to continue...");
}
void addCareerMenu(College* college){
	int rc=-1;
	char careerName[21];
	while (rc!=0){
	rc = getLine ("Enter a career name: ", careerName, sizeof(careerName));
	if(rc==2)printf("20 chars maximum.\n");
	}
	addNewCareer(college, careerName);
	pauseProgram("Career added successfully, press enter key to continue...");
}
void addBookInfoMenu(College* college){
	if(college->amountOfCareers==0){
						printf("There are no careers, please create one.\n");
						addCareerMenu(college);
					}
	printf("select a subject in which to add the book: \n");
	printf("available subjects are: \n");
	for(int i=0; i< college->amountOfSubjects; i++){
			printf("%d. %s.\n", i+1, college->subjects[i]->name);
			    }
    int selectedSubject=0;
    while(selectedSubject<1||selectedSubject>college->amountOfSubjects){
    	selectedSubject=getOption("Please select a subject: ");
    	if(selectedSubject<1||selectedSubject>college->amountOfSubjects) printf("Please select a valid subject.\n");;
    }
	        	char title[51];
	        			int rc = -1;
	        			while (rc!=0){
	        			rc = getLine ("Enter title: ", title, sizeof(title));
	        			if(rc==2) printf("50 chars maximum.\n");
	        			}
	        			char author[51];
	        					rc = -1;
	        					while (rc!=0){
	        					rc = getLine ("Enter author: ", author, sizeof(author));
	        					if(rc==2) printf("50 chars maximum.\n");
	        					}
	        					int ISBN=0;
	        									while(ISBN<1){
	        										ISBN=getOption("enter ISBN number: ");
	        										if(ISBN<1)printf("invalid ISBN number. \n");
	        									}
	        	BookInformation* newBook = createBookInformation(title, ISBN, author);
	        	addNewBook(college->subjects[selectedSubject-1], newBook);
	        	pauseProgram("Book added successfully, press enter key to continue...");

}
void adminMenu(UserDatabase* database, Bank* bank, SupportDatabase* supportDatabase, College* college, int userID){
	printf("\nWelcome!\n");
	for(;;){
	int rc=-1;
			printf("%s\n", "would you like to:\n");
					printf("%s\n", "1. create support account. ");
					printf("%s\n", "2. create provider account. ");
					printf("%s\n", "3. remove support, provider or student account. ");
					printf("%s\n", "4. add a subject. ");
					printf("%s\n", "5. add a career. ");
					printf("%s\n", "6. add book information. ");
					printf("%s\n", "0. return to main menu");
					while (rc<0 || rc>6){
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
						removeUserMenu(database);
						break;
					case 4:
						addSubjectMenu(college);
						break;
					case 5:
						addCareerMenu(college);
						break;
					case 6:
						addBookInfoMenu(college);
						break;
					case 0:
						return;
					}
}
}
