#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <ctime>

#include "Registry.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"

class FinanceManager {
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;
    const int ID_OF_LOGGED_IN_USER;
    vector<Registry> incomes;
    vector<Registry> expenses;
    Registry getNewRegistrationData();
    char selectDateOfOperation();
    string currentDate;
    string userDate;
    string checkCurrentDate();
    void viewDataOfRegistry(Registry registry);
    bool checkUsersDate(string date);
    bool checkLeapYear (int yearInt);
    int userId;
public:
    FinanceManager(string fileNameWithIncomes, string fileNameWithExpenses, int idOfLoggedInUser)
        :   fileWithIncomes(fileNameWithIncomes), fileWithExpenses(fileNameWithExpenses), ID_OF_LOGGED_IN_USER(idOfLoggedInUser) {
            userId = idOfLoggedInUser;
            incomes = fileWithIncomes.loadIncomesFromFile(userId);
            expenses = fileWithExpenses.loadExpensesFromFile(userId);
        };
    void addIncomes();
    void addExpenses();
    void currentMonthsBalanceSheet();
    void previousMonthsBalanceSheet();
    void balanceSheetForTheSelectedPeriod();
};





#endif
