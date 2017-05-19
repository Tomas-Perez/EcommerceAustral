

#include "BankAccount.h"
#include <stdlib.h>

BankAccount* createBankAccount(int bankAccountID,double balance, double maintenance,int userID){

    BankAccount* result = malloc(sizeof(BankAccount));

    result->bankAccountID = bankAccountID;
    result->balance = balance;
    result->maintenance = maintenance;
    result->userID = userID;
    result->openedDate;
    result->timeStamp;
    return result;
}
OperationCertificate* withdrawMoney(BankAccount* bankAccount, double amount){
    OperationCertificate* result = malloc(sizeof(OperationCertificate));

    return result;
}

OperationCertificate * depositMoney(BankAccount* bankAccount, double amount){
    OperationCertificate* result = malloc(sizeof(OperationCertificate));

    return result;
}

void freeBankAccount(BankAccount* bankAccount){
    free(bankAccount);
}

