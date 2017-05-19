#include <afxres.h>
#include "UserDatabase.h"

/*
 * Description: Contains functions related to the UserDatabase ADT
 */

static void growUserLog(UserDatabase* database){
    int maxCapacity = database->userLogCapacity;
    database->userLogs = realloc(database->userLogs, sizeof(UserLog*)*maxCapacity*2);
    database->userLogCapacity = maxCapacity*2;
}

static void addUserLog(UserDatabase* database, UserLog* userLog){
    if(database->userLogAmount == database->userLogCapacity){
        growUserLog(database);
    }
    database->userLogs[database->userLogAmount] = userLog;
    database->userLogAmount++;
}

static void removeUserLog(UserDatabase* database, int userID){
    for(int i = 0; i < database->userLogAmount; i++){
        if(database->userLogs[i]->userID == userID){
            destroyUserLog(database->userLogs[i]);
            for(; i < database->userLogAmount-1; i++){
                database->userLogs[i] = database->userLogs[i+1];
            }
            database->userLogAmount--;
            break;
        }
        else if(database->userLogs[i]->userID < userID) break;
    }
}

/*
 * Function: createUserDatabase
 * Description: allocates all memory necessary for the userDatabase, initializes all arrays with the given
 * initial capacity.
 * Returns: UserDatabase pointer.
 */

UserDatabase* createUserDatabase(int initialCapacity, Admin *admin){
    UserDatabase* result = malloc(sizeof(UserDatabase));

    result->idGenerator = 1;

    result->providerCapacity = initialCapacity;
    result->studentCapacity = initialCapacity;
    result->supportStaffCapacity = initialCapacity;
    result->userLogCapacity = initialCapacity*3 + 1;

    result->providerAmount = 0;
    result->studentAmount = 0;
    result->supportStaffAmount = 0;
    result->userLogAmount = 0;

    result->students = malloc(sizeof(Student*)*result->studentCapacity);
    result->supportStaff = malloc(sizeof(SupportStaff*)*result->supportStaffCapacity);
    result->providers = malloc(sizeof(Provider*)*result->providerCapacity);
    result->userLogs = malloc(sizeof(UserLog*)*result->userLogCapacity);

    admin->userID = 0;
    result->admin = admin;
    UserLog* adminLog = createUserLog(ADMIN, admin->userID,"admin");
    addUserLog(result, adminLog);

    return result;
}

static void growStudent(UserDatabase *database){
    int maxCapacity = database->studentCapacity;
    database->students = realloc(database->students, sizeof(Student*)*maxCapacity*2);
    database->studentCapacity = maxCapacity*2;
}

static void growProvider(UserDatabase *database){
    int maxCapacity = database->providerCapacity;
    database->providers = realloc(database->providers, sizeof(Provider*)*maxCapacity*2);
    database->providerCapacity = maxCapacity*2;
}
static void growSupportStaff(UserDatabase *database){
    int maxCapacity = database->supportStaffCapacity;
    database->supportStaff = realloc(database->supportStaff, sizeof(SupportStaff*)*maxCapacity*2);
    database->supportStaffCapacity = maxCapacity*2;
}

/*
 * Function: uDatabaseAddStudent
 * Description: adds a student to the database, also generates a userLog with the given username for future log ins.
 * Returns: -
 */

void uDatabaseAddStudent(UserDatabase* userDatabase, Student* student, char* username){
    student->userID = userDatabase->idGenerator++;
    if(userDatabase->studentAmount == userDatabase->studentCapacity){
        growStudent(userDatabase);
    }
    userDatabase->students[userDatabase->studentAmount] = student;
    userDatabase->studentAmount++;
    UserLog* userLog = createUserLog(STUDENT, student->userID, username);
    addUserLog(userDatabase, userLog);
}

/*
 * Function: uDatabaseAddProvider
 * Description: adds a provider to the database, also generates a userLog with the given username for future log ins.
 * Returns: -
 */

void uDatabaseAddProvider(UserDatabase* userDatabase, Provider* provider, char* username){
    provider->userID = userDatabase->idGenerator++;
    if(userDatabase->providerAmount == userDatabase->providerCapacity){
        growProvider(userDatabase);
    }
    userDatabase->providers[userDatabase->providerAmount] = provider;
    userDatabase->providerAmount++;
    UserLog* userLog = createUserLog(PROVIDER, provider->userID, username);
    addUserLog(userDatabase, userLog);
}

/*
 * Function: uDatabaseAddSupportStaff
 * Description: adds a supportStaff to the database, also generates a userLog with the given username for future log ins.
 * Returns: -
 */

void uDatabaseAddSupportStaff(UserDatabase* userDatabase, SupportStaff* supportStaff, char* username){
    supportStaff->userID = userDatabase->idGenerator++;
    if(userDatabase->supportStaffAmount == userDatabase->supportStaffCapacity){
        growSupportStaff(userDatabase);
    }
    userDatabase->supportStaff[userDatabase->supportStaffAmount] = supportStaff;
    userDatabase->supportStaffAmount++;
    UserLog* userLog = createUserLog(SUPPORT_STAFF, supportStaff->userID, username);
    addUserLog(userDatabase, userLog);
}

/*
 * Function: uDatabaseGetStudent
 * Description: retrieves a student from the database that has a matching userID.
 * Returns: Student pointer, NULL if the student is not found.
 */

Student* uDatabaseGetStudent(UserDatabase* userDatabase, int userID){
    for(int i = 0; i < userDatabase->studentAmount; i++){
        if(userDatabase->students[i]->userID == userID) return userDatabase->students[i];
        else if(userDatabase->students[i]->userID < userID) break;
    }
    return NULL;
}

/*
 * Function: uDatabaseGetProvider
 * Description: retrieves a provider from the database that has a matching userID.
 * Returns: Provider pointer, NULL if the provider is not found.
 */

Provider* uDatabaseGetProvider(UserDatabase* userDatabase, int userID){
    for(int i = 0; i < userDatabase->providerAmount; i++){
        if(userDatabase->providers[i]->userID == userID) return userDatabase->providers[i];
        else if(userDatabase->providers[i]->userID < userID) break;
    }
    return NULL;
}

/*
 * Function: uDatabaseGetSupportStaff
 * Description: retrieves a supportStaff from the database that has a matching userID.
 * Returns: SupportStaff pointer, NULL if the supportStaff is not found.
 */

SupportStaff* uDatabaseGetSupportStaff(UserDatabase* userDatabase, int userID){
    for(int i = 0; i < userDatabase->supportStaffAmount; i++){
        if(userDatabase->supportStaff[i]->userID == userID) return userDatabase->supportStaff[i];
        else if(userDatabase->supportStaff[i]->userID < userID) break;
    }
    return NULL;
}

/*
 * Function: uDatabaseRemoveStudent
 * Description: removes a student from the database that has a matching userID.
 * Returns: -
 */

void uDatabaseRemoveStudent(UserDatabase* userDatabase, int userID){
    for(int i = 0; i < userDatabase->studentAmount; i++){
        if(userDatabase->students[i]->userID == userID){
            destroyStudent(userDatabase->students[i]);
            for(; i < userDatabase->studentAmount-1; i++){
                userDatabase->students[i] = userDatabase->students[i+1];
            }
            userDatabase->studentAmount--;
            removeUserLog(userDatabase, userID);
            break;
        }
        else if(userDatabase->students[i]->userID < userID) break;
    }
}

/*
 * Function: uDatabaseRemoveProvider
 * Description: removes a provider from the database that has a matching userID.
 * Returns: -
 */

void uDatabaseRemoveProvider(UserDatabase* userDatabase, int userID){
    for(int i = 0; i < userDatabase->providerAmount; i++){
        if(userDatabase->providers[i]->userID == userID){
            destroyProvider(userDatabase->providers[i]);
            for(; i < userDatabase->providerAmount-1; i++){
                userDatabase->providers[i] = userDatabase->providers[i+1];
            }
            userDatabase->providerAmount--;
            removeUserLog(userDatabase, userID);
            break;
        }
        else if(userDatabase->providers[i]->userID < userID) break;
    }
}

/*
 * Function: uDatabaseRemoveSupportStaff
 * Description: removes a supportStaff from the database that has a matching userID.
 * Returns: -
 */

void uDatabaseRemoveSupportStaff(UserDatabase* userDatabase, int userID){
    for(int i = 0; i < userDatabase->supportStaffAmount; i++){
        if(userDatabase->supportStaff[i]->userID == userID){
            destroySupportStaff(userDatabase->supportStaff[i]);
            for(; i < userDatabase->supportStaffAmount-1; i++){
                userDatabase->supportStaff[i] = userDatabase->supportStaff[i+1];
            }
            userDatabase->supportStaffAmount--;
            removeUserLog(userDatabase, userID);
            break;
        }
        else if(userDatabase->supportStaff[i]->userID < userID) break;
    }
}

static UserLog* getUserLog(UserDatabase* database, char* username){
    for(int i = 0; i < database->providerAmount; i++){
        int compare = strcmp(database->userLogs[i]->username, username);
        if(compare == 0) return database->userLogs[i];
        else if(compare < 0) break;
    }
    return createUserLog(UNKNOWN, -1, "unknown");
}

/*
 * Function: login
 * Description: takes a username and password, finds a user with matching parameters and returns a userLog with its type
 * and userID.
 * Returns: UserLog pointer. If there is a problem authenticating the user it will return a UserLog with UNKNOWN type.
 *          ID = -1 means there is no user matching the username.
 *          ID = -2 means the password is wrong.
 */

UserLog* login(UserDatabase* database, char* username, int password){
    UserLog* userLog = getUserLog(database, username);
    switch (userLog->userType){
        case STUDENT:
        {
            Student* result = uDatabaseGetStudent(database, userLog->userID);
            if(result->password == password) return userLog;
            else return createUserLog(UNKNOWN, -2, "unknown");
        }
        case PROVIDER:
        {
            Provider* result = uDatabaseGetProvider(database, userLog->userID);
            if(result->password == password) return userLog;
            else return createUserLog(UNKNOWN, -2, "unknown");
        }
        case SUPPORT_STAFF:
        {
            SupportStaff* result = uDatabaseGetSupportStaff(database, userLog->userID);
            if(result->password == password) return userLog;
            else return createUserLog(UNKNOWN, -2, "unknown");
        }
        case ADMIN:
        {
            Admin* result = database->admin;
            if(result->password == password) return userLog;
            else return createUserLog(UNKNOWN, -2, "unknown");
        }
        case UNKNOWN:
        {
            return userLog;
        }
    }
}

/*
 * Function: destroyUserDatabase
 * Description: frees all memory related to the userDatabase
 * Returns: -
 */

void destroyUserDatabase(UserDatabase* userDatabase){
    for(int i = 0; i < userDatabase->providerAmount; i++){
        destroyProvider(userDatabase->providers[i]);
    }
    for(int i = 0; i < userDatabase->studentAmount; i++){
        destroyStudent(userDatabase->students[i]);
    }
    for(int i = 0; i < userDatabase->supportStaffAmount; i++){
        destroySupportStaff(userDatabase->supportStaff[i]);
    }
    for(int i = 0; i < userDatabase->userLogAmount; i++){
        destroyUserLog(userDatabase->userLogs[i]);
    }
    destroyAdmin(userDatabase->admin);
    free(userDatabase->providers);
    free(userDatabase->students);
    free(userDatabase->supportStaff);
    free(userDatabase->userLogs);
    free(userDatabase->admin);
    free(userDatabase);
}
