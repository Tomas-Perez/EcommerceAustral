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
					        if (rc<0 || rc>2)printf("invalid option. m\n");
					        }

					printSubjects(college);
					int selectedSubject = 0;
					while (selectedSubject<1 || selectedSubject>college->amountOfSubjects){
						selectedSubject = getOption ("enter option: ");
						        if (selectedSubject<1 || selectedSubject>college->amountOfSubjects) printf("invalid option. m\n");
						        }
					printBookInformation(college, selectedSubject-1);
					int selectedBook = 0;
					while (selectedBook<1 || selectedBook>college->subjects[selectedSubject-1]->amountOfBooks){
						selectedBook = getOption ("enter option: ");
						        if (selectedBook<1 || selectedBook>college->subjects[selectedSubject-1]->amountOfBooks) printf("invalid option. m\n");
						        }
					int quantity = 0;
					while (quantity<1){
						quantity = getOption ("enter quantity: ");
						        if (quantity<1) printf("positive values please. m\n");
						        }
					if (rc==1){
					int price = 0;
					while (price<1){
						price = getOption ("enter price: $");
						       if (price<1) printf("positive values please. m\n");
						        }
					addBook(provider, college->subjects[selectedSubject-1]->books[selectedBook-1], quantity, price);
						pauseProgram("books added successfully, press enter key to continue.");
				}
				if(rc==2){
					removeBook(provider, college->subjects[selectedSubject-1]->books[selectedBook-1]->ISBN, quantity);
				}
}

