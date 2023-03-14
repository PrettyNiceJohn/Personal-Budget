#include "HelperMethods.h"

char HelperMethods::loadSign() {
    string input = "";
    char sign  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            sign = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}

string HelperMethods::loadLine() {
    string input = "";
    getline(cin, input);
    int lengthOfInput = input.length();
    if(lengthOfInput == 0){
        cout << "Musisz cos wpisac!" << endl;
        return loadLine();
    } else {
        return input;
    }
}

int HelperMethods::convertStringToInt(string numberStr) {
    int numberInt;
    istringstream iss(numberStr);
    iss >> numberInt;

    return numberInt;
}

string HelperMethods::convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}


string HelperMethods::checkDotInAmount(string amount) {
    int lengthOfStrAmount = amount.length();
    for (int i = 0; i < lengthOfStrAmount; i++) {
        if (amount[i] == ',') {
            amount[i] = '.';
        }
    }
    return amount;
}

string HelperMethods::checkComaInAmount(string amount) {
        int lengthOfStrAmount = amount.length();
    for (int i = 0; i < lengthOfStrAmount; i++) {
        if (amount[i] == '.') {
            amount[i] = ',';
        }
    }
    return amount;
}

string HelperMethods::cutDouble(string amountStr) {
    int lengthOfDouble = amountStr.length();
    string correctDouble = "";

    for (int i = 0; i < lengthOfDouble; i++) {
        correctDouble += amountStr[i];
        if (amountStr[i] == '.'){
            correctDouble += amountStr[i+1];
            correctDouble += amountStr[i+2];
                    break;
        }
    }
    return correctDouble;
}
