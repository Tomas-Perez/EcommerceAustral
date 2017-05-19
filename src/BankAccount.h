//
// Created by José Rojas on 18/5/17.
//

#ifndef ECOMMERCEAUSTRAL_BANKACCOUNT_H
#define ECOMMERCEAUSTRAL_BANKACCOUNT_H

#include <sspi.h>
#include "OperationCertificate"

typedef struct BankAccount{
    int bankAccountID;
    double balance;
    double maintenance;
    int userID;
    id openedDate;
    TimeStamp timeStamp;
} BankAccount;

BankAccount* createBankAccount(int bankAccountID, double balance, double maintenance, int userID);
OperationCertificate* withdrawMoney(BankAccount* bankAccount, double amount);
OperationCertificate* depositMoney(BankAccount* bankAccount, double amount);
void updateMaintenance(BankAccount* bankAccount, double maintenance);

#endif
