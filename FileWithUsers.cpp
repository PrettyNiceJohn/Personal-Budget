#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user) {
    CMarkup xml;
    bool fileExists = xml.Load(getFileName());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.Save(getFileName());
}

vector<User> FileWithUsers::loadUsersFromFile() {
    User user;
    vector<User> users;
    CMarkup xml;

    xml.Load(getFileName());
    xml.FindElem();
    xml.IntoElem();

    while(xml.FindElem()) {
        xml.IntoElem();

        xml.FindElem();
        user.setId(HelperMethods::convertStringToInt(xml.GetData()));

        xml.FindElem();
        user.setName(xml.GetData());

        xml.FindElem();
        user.setSurname(xml.GetData());

        xml.FindElem();
        user.setLogin(xml.GetData());

        xml.FindElem();
        user.setPassword(xml.GetData());

        users.push_back(user);
        xml.OutOfElem();
    }
    return users;
}

void FileWithUsers::changeUserDataInXmlFile(string newPassword, int idOfLoggedInUser) {
    CMarkup xml;

    xml.Load(getFileName());
    xml.FindElem();
    xml.IntoElem();

    while(xml.FindElem()) {
        xml.IntoElem();
        xml.FindElem();
        if (HelperMethods::convertStringToInt(xml.GetData()) == idOfLoggedInUser) {
            xml.FindElem();
            xml.FindElem();
            xml.FindElem();
            xml.FindElem();
            xml.SetData(newPassword);
            xml.Save(getFileName());
            break;
        }
        xml.OutOfElem();
    }
}
