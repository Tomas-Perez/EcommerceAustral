#include "BankAccount.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

BankAccount* createBankAccount(int bankAccountID,double balance, double maintenance){

    BankAccount* result = malloc(sizeof(BankAccount));

    result->bankAccountID = bankAccountID;
    result->balance = balance;
    result->maintenance = maintenance;

    time_t t = time(NULL);
    result->timeStamp = t;
    struct tm* tm1 = localtime(&t);
    char* tempDate = asctime(tm1);
    result->openedDate = malloc(sizeof(char*)*strlen(tempDate)+1);
    strcpy(result->openedDate, tempDate);

    return result;
}

/**
 * Substract amount of money from account, if it is possible.
 * @param bankAccount
 * @param amount
 * @return operationCertificate with the operation data.
 */
OperationCertificate* withdrawMoney(BankAccount* bankAccount, double amount){
    bankAccount-> balance -= amount;
    OperationCertificate* result = createOperationCertificate(bankAccount->bankAccountID, 1,amount);

    return result;
}

/**
 * sums up amount of money in account. If it is possible.
 * @param bankAccount
 * @param amount
 * @return operationCertificate with the operation data.
 */
OperationCertificate* depositMoney(BankAccount* bankAccount, double amount){
    bankAccount-> balance += amount;
    OperationCertificate* result = createOperationCertificate(bankAccount->bankAccountID, 0,amount);
    return result;
}

/**
 * Frees up Bank memory space.
 * @param bankAccount
 */
void freeBankAccount(BankAccount* bankAccount){
    free(bankAccount->openedDate);
    free(bankAccount);
}

