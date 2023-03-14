#ifndef REGISTRY_H
#define REGISTRY_H

#include <iostream>

#include "UserManager.h"

using namespace std;

class Registry {
    double amount;
    string date;
    int userId;
    string type;
    int registryId;
public:
        Registry(int userId = 0, string date = "", string type = "", double amount = 0.00, int registryId = 0) {
        this -> userId = userId;
        this -> date = date;
        this -> type = type;
        this -> amount = amount;
        this -> registryId = registryId;
    }
    void setUserId(int idOfLoggedInUser);
    void setDate(string dateOfRegistry);
    void setType(string typeOfRegistry);
    void setAmount(double amountValue);
    void setRegistryId(int regId);

    int getUserId();
    string getDateOfRegistry();
    double getAmount();
    string getTypeOfRegistry();
    int getRegistryId();

    bool operator<(const Registry &other);
};

#endif
