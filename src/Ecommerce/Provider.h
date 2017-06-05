#ifndef ECOMMERCEAUSTRAL_PROVIDER_H
#define ECOMMERCEAUSTRAL_PROVIDER_H

//#include "../structs/StaticList.h"
#include "ProductBook.h"

typedef struct Provider{
    int userID;
    char* name;
    int password;
    int phoneNumber;
    int RIF;
    ProductBook** books;

    int amountOfBooks;
    int maxCapacityOfBooks;

    //StaticList* books;

}Provider;

Provider* createProvider(char *name,
                         int password,
                         int phoneNumber,
                         int RIF, int initialCapacity);

void addBook(Provider* provider, BookInformation* bookInfo, int quantity, int price);
void removeBook(Provider* provider, int ISBN, int quantity);
void destroyProvider(Provider* provider);


#endif //ECOMMERCEAUSTRAL_PROVIDER_H
