

#ifndef SRC_BANK_H
#define SRC_BANK_H

#include "BankAccount.h"
#include "Transaction.h"

typedef struct bank Bank;

struct bank{
    int id;
    char name[]; // Un pointer de funciona como un array en C, pueden ver el ejemplo del campus
    char office[];
    Transaction* transactions[];
    BankAccount* bankAccounts[];
};

Bank* newBank(int id, char name[], char office[], Transaction* transactions[], BankAccount* bankAccounts[]);
Transaction* withdrawMoneyy(Bank* bank, int accountId, double amount);
Transaction* depositMoneyy(Bank* bank, int accountId, double amount);
Transaction* transferMoney(Bank* bank, int senderAccountId, int receiverAccountId, double amount);
void freeBank(Bank* bank1);

#endif //SRC_BANK_H
