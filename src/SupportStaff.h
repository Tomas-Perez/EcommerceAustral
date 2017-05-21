#ifndef ECOMMERCEAUSTRAL_SUPPORTSTAFF_H
#define ECOMMERCEAUSTRAL_SUPPORTSTAFF_H

typedef struct SupportStaff{
    int userID;
    int password;
}SupportStaff;

SupportStaff* createSupportStaff(int password); //Testing database
void destroySupportStaff(SupportStaff* supportStaff);


#endif //ECOMMERCEAUSTRAL_SUPPORTSTAFF_H
