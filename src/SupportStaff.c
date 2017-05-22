#include "SupportStaff.h"
#include <stdlib.h>
#include <string.h>

/*
 *  Function: newSupportStaff
 *  Description: creates a new SupportStaff with the provided data.
 *  Returns: SupportStaff*
*/
SupportStaff* newSupportStaff(char* name, int supportID, int password, int phoneNumber){
    SupportStaff* staff = malloc(sizeof(SupportStaff));
    staff->userID = supportID;
    staff->password = password;
    staff->phoneNumber = phoneNumber;
    staff->name = malloc(sizeof(char)*(strlen(name)+1));
    strcpy(staff->name, name);
    return staff;
}

/*
 *  Function: answerQuestion
 *  Description: answers the provided message. The question is answered by the support staff with the specified
 *  id.
 *  Returns: -
*/
void answerQuestion(int supportStaffId, SupportMessage* message, char* answer){
    if (message->isAnswered) return; //the question is already answered.
    message->supportStaffID = supportStaffId;
    message->answer = malloc(sizeof(char)*(strlen(answer)+1));
    strcpy(message->answer, answer);
    message->isAnswered = 1;
}

/*
 *  Function: changePerson
 *  Description: changes the id of the SupportStaff.
 *  Returns: SupportStaff*
*/
SupportStaff* changePerson(SupportStaff* staff, int supportID){ //still don't understand the purpose of this function
    staff->userID = supportID;
    return staff;
}

/*
 *  Function: destroySupportStaff
 *  Description: frees memory space that was used by the SupportStaff.
 *  Returns: -
*/
void destroySupportStaff(SupportStaff* supportStaff){
    free(supportStaff->database->messages);
    free(supportStaff->database);
    free(supportStaff);
}