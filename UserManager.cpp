#include "UserManager.h"

void UserManager::userRegistration() {
    User user = getNewUserData();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::getNewUserData() {
    User user;
    string name, surname, login, password;

    user.setId(getIdOfNewUser());

    cout << "Podaj imie: ";
    cin >> name;
    user.setName(name);

    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(surname);

    do {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (isThereALogin(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    cin >> password;

    user.setPassword(password);

    return user;
}

void UserManager::setIdOfLoggedInUser(int newId) {
    idOfLoggedInUser = newId;
}

int UserManager::getIdOfNewUser() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isThereALogin(string login) {
    int lengthOfUsersVector = users.size();

    for (int i = 0; i < lengthOfUsersVector; i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o podanym loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::userLogin() {
    User user;
    string login = "", password = "";
    int lengthOfUsersVector = users.size();

    cout << endl << "Podaj login: ";
    login = HelperMethods::loadLine();

    for (int i = 0; i < lengthOfUsersVector; i++) {
        if (users[i].getLogin() == login) {
            for (int attempts = 3; attempts > 0; attempts--) {
                cout << "Podaj haslo. pozostalo prob " << attempts << ": ";
                password = HelperMethods::loadLine();

                if (users[i].getPassword() == password) {
                    cout << endl << "Zalogowales sie!" << endl << endl;
                    system("pause");
                    setIdOfLoggedInUser(users[i].getId());
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo!" << endl;
            system("pause");
            return;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem." << endl << endl;
    system("pause");
    return;
}

void UserManager::editPasswordOfLoggedInUser() {
    string newPassword = "";
    int lengthOfUsersVector = users.size();

    cout << "Podaj nowe haslo: ";
    newPassword = HelperMethods::loadLine();

    for (int i =0; i < lengthOfUsersVector; i++) {
        if (users[i].getId() == idOfLoggedInUser) {
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.changeUserDataInXmlFile(newPassword, idOfLoggedInUser);
}

void UserManager::userLogout() {
    idOfLoggedInUser = 0;
}

int UserManager::getIdOfLoggedInUser() {
    return idOfLoggedInUser;
}

bool UserManager::isTheUserLoggedIn() {
    if (idOfLoggedInUser > 0) {
        return true;
    } else {
        return false;
    }
}
