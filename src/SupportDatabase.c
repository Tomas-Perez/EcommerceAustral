#include <stdlib.h>
#include "SupportDatabase.h"

/*
 *  Function: newSupportDatabase
 *  Description: creates a new SupportDatabase with the specified size.
 *  Returns: SupportDatabase*
*/
SupportDatabase* newSupportDatabase(int initialCapacity){
    SupportDatabase* database = malloc(sizeof(SupportDatabase));
    database->messages = malloc(sizeof(SupportMessage)*initialCapacity);
    database->messageCapacity = initialCapacity;
    database->messageAmount = 0;
    return database;
}

/*
 *  Function: addMessage
 *  Description: adds a SupportMessage to the message array in the provided SupportDatabase.
 *  Returns: -
*/
void addMessage(SupportDatabase* database, SupportMessage* message){
    if (database->messageAmount == database->messageCapacity){
        growSupportDatabase(database);
    }
    database->messages[database->messageAmount] = message;
    database->messageAmount++;
}

/*
 *  Function: growSupportDatabase
 *  Description: doubles the size of the message array in the provided SupportDatabase.
 *  Returns: -
*/
void growSupportDatabase(SupportDatabase* database){
    int maxCapacity = database->messageCapacity;
    database->messages = realloc(database->messages, sizeof(SupportMessage)*maxCapacity*2);
    database->messageCapacity = maxCapacity*2;
}

/*
 *  Function: getMessages
 *  Description: returns all the messages sent to support by the student with the specified id.
 *  Returns: SupportMessage**
*/
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

/*
 *  Function: removeMessage
 *  Description: removes the message with the provided id from SupportDatabase.
 *  Returns: -
*/
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

/*
 *  Function: destroyMessages
 *  Description: frees the space in memory that was used by the provided method.
 *  Returns: -
*/
void destroyMessage(SupportMessage* message){
    free(message->date);
    free(message->question);
    free(message->answer);
    free(message);
}