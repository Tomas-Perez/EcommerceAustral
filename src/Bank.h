

#ifndef SRC_BANK_H
#define SRC_BANK_H

#include "BankAccount.h"
#include "Transaction.h"

typedef struct bank Bank;

struct bank{
    int id;
    char* name; // Un pointer de funciona como un array en C, pueden ver el ejemplo del campus
    char* office;
    Transaction** transactions; //Doble pointer significa un array de pointers
    BankAccount** bankAccounts;

};

Bank* newBank(int id, char* name, char* office, Transaction** transactions, BankAccount** bankAccounts);
Transaction* withdrawMoney(int accountId, double amount);
Transaction* depositMoney(int accountId, double amount);
Transaction* transferMoney(int senderAccountId, int receiverAccountId, double amount);
BankAccount* getAccounts();
Transaction* getTransactions();
char getOffice();
char getName();
int getId();
void freeBank(Bank* bank1);

#endif //SRC_BANK_H
