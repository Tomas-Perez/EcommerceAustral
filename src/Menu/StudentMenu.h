//
// Created by micaeladominguez on 02/06/17.
//

#ifndef ECOMMERCEAUSTRAL_STUDENTMENU_H
#define ECOMMERCEAUSTRAL_STUDENTMENU_H

typedef struct stuentMenu StudentMenu;

struct stuentMenu {

};

void studentMenu(UserDatabase* database, Bank* bank, SupportDatabase* supportDatabase, College* college, int userID);
void campusOption(UserDatabase* database, College* college, int userID);
void eCommerceOption(UserDatabase* database, Bank* bank);
void bankOption(UserDatabase* database, Bank* bank, int userID);
void editInformationOption(UserDatabase* database, Student* student);

#endif //ECOMMERCEAUSTRAL_STUDENTMENU_H
