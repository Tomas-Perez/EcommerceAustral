

#include <stdlib.h>
#include <printf.h>
#include "Bank.h"

Bank* newBank(int id, char name[], char office[], Transaction* transactions[], BankAccount* bankAccounts[]){
    Bank* result= malloc(sizeof(Bank));
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

    return result;
}

Transaction* withdrawMoneyy(Bank* bank, int accountId, double amount){
    //Faltar crear transaction y terminar implementacion

    for(int i=0; sizeof(bank->bankAccounts); i++){
        if(bank->bankAccounts[i]->bankAccountID == accountId){
            printf("%i", accountId);
        }
    }
}


Transaction* depositMoneyy(Bank* bank, int accountId, double amount){
    //Faltar crear transaction y terminar implementacion

    for(int i=0; sizeof(bank->bankAccounts); i++){
        if(bank->bankAccounts[i]->bankAccountID == accountId){
            printf("%i", accountId);
        }
    }
}


Transaction* transferMoney(Bank* bank, int senderAccountId, int receiverAccountId, double amount){
    //Faltar crear transaction y terminar implementacion
    freeTransaction(withdrawMoneyy(bank, senderAccountId, amount));
    freeTransaction(depositMoneyy(bank, receiverAccountId, amount));
}


void freeBank(Bank* bank){
    free(bank->id);
    free(bank->name);
    free(bank->office);
    free(bank->transactions);
    free(bank->bankAccounts);
    free(bank);
}