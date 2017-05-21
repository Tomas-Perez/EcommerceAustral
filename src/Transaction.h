
#ifndef SRC_TRANSACTION_H
#define SRC_TRANSACTION_H

typedef struct transaction Transaction;

struct transaction{
    long timeStamp;
    int transactionNumber;
    int toAccountID;
    int fromAccountID;
    int operationType;
    double amount;
    char* date;
};

Transaction* createTransaction(int toAccountID, int fromAccountID, int operationType, double amount, int transactionNumber);
void freeTransaction(Transaction* transaction);

#endif //SRC_TRANSACTION_H
