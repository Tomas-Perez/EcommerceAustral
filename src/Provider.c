#include "Provider.h"
#include <stdlib.h>

Provider* createProvider(int password){
    Provider* result = malloc(sizeof(Provider));
    result->password = password;
}

void destroyProvider(Provider* provider){
    free(provider);
}