#ifndef ECOMMERCEAUSTRAL_SUPPORTMESSAGE_H
#define ECOMMERCEAUSTRAL_SUPPORTMESSAGE_H

/*
 * Description: Header file that represents a SupportMessage sent by a user to a SupportStaff.
 */
typedef struct SupportMessage{
    long timeStamp;
    char* date;
    char* question;
    char* answer;
    int supportStaffID;
    int studentID;
    int id; //set by SupportDatabase when it is added (used to remove a message from the database).
    int isAnswered;
}SupportMessage;

SupportMessage* newSupportMessage(char* question, int studentID);
void addAnswer(SupportMessage* message, char* answer, int supportID);
void destroySupportMessage(SupportMessage* message);

#endif //ECOMMERCEAUSTRAL_SUPPORTMESSAGE_H
