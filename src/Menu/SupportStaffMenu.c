#include "../Ecommerce/UserDatabase.h"
#include "../Ecommerce/SupportDatabase.h"
#include "InputTool.h"

void printMessages(SupportDatabase* supportDatabase){
	for(int i=0; i< supportDatabase->messageAmount; i++){
		if(supportDatabase->messages[i]->isAnswered==0) printf("%d. User with id %d asks: %s\n", i+1,supportDatabase->messages[i]->studentID  ,supportDatabase->messages[i]->question);
	}
}

void supportStaffMenu(UserDatabase* database, SupportDatabase* supportDatabase, int userID){
	printf("\nWelcome!\n");
	while(1){
        menu:
        printf("%s\n", "would you like to:");
        int rc=-1;
        printf("%s\n", "1. answer messages");
        printf("%s\n", "0. return to main menu\n");
        while (rc<0 || rc>1){
            rc = getOption ("enter option: ");
            if (rc<0 || rc>1)printf("invalid option.\n");
        }
        if(supportDatabase->messageAmount==0){
            printf("There are no messages, you can't do anything, logging out...");
            return;
        }
        if(rc==0) return;
        if (rc==1){
            printMessages(supportDatabase);
            int selectedMessage = 0;
            while (selectedMessage<1 || selectedMessage>supportDatabase->messageAmount) {
                selectedMessage = getOption("enter option, 0 to exit: ");
                if (selectedMessage < 0 || selectedMessage > supportDatabase->messageAmount)
                    printf("invalid option.\n");
                else if(selectedMessage == 0) goto menu;
            }
            char answer[140];
            int result = -1;
            while (result!=0){
                result = getLine ("Enter answer: ", answer, sizeof(answer));
                if(result==2) printf("140 characters is the maximum\n");
            }
            addAnswer(supportDatabase->messages[selectedMessage-1], answer, userID);
            pauseProgram("Answer submitted successfully, press enter key to continue.");
        }
	}
}

