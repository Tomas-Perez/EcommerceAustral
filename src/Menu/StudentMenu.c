#include "../Ecommerce/UserDatabase.h"
#include "../Bank/Bank.h"
#include "../College/College.h"
#include "../Ecommerce/SupportDatabase.h"
#include "InputTool.h"

void studentMenu(UserDatabase* database, Bank* bank, SupportDatabase* supportDatabase, College* college, int userID){
char key[2];
Student* student = uDatabaseGetStudent(database, userID);
printf("Welcome %s, your user id is %d, and your carreer is %s\n", student->name, student->userID, student->career);
	getLine("this is just to see that until here the program behaves 'normally'.", key, sizeof(key));
}
