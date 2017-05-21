#ifndef ECOMMERCEAUSTRAL_SUPPORTDATABASE_H
#define ECOMMERCEAUSTRAL_SUPPORTDATABASE_H
#include "SupportMessage.h"

/*
 * Description: Header file that describes a SupportDatabase that stores messages sent to SupportStaff.
 */
typedef struct SupportDatabase{
    SupportMessage** messages;
    int messageAmount;
    int messageCapacity;
}SupportDatabase;

SupportDatabase* newSupportDatabase(int initialCapacity); //is it necessary to have a SupportMessage array as an argument for the method?

void addMessage(SupportDatabase* database, SupportMessage* message);

void growSupportDatabase(SupportDatabase* database);

SupportMessage** getMessages(SupportDatabase* database, int id);

void removeMessage(SupportDatabase* database, int messageID);

void destroyMessage(SupportMessage* message);

#endif //ECOMMERCEAUSTRAL_SUPPORTDATABASE_H
