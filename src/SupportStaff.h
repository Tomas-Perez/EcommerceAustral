#ifndef ECOMMERCEAUSTRAL_SUPPORTSTAFF_H
#define ECOMMERCEAUSTRAL_SUPPORTSTAFF_H
#include "SupportDatabase.h"
/*
 * Description: Header file for a SupportStaff
 */
typedef struct SupportStaff{
    int userID;
    int password;
    int phoneNumber;
    char* name;
    SupportDatabase* database;
}SupportStaff;

SupportStaff* newSupportStaff(char* name, int supportID, int password, int phoneNumber);

void answerQuestion(int supportStaffId, SupportMessage* message, char* answer);

SupportStaff* changePerson(SupportStaff* staff, int supportID); //what is the purpose of this method

void destroySupportStaff(SupportStaff* supportStaff);


#endif //ECOMMERCEAUSTRAL_SUPPORTSTAFF_H
