
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

    time_t currentTime=time(NULL);
    result->timeStamp=currentTime;

    time_t calendarTime;
    time(&calendarTime);

    result->date=malloc(sizeof(char*));
    strcpy(result->date, ctime(&calendarTime));

}
void freeTransaction(Transaction* transaction){
    free(transaction->date);
    free(transaction);
}