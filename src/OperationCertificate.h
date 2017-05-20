//
// Created by Lucas on 19/5/2017.
//

#ifndef ECOMMERCEAUSTRAL_OPERATIONCERTIFICATE_H
#define ECOMMERCEAUSTRAL_OPERATIONCERTIFICATE_H




typedef struct OperationCertificate{
    long timeStamp;
    int accountID;
    int operationType;
    double amount;
    char* date;
} OperationCertificate;

OperationCertificate* createOperationCertificate(int accountID, int operationType, double amount);
void freeOperationCertificate(OperationCertificate*  operationCertificate);

#endif //ECOMMERCEAUSTRAL_OPERATIONCERTIFICATE_H
