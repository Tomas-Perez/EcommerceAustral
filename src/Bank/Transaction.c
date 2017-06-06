
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Transaction.h"

//OperationType: 1 deposito, 2 retiro, 3 transferencia.

Transaction* createTransaction(int toAccountID, int fromAccountID, int operationType, double amount, int transactionNumber){
    Transaction* result = malloc(sizeof(Transaction));

    result->amount=amount;
    result->fromAccountID=fromAccountID;
    result->toAccountID=toAccountID;
    result->operationType=operationType;
    result->transactionNumber=transactionNumber;

    time_t t = time(NULL);
    result->timeStamp = t;
    struct tm* tm1 = localtime(&t);
    char* tempDate = asctime(tm1);
    result->date = malloc(sizeof(char*)*strlen(tempDate)+1);
    strcpy(result->date, tempDate);
    return result;
}

/**
 * frees up space memory.
 * @param transaction
 */
void freeTransaction(Transaction* transaction){
    free(transaction->date);
    free(transaction);
}
