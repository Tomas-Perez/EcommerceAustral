#include <stdlib.h>
#include "Bank.h"

Bank* newBank(int id, char* name, char* office, int capacity){
    Bank* result= malloc(sizeof(Bank));

    result->id=id;
    result->name=name;
    result->office=office;

    result->transactionCapacity=capacity*10;
    result->accountCapacity=capacity;

    result->transactionAmount=0;
    result->accountAmount=0;
    result->idGenerator=1;
    result->transactionNumberGenerator=1;

    result->transactions=malloc(sizeof(Transaction*)*result->transactionCapacity);
    result->bankAccounts=malloc(sizeof(BankAccount*)*result->accountCapacity);

    return result;
}

static void growTransactions(Bank* bank){
    int capacity= (bank->transactionCapacity)*2;
    bank->transactions=realloc(bank->transactions, sizeof(Transaction*)*capacity);
    bank->transactionCapacity=capacity;
}
static void growAccounts(Bank* bank){
    int capacity= (bank->accountCapacity)*2;
    bank->bankAccounts=realloc(bank->bankAccounts, sizeof(BankAccount*)*capacity);
    bank->accountCapacity=capacity;
}

static int containsTransaction(Bank* bank, int transactionNumber){
    for(int i=0; i<bank->transactionAmount; i++){
        if(bank->transactions[i]->transactionNumber == transactionNumber){
            return 1;
        }
        else{
            return 0;
        }
    }
}
static int containsAccount(Bank* bank, int id){
    for(int i=0; i < bank->accountAmount; i++){
        if(bank->bankAccounts[i]->bankAccountID == id){
            return 1;
        }
        else{
            return 0;
        }
    }
}

int addTransaction(Bank* bank, Transaction* transaction){
    if(bank->transactionAmount==bank->transactionCapacity){
        growTransactions(bank);
    }
    if(containsTransaction(bank, transaction->transactionNumber)==1){
        return 0;
    }
    bank->transactions[bank->transactionAmount]=transaction;
    bank->transactionAmount++;
    return 1;
}
int addAccount(Bank* bank, BankAccount* account){
    if(bank->accountCapacity==bank->accountAmount){
        growAccounts(bank);
    }
    if(containsAccount(bank, account->bankAccountID)){
        return 0;
    }
    bank->bankAccounts[bank->accountAmount]=account;
    bank->accountAmount++;
    return 1;
}

void removeTransaction(Bank* bank, int transactionNumber){
    for(int i = 0; i < bank->transactionAmount; i++){
        if(bank->transactions[i]->transactionNumber==transactionNumber){
            freeTransaction(bank->transactions[i]);
            for(; i < bank->transactionAmount-1; i++){
                bank->transactions[i] = bank->transactions[i+1];
            }
            bank->transactionAmount--;
            break;
        }
        else if(bank->transactions[i]->transactionNumber > transactionNumber){
            break;
        }
    }
}
void removeAccount(Bank* bank, int id){
    for(int i = 0; i < bank->accountAmount; i++){
        if(bank->bankAccounts[i]->bankAccountID==id){
            freeBankAccount(bank->bankAccounts[i]);
            for(; i < bank->accountAmount-1; i++){
                bank->bankAccounts[i] = bank->bankAccounts[i+1];
            }
            bank->accountAmount--;
            break;
        }
        else if(bank->bankAccounts[i]->bankAccountID > id){
            break;
        }
    }
}

Transaction* withdraw_Money(Bank* bank, int accountId, double amount){
    Transaction* result= createTransaction(accountId, NULL, 2, amount, bank->transactionNumberGenerator);
    bank->transactionNumberGenerator++;

    for(int i=0; i<bank->accountAmount;i++){
        if(bank->bankAccounts[i]->bankAccountID==accountId){
            withdrawMoney(bank->bankAccounts[i], amount);
            bank->transactions[bank->transactionAmount]=result;
            bank->transactionAmount++;
            break;
        }
    }
    return result;
}


Transaction* deposit_Money(Bank* bank, int accountId, double amount){
    Transaction* result= createTransaction(accountId, NULL, 1, amount, bank->transactionNumberGenerator);
    bank->transactionNumberGenerator++;

    for(int i=0; i<bank->accountAmount;i++){
        if(bank->bankAccounts[i]->bankAccountID==accountId){
            depositMoney(bank->bankAccounts[i], amount);
            bank->transactions[bank->transactionAmount]=result;
            bank->transactionAmount++;
            break;
        }
    }
    return result;
}


Transaction* transfer_Money(Bank* bank, int senderAccountId, int receiverAccountId, double amount){
    Transaction* result= createTransaction(receiverAccountId, senderAccountId, 3, amount, bank->transactionNumberGenerator);
    bank->transactionNumberGenerator++;

    for(int i=0; i<bank->accountAmount;i++){
        if(bank->bankAccounts[i]->bankAccountID==senderAccountId){
            for(int j=0; j<bank->transactionAmount;j++){
                if(bank->bankAccounts[j]->bankAccountID==receiverAccountId){
                    withdrawMoney(bank->bankAccounts[i], amount);
                    depositMoney(bank->bankAccounts[j], amount);
                    bank->transactions[bank->transactionAmount]=result;
                    bank->transactionAmount++;
                    break;
                }
            }
        }
    }
    return result;
}


void freeBank(Bank* bank){
    for(int i=0; i<bank->transactionAmount; i++){
        freeTransaction(bank->transactions[i]);
    }
    for(int i=0; i<bank->accountAmount; i++){
        freeBankAccount(bank->bankAccounts[i]);
    }

    free(bank->name);
    free(bank->office);
    free(bank->transactions);
    free(bank->bankAccounts);
    free(bank);
}