#include "SupportMessage.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * Function: newSupportMessage
 * Description: creates a new SupportMessage with the provided information.
 * Returns: SupportMessage*
 */
SupportMessage* newSupportMessage(char* question, int studentID){
    SupportMessage* message = malloc(sizeof(SupportMessage));
    message->question = malloc(sizeof(char)*(strlen(question)+1));
    strcpy(message->question, question);
    message->studentID = studentID;
    message->isAnswered = 0;

    time_t t = time(NULL);
    message->timeStamp = t;
    struct tm* tm1 = localtime(&t);
    char* tempDate = asctime(tm1);
    message->date = malloc(sizeof(char)*(strlen(tempDate)+1));
    strcpy(message->date, tempDate);

    return message;
}

void addAnswer(SupportMessage* message, char* answer, int supportID){
    message->answer = malloc(sizeof(char)*(strlen(answer)+1));
    strcpy(message->answer, answer);
    message->isAnswered = 1;
    message->supportStaffID = supportID;
}

void destroySupportMessage(SupportMessage* message){
    free(message->answer);
    free(message->date);
    free(message->question);
    free(message);
}