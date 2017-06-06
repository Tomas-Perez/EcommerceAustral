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
void registerMenu(UserDatabase* userDatabase, College* college);


UserLog* loginMenu(UserDatabase* userDatabase);

UserDatabase* userDatabaseSetup(){
	Admin* admin = createAdmin("pepe", 1234, 232323);
	UserDatabase* database = createUserDatabase(10, admin);
	return database;
}


Bank* bankSetup(){
    printf("\nYou are about to create a bank. \n");
    int id = getOption("Enter bank id: ");
    char name[20];
    int rc = -1;
    while (rc != 0) {
        rc = getLine("Enter bank name: ", name, sizeof(name));
    }
    rc = -1;
    char office[20];
    while (rc != 0) {
        rc = getLine("Enter bank office name: ", office, sizeof(office));
    }
    Bank *bank = createBank(id, name, office, 10);
    return bank;
}

College* collegeSetup(){
	printf("\nYou are about to create a college. \n");
		char name[20];
		int rc = -1;
		while (rc!=0){
		rc = getLine ("Enter college name: ", name, sizeof(name));
		}
		char careerName[20];
		rc = -1;
		while (rc!=0){
		rc = getLine ("Enter a career name: ", careerName, sizeof(careerName));
		}
		College* college = createCollege(name, 10);
		addNewCareer(college, careerName);

	return college;
}

SupportDatabase* supportDatabaseSetup(){
	SupportDatabase* database = newSupportDatabase(10);
	return database;
}

typedef struct initialSetup{
    UserDatabase* userDatabase;
    SupportDatabase* supportDatabase;
    Bank* bank;
    College* college;
} InitialSetup;

InitialSetup* predeterminedSetup(){
    InitialSetup* setup = malloc(sizeof(InitialSetup));
    UserDatabase* userDatabase = userDatabaseSetup();
    SupportDatabase* supportDatabase = supportDatabaseSetup();
    Bank* bank = createBank(1, "Santander Rio", "Pilar", 20);
    College* college = createCollege("Austral", 10);
    addNewCareer(college, "Ingenieria");
    addNewCareer(college, "Comunicacion");
    addNewCareer(college, "Abogacia");
    Student* jorge = createStudent("Jorge", 123, 345345, "Ingenieria", 10);
    Student* maria = createStudent("Maria", 123, 345345, "Comunicacion", 10);
    Student* augusto = createStudent("Augusto", 123, 345345, "Abogacia", 10);
    SupportStaff* supportStaff1 = createSupportStaff("Miguel", 123, 3424);
    SupportStaff* supportStaff2 = createSupportStaff("Ernesto", 123, 3424);
    SupportStaff* supportStaff3 = createSupportStaff("Juan", 123, 3424);
    Provider* provider1 = createProvider("Estrada", 123, 456, 4564564, 5);
    Provider* provider2 = createProvider("FedEx", 123, 456, 345786, 5);
    uDatabaseAddStudent(userDatabase, jorge, "jorge");
    uDatabaseAddStudent(userDatabase, maria, "maria");
    uDatabaseAddStudent(userDatabase, augusto, "augusto");
    uDatabaseAddSupportStaff(userDatabase, supportStaff1, "miguel");
    uDatabaseAddSupportStaff(userDatabase, supportStaff2, "ernesto");
    uDatabaseAddSupportStaff(userDatabase, supportStaff3, "juan");
    uDatabaseAddProvider(userDatabase, provider1, "estrada");
    uDatabaseAddProvider(userDatabase, provider2, "fedex");
    BankAccount* bankAccount = createBankAccount(jorge->userID, 5000, 0, jorge->userID);
    BankAccount* adminBankAccount = createBankAccount(userDatabase->admin->userID, 5000, 0, userDatabase->admin->userID);
    addAccount(bank, bankAccount);
    addAccount(bank, adminBankAccount);
    Subject* algebra = createSubject("Algebra 2", "Ingenieria", 5);
    Subject* analisis = createSubject("Analisis 1", "Ingenieria", 5);
    Subject* legal = createSubject("Legal", "Abogacia", 5);
    Subject* tecnicas = createSubject("Tecnicas de comunicacion", "Comunicacion", 5);
    addNewSubject(college, algebra);
    addNewSubject(college, analisis);
    addNewSubject(college, legal);
    addNewSubject(college, tecnicas);
    BookInformation* bookInformation1 = createBookInformation("Algebra For Dummies", 1234, "Gauss");
    BookInformation* bookInformation2 = createBookInformation("Linear Algebra", 5678, "Gauss-Jordan");
    BookInformation* bookInformation3 = createBookInformation("Constitution", 4535, "Congress");
    BookInformation* bookInformation4 = createBookInformation("More Laws", 568, "Lawer N1");
    BookInformation* bookInformation5 = createBookInformation("e to the Pi", 12346, "Euler");
    addNewBook(algebra, bookInformation1);
    addNewBook(algebra, bookInformation2);
    addNewBook(legal, bookInformation3);
    addNewBook(legal, bookInformation4);
    addNewBook(analisis, bookInformation5);
    addBook(provider1, bookInformation1, 5, 200);
    addBook(provider1, bookInformation2, 3, 600);
    addBook(provider2, bookInformation3, 10, 665);
    addBook(provider2, bookInformation4, 8, 450);
    addBook(provider1, bookInformation5, 8, 200);
    SupportMessage* supportMessage = newSupportMessage("How do I buy books?", jorge->userID);
    SupportMessage* supportMessage2 = newSupportMessage("How do I ask questions?", maria->userID);
    addMessage(supportDatabase, supportMessage);
    addMessage(supportDatabase, supportMessage2);
    setup->userDatabase = userDatabase;
    setup->supportDatabase = supportDatabase;
    setup->bank = bank;
    setup->college = college;
    return setup;
}

int main() {
    UserDatabase *userDatabase ;
    Bank *bank;
    College *college;
    SupportDatabase *supportDatabase;
    int option = getOption("Would you like to set the initial parameters (1) or use a predetermined ones (0)?");
    while(option != 1 && option != 0){
        option = getOption("Please select one of the options.");
    }
    if(option) {
        supportDatabase = supportDatabaseSetup();
        userDatabase = userDatabaseSetup();
        bank = bankSetup();
        college = collegeSetup();
    }
    else{
        InitialSetup* initialSetup = predeterminedSetup();
        userDatabase = initialSetup->userDatabase;
        bank = initialSetup->bank;
        college = initialSetup->college;
        supportDatabase = initialSetup->supportDatabase;
    }
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
                registerMenu(userDatabase, college);
                break;
            case 0:
                exit(0);
            default:
                printf("Please enter one of the options\n");
        }
    }
}
