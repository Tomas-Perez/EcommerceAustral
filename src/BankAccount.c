//
// Created by José Rojas on 18/5/17.
//

#include "BankAccount.h"
#include <stdlib.h>
#include <string.h>

BankAccount* createBankAccount(int accountID,double balance, double maintenance,int userID){

    BankAccount* result = malloc(sizeof(BankAccount));

    result->bankAccountID = accountID;
    result->balance = balance;
    result->maintenance = maintenance;
    result->userID = userID;

    return result;
}
OperationCerticate* withdrawMoney(BankAccount* bankAccount, double amount){
    OperationCerticate* result = malloc(sizeof(OperationCerticate));

}

