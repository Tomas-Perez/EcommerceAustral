#include "Payment.h"

/*
    Description: C file that contains the functions related to the Payment structure.
*/

/*
    Function: createPayment
    Description: Creates a Payment with a PaymentMethod and an Invoice.
    Returns: the Payment pointer
*/
Payment* createPayment(PaymentMethod* paymentMethod, Invoice* invoice){
    Payment* result = malloc(sizeof(Payment));

    result->paymentMethod = paymentMethod;
    result->invoice = invoice;
    return result;
}

/*
    Function: destroyPayment
    Description: frees the memory allocated to the Payment
    Returns: void
*/
void destroyPayment(Payment* payment){
    destroyPaymentMethod(payment->paymentMethod);
    destroyInvoice(payment->invoice);
}