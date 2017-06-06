

#include "OperationCertificate.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include <mem.h>

OperationCertificate* createOperationCertificate(int accountID, int operationType, double amount){
    OperationCertificate* result = malloc(sizeof(OperationCertificate));

    result->accountID=accountID;
    result->operationType=operationType;
    result->amount=amount;

    time_t currentTime = time(NULL);
    result->timeStamp=currentTime;


    time_t calendarTime;
    time(&calendarTime);

    result->date= malloc(sizeof(char*));
    strcpy(result->date,ctime(&calendarTime));

    return result;
}

/**
 * frees up operation certficate memory space.
 * @param operationCertificate
 */
void freeOperationCertificate(OperationCertificate* operationCertificate){
    free(operationCertificate->date);
    free(operationCertificate);
}