

#ifndef SRC_BANK_H
#define SRC_BANK_H

#include "BankAccount.h"
#include "Transaction.h"

typedef struct bank Bank;

struct bank{
    int id;
    char name[];
    char office[];
    Transaction* transactions[];
    BankAccount* bankAccounts[];
};

Bank* createBank(int id, char name[], char office[], Transaction* transactions[], BankAccount* bankAccounts[]);
Transaction* withdrawMoney(Bank* bank, int accountId, double amount);
Transaction* depositMoney(Bank* bank, int accountId, double amount);
Transaction* transferMoney(Bank* bank, int senderAccountId, int receiverAccountId, double amount);
void freeBank(Bank* bank);

#endif //SRC_BANK_H
