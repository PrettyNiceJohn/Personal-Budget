#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>

#include "User.h"
#include "HelperMethods.h"
#include "XmlFile.h"

using namespace std;

class FileWithUsers : public XmlFile {
public:
    FileWithUsers(string fileName) : XmlFile(fileName) {};
    void addUserToFile(User user);
    vector<User> loadUsersFromFile();
    void changeUserDataInXmlFile(string newPassword, int idOfLoggedInUser);
};

#endif
