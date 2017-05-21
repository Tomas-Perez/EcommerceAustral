#ifndef ECOMMERCEAUSTRAL_SUPPORTMESSAGE_H
#define ECOMMERCEAUSTRAL_SUPPORTMESSAGE_H

typedef struct SupportMessage{
    long timeStamp;
    char* date;
    char* question;
    char* answer;
    int supportStaffID;
    int studentID;
    int id;
}SupportMessage;

SupportMessage* newSupportMessage(long timeStamp, char* date, char* question, char* answer, int supportStaffID, int studentID);

void setID(SupportMessage* message, int id);

#endif //ECOMMERCEAUSTRAL_SUPPORTMESSAGE_H
