#include "../Ecommerce/UserDatabase.h"
#include "../College/College.h"
#include <stdio.h>
#include "InputTool.h"

void printSubjects(College* college){
	printf("select subject:\n");
	for(int i=0; i< college->amountOfSubjects; i++){
			printf("%d. %s\n", i+1,college->subjects[i]->name);
	}
	}

void printBookInformation(College* college, int subjectPlaceInArray){
		for (int i=0; i<college->subjects[subjectPlaceInArray]->amountOfBooks; i++){
			printf("%d. book title: %s, ISBN: %d\n", i+1,college->subjects[subjectPlaceInArray]->books[i]->title ,college->subjects[subjectPlaceInArray]->books[i]->ISBN);
	}
}
void providerMenu(UserDatabase* database, College* college, int userID){
	Provider* provider = uDatabaseGetProvider(database, userID);
	int rc=-1;
		printf("%s\n", "would you like to:\n");
				printf("%s\n", "1. addd books. ");
				printf("%s\n", "2. remove books. ");
				printf("%s\n", "0. return to main menu");
				while (rc<0 || rc>2){
					        rc = getOption ("enter option: ");
					        }

					printSubjects(college);
					int selectedSubject = 0;
					while (selectedSubject<1 || selectedSubject>college->amountOfSubjects){
						        rc = getOption ("enter option: ");
						        }
					printBookInformation(college, selectedSubject-1);
					int selectedBook = 0;
					while (selectedBook<1 || selectedBook>college->subjects[selectedSubject-1]->amountOfBooks){
						        rc = getOption ("enter option: ");
						        }
					int quantity = 0;
					while (quantity<1){
						        rc = getOption ("enter quantity: ");
						        }
					if (rc==1){
					int price = 0;
					while (price<1){
						        rc = getOption ("enter price: $");
						        }
					addBook(provider, college->subjects[selectedSubject-1]->books[selectedBook-1], quantity, price);
						pauseProgram("books added successfully, press enter key to continue.");
				}
				if(rc==2){
					removeBook(provider, college->subjects[selectedSubject-1]->books[selectedBook-1]->ISBN, quantity);
				}
}

