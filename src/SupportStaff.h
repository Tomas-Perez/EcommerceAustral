#ifndef ECOMMERCEAUSTRAL_SUPPORTSTAFF_H
#define ECOMMERCEAUSTRAL_SUPPORTSTAFF_H
#include "SupportDatabase.h"
/*
 * Description: Header file for a SupportStaff
 */
typedef struct SupportStaff{
    int userID;
    int password;
    SupportDatabase* database;
}SupportStaff;

SupportStaff* newSupportStaff(SupportDatabase* database, int supportID, int password);

void answerQuestion(SupportStaff* staff, SupportMessage* message);

SupportStaff* changePerson(SupportStaff* staff, int supportID); //what is the purpose of this method

int searchQuestion(SupportStaff* staff, int studentId);

void destroySupportStaff(SupportStaff* supportStaff);

#endif //ECOMMERCEAUSTRAL_SUPPORTSTAFF_H
