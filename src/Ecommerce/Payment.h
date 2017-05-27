#ifndef ECOMMERCEAUSTRAL_PAYMENT_H
#define ECOMMERCEAUSTRAL_PAYMENT_H

#include "PaymentMethod.h"
#include "Invoice.h"

typedef struct Payment{
    PaymentMethod* paymentMethod;
    Invoice* invoice;
}Payment;


Payment* createPayment(PaymentMethod* paymentMethod, Invoice* invoice);
void destroyPayment(Payment* payment);

#endif //ECOMMERCEAUSTRAL_PAYMENT_H
