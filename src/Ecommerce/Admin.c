#include "Admin.h"
#include <stdlib.h>
#include <string.h>
/*
 * Function: createAdmin
 * Description: allocates memory for an Admin and its components.
 * Returns: Admin pointer
 */
Admin* createAdmin(char* name, int password, int phoneNumber){
    Admin* result = malloc(sizeof(Admin));
    result->name = malloc(sizeof(char)*strlen(name)+1);
    strcpy(result->name, name);
    result->password = password;
    result->phoneNumber = phoneNumber;

    return result;
}

/*
 * Function: destroyAdmin
 * Description: frees all memory of the specified Admin.
 * Returns: -
 */
void destroyAdmin(Admin* admin){
    free(admin->name);
    free(admin);
}