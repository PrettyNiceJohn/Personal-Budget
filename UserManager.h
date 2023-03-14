#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "User.h"
#include "FileWithUsers.h"
#include "Registry.h"

using namespace std;

class UserManager {
    vector<User> users;
    User getNewUserData();
    bool isThereALogin(string login);
    FileWithUsers fileWithUsers;
public:
    UserManager(string fileNameWithUsers) : fileWithUsers(fileNameWithUsers) {
        idOfLoggedInUser = 0;
        users = fileWithUsers.loadUsersFromFile();
    };
    void userRegistration();
    void userLogin();
    void setIdOfLoggedInUser(int newId);
    void editPasswordOfLoggedInUser();
    void userLogout();
    bool isTheUserLoggedIn();
    int getIdOfNewUser();
    int getIdOfLoggedInUser();
    int idOfLoggedInUser;

};

#endif
