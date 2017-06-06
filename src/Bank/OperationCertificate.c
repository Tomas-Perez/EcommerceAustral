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

    time_t t = time(NULL);
    result->timeStamp = t;
    struct tm* tm1 = localtime(&t);
    char* tempDate = asctime(tm1);
    result->date = malloc(sizeof(char*)*strlen(tempDate)+1);
    strcpy(result->date, tempDate);

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