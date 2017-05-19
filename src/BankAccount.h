//
// Created by José Rojas on 18/5/17.
//

#ifndef ECOMMERCEAUSTRAL_BANKACCOUNT_H
#define ECOMMERCEAUSTRAL_BANKACCOUNT_H

//#include <sspi.h>
//#include "OperationCertificate"

typedef struct BankAccount{
    int bankAccountID;
    double balance;
    double maintenance;
    int userID;
    char* openedDate;
    long timestamp; //Hay una explicacion del timestamp en el README
}BankAccount;

//No pusheen cosas en rojo por favor, si no el resto no puede correr nada hasta comentar

BankAccount* createBankAccount(int bankAccountID, double balance, double maintenance, int userID);
//OperationCertificate* withdrawMoney(BankAccount* bankAccount, double amount);
//OperationCertificate* depositMoney(BankAccount* bankAccount, double amount);
void updateMaintenance(BankAccount* bankAccount, double maintenance);

#endif
