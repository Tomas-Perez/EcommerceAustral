#ifndef SRC_BOOKINFORMATION_H_
#define SRC_BOOKINFORMATION_H_

typedef struct bookInformation BookInformation;

struct bookInformation{

    char* title;
    int ISBN;
    char* author;
};

typedef struct arrayOfBooks{
    BookInformation** books;
    int amountOfBooks;
}ArrayOfBooks;

BookInformation* createBookInformation(char* title, int ISBN, char* author);
void destroyBookInformation(BookInformation* bookInformation);
int bookInformationIsEqual(BookInformation* bookInformation1, BookInformation* bookInformation2);

#endif /* SRC_BOOKINFORMATION_H_ */
