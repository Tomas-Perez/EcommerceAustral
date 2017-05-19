//
// Created by José Rojas on 18/5/17.
//

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

typedef struct BankAccount{
    int bankAccountID;
    double balance;
    double maintenance;
    int userID;


};

BankAccount* createBankAccount(int accountID, double balance, double maintenance, int userID);
OperationCerticate* withdrawMoney(BankAccount* bankAccount, double amount);
OperationCerticate* depositMoney(BankAccount* bankAccount, double amount);
void updateMaintenance(BankAccount* bankAccount, double maintenance);
//int* getAccountID(BankAccount* bankAccount);
//double* getBalance(BankAccount* bankAccount);
//double* getMaintenanceFee(BankAccount* bankAccount);
//int* getUserID(BankAccount* bankAccount);
//long* getTimeStamp(BankAccount* bankAccount);
//char* getOpenedData(BankAccount* bankAccount);
//void freeBankAccount(BankAccount* bankAccount);


#endif
