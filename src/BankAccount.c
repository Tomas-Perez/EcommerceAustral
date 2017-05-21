

#include "BankAccount.h"
#include <stdlib.h>
#include <time.h>
#include <mem.h>

BankAccount* createBankAccount(int bankAccountID,double balance, double maintenance,int userID){

    BankAccount* result = malloc(sizeof(BankAccount));

    result->bankAccountID = bankAccountID;
    result->balance = balance;
    result->maintenance = maintenance;
    result->userID = userID;

    time_t currentTime = time(NULL);
    result->timeStamp=currentTime;


    time_t calendarTime;
    time(&calendarTime);

    result->openedDate= malloc(sizeof(char*));
    strcpy(result->openedDate,ctime(&calendarTime));

    return result;
}

OperationCertificate* withdrawMoney(BankAccount* bankAccount, double amount){
    bankAccount-> balance -= amount;
    OperationCertificate* result = createOperationCertificate(bankAccount->bankAccountID, 1,amount);

    return result;
}

OperationCertificate* depositMoney(BankAccount* bankAccount, double amount){
    bankAccount-> balance += amount;
    OperationCertificate* result = createOperationCertificate(bankAccount->bankAccountID, 0,amount);
    return result;
}

void freeBankAccount(BankAccount* bankAccount){
    free(bankAccount->openedDate);
    free(bankAccount);
}

