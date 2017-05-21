#include "SupportStaff.h"
#include <stdlib.h>

SupportStaff* newSupportStaff(SupportDatabase* database, int supportID, int password){
    SupportStaff* staff = malloc(sizeof(SupportStaff));
    staff->database = malloc(sizeof(SupportDatabase));
    staff->database = newSupportDatabase(20); //initial capacity, what should be the default value?
    staff->userID = supportID;
    staff->password = password;
    return staff;
}

void answerQuestion(SupportStaff* staff, SupportMessage* message){
    removeMessage(staff->database, message->id);
}

SupportStaff* changePerson(SupportStaff* staff, int supportID){ //how will this method be used?
    staff->userID = supportID;
    return staff;
}

int searchQuestion(SupportStaff* staff, int studentId){
    for (int i=0; i<staff->database->messageAmount; i++){
        if (staff->database->messages[i]->studentID == studentId){
            return i;
        }
    }
    return -1;
}

void destroySupportStaff(SupportStaff* supportStaff){
    free(supportStaff->database->messages);
    free(supportStaff->database);
    free(supportStaff);
}