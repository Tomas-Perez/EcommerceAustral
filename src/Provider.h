#ifndef ECOMMERCEAUSTRAL_PROVIDER_H
#define ECOMMERCEAUSTRAL_PROVIDER_H

typedef struct Provider{
    int userID;
    int password;
}Provider;

Provider* createProvider(int password); //Testing database
void destroyProvider(Provider* provider);


#endif //ECOMMERCEAUSTRAL_PROVIDER_H
