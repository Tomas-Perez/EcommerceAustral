#ifndef ECOMMERCEAUSTRAL_PAYMENTMETHOD_H
#define ECOMMERCEAUSTRAL_PAYMENTMETHOD_H

/*
    Description: Header file that describes the PaymentMethod structure
*/
typedef enum {TRANSFER, CARD, DEPOSIT} paymentType;
typedef struct PaymentMethod{
    long timestamp;
    int paymentID;
    paymentType type;
    int paymentData; //data to be set to the paymentType when defined
}PaymentMethod;

PaymentMethod* createPaymentMethod(long timestamp, int paymentID, paymentType type, int paymentData);
void destroyPaymentMethod(PaymentMethod* paymentMethod);

#endif //ECOMMERCEAUSTRAL_PAYMENTMETHOD_H
