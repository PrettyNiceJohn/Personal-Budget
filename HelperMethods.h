#ifndef HELPERMETHODS_H
#define HELPERMETHODS_H

#include <iostream>
#include <sstream>

using namespace std;

class HelperMethods {
public:
    static char loadSign();
    static string loadLine();
    static int convertStringToInt(string numberStr);
    static string convertIntToString(int number);
    static string checkDotInAmount(string amount);
    static string checkComaInAmount(string amount);
    static string cutFloat(string amountStr);
};

#endif
