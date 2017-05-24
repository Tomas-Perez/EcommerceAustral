#ifndef ECOMMERCEAUSTRAL_PROVIDER_H
#define ECOMMERCEAUSTRAL_PROVIDER_H

#include "structs/StaticList.h
#include "ProductBook.h""

typedef struct Provider{
    int userID;
    char* name;
    int password;
    int phoneNumber;
    int RIF;

    StaticList* books;
}Provider;

Provider* createProvider(char *name,
                         int password,
                         int phoneNumber,
                         ProductBook *productBook,
                         int RIF);
void addBook(Provider* provider, ProductBook* productBook, int quantity);
void removeBook(Provider* provider, ProductBook* productBook, int quantity);
void destroyProvider(Provider* provider);


#endif //ECOMMERCEAUSTRAL_PROVIDER_H
