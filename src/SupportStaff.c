#include "SupportStaff.h"
#include <stdlib.h>

SupportStaff* createSupportStaff(int password){
    SupportStaff* result = malloc(sizeof(SupportStaff));
    result->password = password;

    return result;
}

void destroySupportStaff(SupportStaff* supportStaff){
    free(supportStaff);
}