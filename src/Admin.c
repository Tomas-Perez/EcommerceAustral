#include "Admin.h"
#include <stdlib.h>
#include <string.h>

Admin* createAdmin(char* name, int password, int phoneNumber){
    Admin* result = malloc(sizeof(Admin));
    result->name = malloc(sizeof(char)*strlen(name)+1);
    strcpy(result->name, name);
    result->password = password;
    result->phoneNumber = phoneNumber;

    return result;
}

void destroyAdmin(Admin* admin){
    free(admin->name);
    free(admin->userID);
    free(admin->password);
    free(admin->phoneNumber);
    free(admin);
}