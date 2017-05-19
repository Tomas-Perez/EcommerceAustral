#ifndef ECOMMERCEAUSTRAL_ADMIN_H
#define ECOMMERCEAUSTRAL_ADMIN_H

typedef struct Admin{
    int userID;
    int password;
}Admin;

void destroyAdmin(Admin* admin);

#endif //ECOMMERCEAUSTRAL_ADMIN_H
