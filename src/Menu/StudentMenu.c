#include "../Ecommerce/UserDatabase.h"
#include "../Bank/Bank.h"
#include "../College/College.h"
#include "../Ecommerce/SupportDatabase.h"
#include "StudentMenu.h"
#include "../Util/ScanUtil.h"
#include <stdio.h>

void studentMenu(UserDatabase* database, Bank* bank, SupportDatabase* supportDatabase, College* college, int userID){
    Student* student = uDatabaseGetStudent(database, userID);
    printf("Enter an option: \n");
    printf("1. Campus \n");
    printf("2. E-Commerce \n");
    printf("3. Bank \n");
    printf("4. Edit information \n");

    int option = scanInt();

    switch (option) {
        case 1:
            campusOption(database, college, userID);
            break;
        case 2:
            eCommerceOption(database, bank);
            break;
        case 3:
            bankOption(database, bank, userID);
            break;
        case 4:
            editInformationOption(database, student);
            break;
        default:
            printf("Invalid option");
            break;
    }
}

// Ok
void campusOption(UserDatabase* database, College* college, int userID) {
	Student* student =uDatabaseGetStudent(database, userID);
    printf("Enter an option: \n");
    printf("1. Show books and subjects \n");
    printf("2. Subscribe to subjects \n");

    int option = scanInt();

    switch (option) {
        case 1:
            printf("BOOKS: \n");
            ArrayOfBooks* books = getBooksOfStudent(college, userID);
            int i;
            for (i = 0; i < books->amountOfBooks; i++) {
                printf("%s+%s", books->books[i]->title, "\n");
            }

            printf("SUBJECTS: \n");
            ArrayOfSubjects* subjects = getSubjectsOfStudent(college, userID);

            for (i = 0; i < subjects->amountOfSubjects; i++) {
                printf("%s+%s", subjects->subjects[i]->name, "\n");
            }
            break;
        case 2:
        	printf("Available subjects are: \n");
        	ArrayOfSubjects* availableSubjects= getCareerSubjects(college, student->career);
        	for(int i=0; i< availableSubjects->amountOfSubjects; i++) printf ("%d. %s.\n", i+1, availableSubjects->subjects[i]->name);
        	int selectedSubject = -1;
        	while (selectedSubject<1 || selectedSubject>availableSubjects->amountOfSubjects){
        	printf("Enter your option: \n");
            if(selectedSubject<1 || selectedSubject>availableSubjects->amountOfSubjects) printf("invalid option.");
            }
            enrollStudentInSubject(college, availableSubjects->subjects[selectedSubject-1]->subjectID, userID);
            break;
        default:
            printf("Invalid option");
            break;
    }

}

// terminar
void eCommerceOption(UserDatabase* database, Bank* bank) {
    printf("Enter an option: \n");
    printf("1. Add or remove books to cart \n");
    printf("2. Checkout bill \n");
    printf("3. Shopping history \n");
    printf("4. Support query \n");

    int option = scanInt();

    switch (option) {
        case 1:
            printf("1. Add book \n");
            printf("2. Remove book \n");
            printf("3. Remove all books \n");
            int option2 = scanInt();
            switch (option2) {
                case 1:
                    // No tengo forma de obtener el cart de cada user
                    //cartAddBook();
                	break;
                case 2:
                	break;
                    //cartRemoveBook();
                case 3:
                    //cartRemoveAllBooks();
                	break;
                default:
                    printf("Invalid option");
            }
            break;
        case 2:
        	break;
        case 3:
        	break;
        case 4:
        	break;
        default:
            printf("Invalid option");
            break;
    }
}

// terminar
void bankOption(UserDatabase* database, Bank* bank, int userID) {
    printf("Enter an option: \n");
    printf("1. Create account \n");
    printf("2. Deposit \n");
    printf("3. Withdraw \n");
    printf("4. Transaction history \n");

    int option = scanInt();

    switch (option) {

        case 1:
            addAccount(bank, createBankAccount(userID, 0.0, 0.0, userID));
            printf("Successfully created bank account!");
        	break;
        case 2:
            printf("Enter amount: \n");
            double amount1;
            scanf("%lf", &amount1);
            Transaction* transaction1 = deposit_Money(bank, userID, amount1);
            //printf("transaction amount is %f, it should be %f, date is %s", transaction1->amount, amount1, transaction1->date); //testing transaction
            break;
        case 3:
            printf("Enter amount: \n");
            double amount2;
            scanf("%lf", &amount2);
            Transaction* transaction2 = withdraw_Money(bank, userID, amount2);
            //printf("transaction amount is %f, it should be %f, date is %s", transaction2->amount, amount2, transaction2->date); //testing transaction
            break;
        case 4:
           // transactionHistiy(bank, bankAccuntID);
        	break;
		default:
            printf("Invalid option");
            break;
    }
}


// Ok
void editInformationOption(UserDatabase* database, Student* student) {
    printf("Enter an option: \n");
    printf("1. Change password \n");
    printf("2. Change name \n");
    printf("3. Change phone number \n");

    int option = scanInt();

    switch (option) {
        case 1:
            printf("Enter a new password: \n");
            int newPassword = scanInt();
            student->password = newPassword;
            break;
        case 2:
            printf("Enter a new name: \n");
            char *newName = scanChar();
            student->name = newName;
            break;
        case 3:
            printf("Enter a new phone number: \n");
            int newPhoneNumber = scanInt();
            student->phoneNumber = newPhoneNumber;
            break;
        default:
            printf("Invalid option");
            break;
    }
}
