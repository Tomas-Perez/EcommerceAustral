#ifndef ECOMMERCEAUSTRAL_ADMIN_H
#define ECOMMERCEAUSTRAL_ADMIN_H

typedef struct Admin{
    char* name;
    int userID;
    int password;
    int phoneNumber;
}Admin;

Admin* createAdmin(char* name, int password, int phoneNumber);
void destroyAdmin(Admin* admin);

#endif //ECOMMERCEAUSTRAL_ADMIN_H
