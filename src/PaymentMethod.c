#include "PaymentMethod.h"
#include <stdlib.h>
/*
    Description: C file that contains the functions related to the PaymentMethod structure.
*/

/*
    Function: createPaymentMethod
    Description: Creates a PaymentMethod with a specific time, an ID of the purchase, a certain type of purchase represented by an Integer and the payment Data.
    Returns: the PaymentMethod pointer
*/
PaymentMethod* createPaymentMethod(long timestamp, int paymentID, paymentType type, int paymentData){
    PaymentMethod* result = malloc(sizeof(PaymentMethod));

    result->timestamp = timestamp;
    result->paymentID = paymentID;
    result->type = type;
    result->paymentData = paymentData;
}
