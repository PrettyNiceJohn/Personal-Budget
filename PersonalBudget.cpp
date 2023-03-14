#include "PersonalBudget.h"

void PersonalBudget::userRegistration() {
    userManager.userRegistration();
}

void PersonalBudget::userLogin() {
    userManager.userLogin();
    if (userManager.isTheUserLoggedIn()) {
        financeManager = new FinanceManager(FILE_NAME_WITH_INCOMES, FILE_NAME_WITH_EXPENSES, userManager.getIdOfLoggedInUser());
    }
}

char PersonalBudget::selectOptionFromMainMenu() {
    char choice;
    system("cls");

    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = HelperMethods::loadSign();

    return choice;
}

bool PersonalBudget::isTheUserLoggedIn() {
    if (userManager.isTheUserLoggedIn()) {
        return true;
    } else {
        return false;
    }
}

char PersonalBudget::selectOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "9. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = HelperMethods::loadSign();

    return choice;
}

void PersonalBudget::userLogout() {
    userManager.userLogout();
    delete financeManager;
    financeManager = NULL;
}

void PersonalBudget::editPasswordOfLoggedInUser() {
    userManager.editPasswordOfLoggedInUser();
}

void PersonalBudget::addIncomes() {
    financeManager -> addIncomes();
}

void PersonalBudget::addExpenses() {
    financeManager -> addExpenses();
}

void PersonalBudget::currentMonthsBalanceSheet() {
    financeManager -> currentMonthsBalanceSheet();
}

void PersonalBudget::previousMonthsBalanceSheet() {
    financeManager -> previousMonthsBalanceSheet();
}

void PersonalBudget::balanceSheetForTheSelectedPeriod() {
    financeManager ->balanceSheetForTheSelectedPeriod();
}
