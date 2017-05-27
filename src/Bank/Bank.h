#ifndef SRC_BANK_H
#define SRC_BANK_H

#include "BankAccount.h"
#include "Transaction.h"

typedef struct bank Bank;

struct bank{
    int id;
    int idGenerator;
    int transactionNumberGenerator;

    char* name;
    char* office;

    Transaction** transactions;
    int transactionCapacity;
    int transactionAmount;

    BankAccount** bankAccounts;
    int accountCapacity;
    int accountAmount;
};

Bank* newBank(int id, char* name, char* office, int capacity);

Transaction* withdraw_Money(Bank* bank, int accountId, double amount);
Transaction* deposit_Money(Bank* bank, int accountId, double amount);
Transaction* transfer_Money(Bank* bank, int senderAccountId, int receiverAccountId, double amount);

int addTransaction(Bank* bank, Transaction* transaction);
int addAccount(Bank* bank, BankAccount* account);

void removeTransaction(Bank* bank, int transactionNumber);
void removeAccount(Bank* bank, int id);

void freeBank(Bank* bank1);

#endif //SRC_BANK_H
