#include "Provider.h"
#include <stdlib.h>
#include <string.h>
#include "ProductBook.h"
#include "../structs/StaticList.h"

Provider *createProvider(char *name,
                         int password,
                         int phoneNumber,
                         ProductBook *productBook,
                         int RIF) {

    Provider *newProvider = malloc(sizeof(Provider));

    newProvider->name = malloc( sizeof(char) * (strlen(name) + 1));
    strcpy(newProvider->name, name);

    newProvider->password = password;
    newProvider->phoneNumber = phoneNumber;
    newProvider->RIF = RIF;

    newProvider->books = createStaticList(5);
    addNext(newProvider->books, productBook);
    return newProvider;
}

void addBook(Provider *provider, ProductBook *productBook, int quantity) {

    // If book exists in provider add stocks
    for (int i = 0; i < provider->books->size-1; i++) {
        goTo(provider->books, i);

//        ((ProductBook)getActual(provider->books)).bookInfo->ISBN

        if (provider->books->array[i]->bookInfo->ISBN == productBook->bookInfo->ISBN) {
            provider->books->array[i]->stock += quantity;
            return;
        }
    }

    // If book does not exist in provider add new book
    addNext(provider->books, productBook);
}

void removeBook(Provider *provider, ProductBook *productBook, int quantity) {
    for (int i = 0; i < provider->books->size-1; i++) {
        goTo(provider->books, i);
        if (provider->books->array[i]->bookInfo->ISBN == productBook->bookInfo->ISBN) {
            provider->books->array[i]->stock -= quantity;
            return;
        }
    }
}

void destroyProvider(Provider *provider) {
    free(provider->RIF);
    free(provider->phoneNumber);
    free(provider->name);
    free(provider->userID);

    for (int i = 0; i < provider->books->size-1; i++) {
        goTo(provider->books, i);
        destroyProductBook(provider->books->array[i]);
    }

    freeStaticList(provider->books);
    free(provider);
}
