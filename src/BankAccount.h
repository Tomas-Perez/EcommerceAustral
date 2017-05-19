//
// Created by José Rojas on 18/5/17.
//

#ifndef ECOMMERCEAUSTRAL_BANKACCOUNT_H
#define ECOMMERCEAUSTRAL_BANKACCOUNT_H

typedef struct BankAccount{
    int bankAccountID;
    double balance;
    double maintenance;
    int userID;
    char* openedDate;
    long timestamp;
}BankAccount;

//No pusheen cosas en rojo por favor, si no el resto no puede correr nada hasta comentar

BankAccount* createBankAccount(int accountID, double balance, double maintenance, int userID);
//OperationCerticate* withdrawMoney(BankAccount* bankAccount, double amount);
//OperationCerticate* depositMoney(BankAccount* bankAccount, double amount);
void updateMaintenance(BankAccount* bankAccount, double maintenance);

#endif
