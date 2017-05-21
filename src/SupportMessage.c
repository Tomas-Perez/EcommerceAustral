#include "SupportMessage.h"
#include <stdlib.h>
#include <string.h>

SupportMessage* newSupportMessage(long timeStamp, char* date, char* question, char* answer, int supportStaffID, int studentID){
    SupportMessage* message = malloc(sizeof(SupportMessage));
    message->date = malloc(sizeof(char)*(strlen(date)+1));
    message->question = malloc(sizeof(char)*(strlen(question)+1));
    message->answer = malloc(sizeof(char)*(strlen(answer)+1));
    message->timeStamp = timeStamp;
    strcpy(message->date, date);
    strcpy(message->question, question);
    strcpy(message->answer, answer);
    message->supportStaffID = supportStaffID;
    message->studentID = studentID;
    return message;
}

void setID(SupportMessage* message, int id){ //why is this method necessary? ID could be set in constructor
    message->id = id;
}