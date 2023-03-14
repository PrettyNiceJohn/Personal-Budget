#include "Registry.h"

void Registry::setAmount(float amountValue) {
    amount = amountValue;
}

void Registry::setDate(string dateOfRegistry) {
    date = dateOfRegistry;
}

void Registry::setType(string typeOfRegistry) {
    type = typeOfRegistry;
}

void Registry::setUserId(int idOfLoggedInUser) {
    userId = idOfLoggedInUser;
}

void Registry::setRegistryId(int regId) {
    registryId = regId;
}

string Registry::getDateOfRegistry() {
    return date;
}

int Registry::getUserId() {
    return userId;
}

float Registry::getAmount() {
    return amount;
}

string Registry::getTypeOfRegistry() {
    return type;
}

int Registry::getRegistryId() {
    return registryId;
}

bool Registry::operator<(const Registry &other) {
    return date < other.date;
}
