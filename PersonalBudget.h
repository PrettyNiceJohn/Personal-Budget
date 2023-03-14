#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <ctime>
#include "UserManager.h"
#include "FinanceManager.h"

using namespace std;

class PersonalBudget {
    UserManager userManager;
    FinanceManager *financeManager;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPENSES;
public:
    PersonalBudget(string fileNameWithUsers, string fileNameWithIncomes, string fileNameWithExpenses)
        : userManager(fileNameWithUsers), FILE_NAME_WITH_INCOMES(fileNameWithIncomes), FILE_NAME_WITH_EXPENSES(fileNameWithExpenses) {
        financeManager = NULL;
    };
    ~PersonalBudget() {
        delete financeManager;
        financeManager = NULL;
    }
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
    void userRegistration();
    void userLogin();
    bool isTheUserLoggedIn();
    void userLogout();
    void editPasswordOfLoggedInUser();
    void addIncomes();
    void addExpenses();
    void currentMonthsBalanceSheet();
    void previousMonthsBalanceSheet();
    void balanceSheetForTheSelectedPeriod();
};

#endif
