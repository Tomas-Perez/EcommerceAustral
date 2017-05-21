//
// Created by José Rojas on 18/5/17.
//

#ifndef ECOMMERCEAUSTRAL_BANKACCOUNT_H
#define ECOMMERCEAUSTRAL_BANKACCOUNT_H

#include "OperationCertificate.h"

typedef struct BankAccount{
    int bankAccountID;
    double balance;
    double maintenance;
    int userID;
    char* openedDate;
    long timeStamp;
} BankAccount;

BankAccount* createBankAccount(int bankAccountID, double balance, double maintenance, int userID);
OperationCertificate* withdrawMoney(BankAccount* bankAccount, double amount);
OperationCertificate* depositMoney(BankAccount* bankAccount, double amount);
void updateMaintenance(BankAccount* bankAccount, double maintenance);
void freeBankAccount(BankAccount* bankAccount);

#endif
