
#ifndef ECOMMERCEAUSTRAL_BANKACCOUNT_H
#define ECOMMERCEAUSTRAL_BANKACCOUNT_H

#include "OperationCertificate.h"

typedef struct BankAccount{
    int bankAccountID;
    double balance;
    double maintenance;
    char* openedDate;
    long timeStamp;
} BankAccount;

BankAccount* createBankAccount(int bankAccountID, double balance, double maintenance);
OperationCertificate* withdrawMoney(BankAccount* bankAccount, double amount);
OperationCertificate* depositMoney(BankAccount* bankAccount, double amount);
void applyMaintenance(BankAccount *bankAccount);
void freeBankAccount(BankAccount* bankAccount);

#endif
