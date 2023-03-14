#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main() {
    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");

    char choice;

    while (true) {
        if (!personalBudget.isTheUserLoggedIn()) {
            choice = personalBudget.selectOptionFromMainMenu();

            switch (choice) {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = personalBudget.selectOptionFromUserMenu();

            switch (choice) {
            case '1':
                personalBudget.addIncomes();
                break;
            case '2':
                personalBudget.addExpenses();
                break;
            case '3':
                personalBudget.currentMonthsBalanceSheet();
                break;
            case '4':
                personalBudget.previousMonthsBalanceSheet();
                break;
            case '5':
                personalBudget.balanceSheetForTheSelectedPeriod();
                break;
            case '6':
                personalBudget.editPasswordOfLoggedInUser();
                break;
            case '9':
                personalBudget.userLogout();
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
