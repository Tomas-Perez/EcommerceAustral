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
    newProvider->amountOfBooks = 0;

    newProvider->maxCapacityOfBooks = initialCapacity;

    newProvider->books = malloc(sizeof(ProductBook*)*initialCapacity);
    return newProvider;
}

void addBook(Provider *provider, BookInformation *bookInfo, int quantity, int price) {
    // If ProductBook exists, add stock
    for (int i = 0; i < provider->amountOfBooks; i++) {
        if(provider->books[i]->bookInfo->ISBN == bookInfo->ISBN){
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
    provider->books[provider->amountOfBooks] = createProductBook(bookInfo, quantity, price);
    provider->amountOfBooks++;
}

void removeBook(Provider *provider, int ISBN, int quantity) {
    for (int i = 0; i < provider->amountOfBooks; i++) {
        if(provider->books[i]->bookInfo->ISBN == ISBN){
            provider->books[i]->stock -= quantity;
        }
    }
}

void destroyProvider(Provider *provider) {
    free(provider->name);

    for (int i = 0; i < provider->amountOfBooks; i++) {
        destroyProductBook(provider->books[i]);
    }

    free(provider->books);

    free(provider);
}