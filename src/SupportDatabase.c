#include <stdlib.h>
#include "SupportDatabase.h"

SupportDatabase* newSupportDatabase(int initialCapacity){
    SupportDatabase* database = malloc(sizeof(SupportDatabase));
    database->messages = malloc(sizeof(SupportMessage)*initialCapacity);
    database->messageCapacity = initialCapacity;
    database->messageAmount = 0;
    return database;
}

void addMessage(SupportDatabase* database, SupportMessage* message){
    if (database->messageAmount == database->messageCapacity){
        growSupportDatabase(database);
    }
    database->messages[database->messageAmount] = message;
    database->messageAmount++;
}

void growSupportDatabase(SupportDatabase* database){
    int maxCapacity = database->messageCapacity;
    database->messages = realloc(database->messages, sizeof(SupportMessage*)*maxCapacity*2);
    database->messageCapacity = maxCapacity*2;
}

SupportMessage** getMessages(SupportDatabase* database, int id){
    SupportMessage** messages = malloc(sizeof(SupportMessage)*database->messageAmount); //how do I know the size?
    int count = 0;
    for (int i=0; i<database->messageAmount; i++){
        if (database->messages[i]->studentID == id){
            messages[count] = database->messages[i];
            count++;
        }
    }
    return messages;
}

void removeMessage(SupportDatabase* database, int messageID){
    for(int i = 0; i < database->messageAmount; i++){
        if(database->messages[i]->id== messageID){
            destroyMessage(database->messages[i]);
            for(; i < database->messageAmount-1; i++){
                database->messages[i] = database->messages[i+1];
            }
            database->messageAmount--;
            break;
        }
    }
}

void destroyMessage(SupportMessage* message){
    free(message->date);
    free(message->question);
    free(message->answer);
    free(message);
}