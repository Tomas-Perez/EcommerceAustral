#include <stdlib.h>
#include "Bank.h"

Bank* createBank(int id, char* name, char* office, int capacity){
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

/**
 * Augments bankTransations capacity
 * @param bank
 */
static void growTransactions(Bank* bank){
    int capacity= (bank->transactionCapacity)*2;
    bank->transactions=realloc(bank->transactions, sizeof(Transaction*)*capacity);
    bank->transactionCapacity=capacity;
}

/**
 * Augments bankAccounts capacity.
 * @param bank
 */
static void growAccounts(Bank* bank){
    int capacity= (bank->accountCapacity)*2;
    bank->bankAccounts=realloc(bank->bankAccounts, sizeof(BankAccount*)*capacity);
    bank->accountCapacity=capacity;
}

/**
 * Adds transactions to bankAccounts transactions
 * @param bank
 * @param transaction
 * @return 1 if transaction was added
 */
int addTransaction(Bank* bank, Transaction* transaction){
    if(bank->transactionAmount==bank->transactionCapacity){
        growTransactions(bank);
    }
    bank->transactions[bank->transactionAmount]=transaction;
    bank->transactionAmount++;
    return 1;
}

/**
 * add accounts to Bank
 * @param bank
 * @param account
 * @return 1 if account was added
 */
int addAccount(Bank* bank, BankAccount* account){
    if(bank->accountCapacity==bank->accountAmount){
        growAccounts(bank);
    }
    bank->bankAccounts[bank->accountAmount]=account;
    bank->accountAmount++;
    return 1;
}

/**
 * removes transaction from Bank
 * @param bank
 * @param transactionNumber
 */
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

/**
 * removes account from Bank
 * @param bank
 * @param id
 */
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

/**
 * Withdraws money from account, creates transaction as a result of the operation.
 * @param bank
 * @param accountId
 * @param amount
 * @return transaction with operation data.
 */
Transaction* withdraw_Money(Bank* bank, int accountId, double amount){
    Transaction* result= createTransaction(accountId, accountId, 2, amount, bank->transactionNumberGenerator);
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

/**
 * deposits money to account, creates a new Transaction containing all data of the operation.
 * @param bank
 * @param accountId
 * @param amount
 * @return transaction with operation data.
 */
Transaction* deposit_Money(Bank* bank, int accountId, double amount){
    Transaction* result= createTransaction(accountId, accountId, 1, amount, bank->transactionNumberGenerator);
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

/**
 * Makes withdraw of the sender account and deposit in the receiver account.
 * @param bank
 * @param senderAccountId
 * @param receiverAccountId
 * @param amount
 * @return transaction with operation data.
 */
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

/**
 * Frees up memory of Bank.
 * @param bank
 */
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