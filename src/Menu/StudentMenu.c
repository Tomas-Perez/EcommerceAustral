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
            eCommerceOption(database, bank, college, userID);
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
                printf("%s%s", books->books[i]->title, "\n");
            }

            printf("SUBJECTS: \n");
            ArrayOfSubjects* subjects = getSubjectsOfStudent(college, userID);

            for (i = 0; i < subjects->amountOfSubjects; i++) {
                printf("%s%s", subjects->subjects[i]->name, "\n");
            }
            break;
        case 2: ;
        	ArrayOfSubjects* availableSubjects= getCareerSubjects(college, student->career);
        	if(availableSubjects->amountOfSubjects==0){
        		printf("your career has no available subjects\n");
				break;
        	}
        	printf("Available subjects are: \n");

        	for(int i=0; i< availableSubjects->amountOfSubjects; i++) printf ("%d. %s.\n", i+1, availableSubjects->subjects[i]->name);
        	int selectedSubject = -1;
        	while (selectedSubject<1 || selectedSubject>availableSubjects->amountOfSubjects){
        	printf("Enter your option: \n");
        	selectedSubject=scanInt();
            if(selectedSubject<1 || selectedSubject>availableSubjects->amountOfSubjects)
            	printf("invalid option.");

            }
            enrollStudentInSubject(college, availableSubjects->subjects[selectedSubject-1]->subjectID, userID);
            break;
        default:
            printf("Invalid option");
            break;
    }

}

void eCommerceOption(UserDatabase* database, Bank* bank, College* college, int userID) {
    Cart* cart = createCart(10, userID);
    ArrayOfBooks* array = getBooksOfStudent(college, userID);
    Student* student = uDatabaseGetStudent(database, userID);

    printf("Enter an option: \n");
    printf("1. Add or remove books to cart \n");
    printf("2. Checkout bill \n");
    printf("3. Shopping history \n");
    printf("4. Support query \n");

    int option = scanInt();

    switch (option) {
        case 1:
            printf("1. Show books: \n");
            printf("2. Add book \n");
            printf("3. Remove book \n");
            printf("4. Remove all books \n");
            int option2 = scanInt();
            switch (option2) {
                case 1:
                    printf("Books: \n");
                    int i;
                    int j;
                    for (i = 0; i < database->providerAmount; i++) {
                        for (j = 0; j < database->providers[i]->amountOfBooks; j++) {
                            printf("%s\n", database->providers[i]->books[j]->bookInfo->title);
                        }
                    }
                	break;
                case 2:
                    printf("Enter the name of the book you want to buy\n");
                    char* nameBook = scanChar();
                    int k;
                    for (j = 0; j < database->providerAmount; j++) {
                        for (k = 0; k < database->providers[j]->amountOfBooks; k++) {
                            if (database->providers[j]->books[k]->bookInfo->title == nameBook) {
                                cartAddBook(cart, database->providers[j]->books[i], 1);
                                printf("Book bought!\n");
                                break;
                            }
                        }
                    }
                    printf("Sorry, the book does not exist\n");
                	break;
                case 3:
                    printf("Enter the name of the book you want to remove: \n");
                    char* nameBook2 = scanChar();
                    for (k = 0; k < cart->amountOfBooks; k++) {
                        if (cart->pBooks[i]->bookInfo->title == nameBook2) {
                            cart->pBooks[i] = NULL;
                            printf("Book deleted successfully");
                        }
                    }
                    printf("You did not buy that book");
                case 4:
                    cartRemoveAllBooks(cart);
                    printf("Deleted books");
                    break;
                default:
                    printf("Invalid option\n");
            }
            break;
        case 2:
        	break;
        case 3:
            printf("Shopping history: \n");
            int j;
            for (j = 0; j < student->maxCapacityOfPayments; j++) {
                if (student->purchaseHistory[j] != NULL) {
                    printf("Amount of books: %i\n", student->purchaseHistory[j]->invoice->amountOfBooks);
                    printf("Id: %i\n", student->purchaseHistory[j]->invoice->id);
                    printf("Student id: %i\n", student->purchaseHistory[j]->invoice->studentID);
                    printf("Total Amount: %i\n", student->purchaseHistory[j]->invoice->totalAmount);

                    printf("Pa0yment data: %i\n", student->purchaseHistory[j]->paymentMethod->paymentData);
                    printf("Payment id: %i\n", student->purchaseHistory[j]->paymentMethod->paymentID);
                }
            }
        	break;
        case 4:
            printf("Support query: \n");
            printf("Enter an option: \n");
            printf("1. Ask \n");
            printf("2. See answer \n");
            int option3 = scanInt();
            switch (option3) {
                case 1:
                    printf("Leave your question: \n");
                    char* question;
                    question = scanChar();
                    SupportMessage* supportMessage = newSupportMessage(question, student->userID);
                    printf("Question submitted!");
                    break;
                case 2:
                   if (supportMessage->isAnswered == 1) {
                       printf("Answer: %s", supportMessage->answer);
                   } else {
                       printf("They have not answered your question");  
                   }
                    break;
                default:
                    printf("Invalid option");
                    break;
            }

        default:
            printf("Invalid option");
            break;
    }
}

void bankOption(UserDatabase* database, Bank* bank, int userID) {
    printf("Enter an option: \n");
    printf("1. Create account \n");
    printf("2. Deposit \n");
    printf("3. Withdraw \n");
    printf("4. Transaction history \n");

    int option = scanInt();

    switch (option) {

        case 1:
            addAccount(bank, createBankAccount(userID, 0.0, 0.0));
            printf("Successfully created bank account!\n");
        	break;
        case 2:
            printf("Enter amount: \n");
            double amount1;
            scanf("%lf", &amount1);
            Transaction* transaction1 = deposit_Money(bank, userID, amount1);
            printf("transaction amount is %f, it should be %f, date is %s", transaction1->amount, amount1, transaction1->date);
            break;
        case 3:
            printf("Enter amount: \n");
            double amount2;
            scanf("%lf", &amount2);
            Transaction* transaction2 = withdraw_Money(bank, userID, amount2);
            printf("transaction amount is %f, it should be %f, date is %s", transaction2->amount, amount2, transaction2->date); //testing transaction
            break;
        case 4:
        	break;
		default:
            printf("Invalid option");
            break;
    }
}

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
