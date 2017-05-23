

#include <stdlib.h>
#include "Transaction.c"
#include "BankAccount.c"
#include "Bank.h"

Bank* newBank(int id, char name[], char office[], Transaction* transactions[], BankAccount* bankAccounts[]){
    Bank* result= malloc(sizeof(Bank));
    /*
    result->id = (int) malloc(sizeof(int));
    result->name = malloc(sizeof(char[]));
    result->office = malloc(sizeof(char[]));
    result->transactions = malloc(sizeof(Transaction[]));
    result->bankAccounts = malloc(sizeof(BankAccount[]));

    result->id = id;
    result->name = name;
    result->office = office;
    result->transactions = transactions;
    result->bankAccounts = bankAccounts;
     */

    return result;
}

OperationCertificate* withdrawMoneyy(Bank* bank, int accountId, double amount){
    OperationCertificate* result;

    for(int i=0; sizeof(bank->bankAccounts); i++){
        if(bank->bankAccounts[i]->bankAccountID == accountId){
            result = withdrawMoney(bank->bankAccounts[i], amount);
            break;
        }
    }

    return result;
}


OperationCertificate* depositMoneyy(Bank* bank, int accountId, double amount){
    OperationCertificate* result;

    for(int i=0; sizeof(bank->bankAccounts); i++){
        if(bank->bankAccounts[i]->bankAccountID == accountId){
            result = depositMoney(bank->bankAccounts[i], amount);
            break;
        }
    }

    return result;
}


Transaction* transferMoney(Bank* bank, int senderAccountId, int receiverAccountId, double amount, int operationType){
    Transaction* result = createTransaction(senderAccountId, receiverAccountId, 0, amount, sizeof(bank->transactions));
    /*
    freeTransaction(withdrawMoneyy(bank, senderAccountId, amount));
    freeTransaction(depositMoneyy(bank, receiverAccountId, amount));
    */
    return result;
}


void freeBank(Bank* bank){
    /*
    free(bank->id);
    free(bank->name);
    free(bank->office);
    free(bank->transactions);
    free(bank->bankAccounts);
    free(bank);
     */
}