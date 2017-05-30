#include "Provider.h"
#include <stdlib.h>
#include <string.h>
#include "ProductBook.h"
//#include "../structs/StaticList.h"

Provider *createProvider(char *name,
                         int password,
                         int phoneNumber,
                         int RIF, int initialCapacity) {

    Provider *newProvider = malloc(sizeof(Provider));
    newProvider->name = malloc( sizeof(char) * (strlen(name) + 1));
    strcpy(newProvider->name, name);

    newProvider->password = password;
    newProvider->phoneNumber = phoneNumber;
    newProvider->RIF = RIF;

    newProvider->maxCapacityOfBooks=5;

    newProvider->books = malloc(sizeof(ProductBook*)*initialCapacity);
    return newProvider;
}

void addBook(Provider *provider, ProductBook *productBook, int quantity) {
    // If ProductBook exists, add stock
    for (int i = 0; i < provider->amountOfBooks; i++) {
        if(provider->books[i]->bookInfo->ISBN == productBook->bookInfo->ISBN){
            provider->books[i]->stock += quantity;
            return;
        }
    }

    // Grow books array if needed
    if(provider->amountOfBooks == provider->maxCapacityOfBooks){
        provider->books = realloc(provider->books, sizeof(ProductBook*)*provider->maxCapacityOfBooks*2);
        provider->maxCapacityOfBooks = provider->maxCapacityOfBooks*2;
    }

    // Add new ProductBook
    provider->books[provider->amountOfBooks] = productBook;
    provider->amountOfBooks++;
}

void removeBook(Provider *provider, ProductBook *productBook, int quantity) {
    for (int i = 0; i < provider->amountOfBooks; i++) {
        if(provider->books[i]->bookInfo->ISBN == productBook->bookInfo->ISBN){
            provider->books[i]->stock -= quantity;
        }
    }
}

void destroyProvider(Provider *provider) {
    free(provider->RIF);
    free(provider->phoneNumber);
    free(provider->name);
    free(provider->userID);

    for (int i = 0; i < provider->amountOfBooks; i++) {
        destroyProductBook(provider->books[i]);
    }

    free(provider->books);
    free(provider->amountOfBooks);
    free(provider->maxCapacityOfBooks);

    free(provider);
}