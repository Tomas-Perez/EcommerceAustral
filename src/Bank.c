
#include "Bank.h"

Bank* createBank(int id, char name[], char office[], Transaction* transactions[], BankAccount* bankAccounts[]){
    Bank* result= malloc(sizeof(Bank));
    result->id = malloc(sizeof(int));
    result->name = malloc(sizeof(char[]));
    result->transactions = malloc(sizeof(Transaction[]));
    result->bankAccounts = malloc(sizeof(BankAccount[]));

    result->id = id;
    result->name = name;
    result->transactions = transactions;
    result->bankAccounts = bankAccounts;

    return result;
}

Transaction* withdrawMoney(Bank* bank, int accountId, double amount){
    for(int i=0; (bank->bankAccounts).size; i++){
    }
}


Transaction* depositMoney(Bank* bank, int accountId, double amount);


Transaction* transferMoney(Bank* bank, int senderAccountId, int receiverAccountId, double amount);


void freeBank(Bank* bank);