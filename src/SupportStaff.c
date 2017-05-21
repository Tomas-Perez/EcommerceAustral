#include "SupportStaff.h"
#include <stdlib.h>

/*
 *  Function: newSupportStaff
 *  Description: creates a new SupportStaff with the provided data.
 *  Returns: SupportStaff*
*/
SupportStaff* newSupportStaff(SupportDatabase* database, int supportID, int password){
    SupportStaff* staff = malloc(sizeof(SupportStaff));
    staff->database = malloc(sizeof(SupportDatabase));
    staff->database = newSupportDatabase(20); //initial capacity, what should be the default value?
    staff->userID = supportID;
    staff->password = password;
    return staff;
}

/*
 *  Function: answerQuestion
 *  Description: removes a question from SupportDatabase, as the question has already been answered.
 *  Returns: -
*/
void answerQuestion(SupportStaff* staff, SupportMessage* message){
    removeMessage(staff->database, message->id);
}

/*
 *  Function: changePerson
 *  Description: changes the id of the SupportStaff.
 *  Returns: SupportStaff*
*/
SupportStaff* changePerson(SupportStaff* staff, int supportID){ //how will this method be used?
    staff->userID = supportID;
    return staff;
}

/*
 *  Function: searchQuestion
 *  Description: searches for a question in the staff's SupportDatabase, if found it returns its position, it
 *  returns -1 otherwise.
 *  Returns: SupportStaff*
*/
int searchQuestion(SupportStaff* staff, int studentId){
    for (int i=0; i<staff->database->messageAmount; i++){
        if (staff->database->messages[i]->studentID == studentId){
            return i;
        }
    }
    return -1;
}

/*
 *  Function: destroySupportStaff
 *  Description: frees memory space that was used by the SupportStaff.
 *  Returns: -
*/
void destroySupportStaff(SupportStaff* supportStaff){
    free(supportStaff->database->messages);
    free(supportStaff->database);
    free(supportStaff);
}