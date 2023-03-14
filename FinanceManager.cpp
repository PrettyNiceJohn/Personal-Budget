#include "FinanceManager.h"

void FinanceManager::addIncomes() {
    Registry registry = getNewRegistrationData();
    registry.setRegistryId(fileWithIncomes.getLastIdFromFile()+1);
    incomes.push_back(registry);
    sort(incomes.begin(), incomes.end());
    fileWithIncomes.addIncomeToXmlFile(registry);
}

Registry FinanceManager::getNewRegistrationData() {
    Registry registry;

    registry.setUserId(userId);

    char choice = selectDateOfOperation();

    switch (choice) {
    case '1':
        registry.setDate(checkCurrentDate());
        break;
    case '2':
        cout << "Podaj date operacji[RRRR-MM-DD]: " << endl;
        registry.setDate(HelperMethods::loadLine());
        while (!checkUsersDate(registry.getDateOfRegistry())) {
            cout << "Blad! Wpisz poprawna date z zakresu 2000-01-01 do ostatniego dnia";
            cout << endl <<"biezacego miesiaca, uwzgledniajac lata przestepne [RRRR-MM-DD]: " << endl;
            registry.setDate(HelperMethods::loadLine());
        }
        break;
    }
    system("cls");
    if (choice == 1){
        cout << "Data operacji: " << checkCurrentDate() << endl;
    } else {
        cout << "Data operacji: " << registry.getDateOfRegistry() << endl;
     }
    cout << "Podaj typ operacji: ";
    registry.setType(HelperMethods::loadLine());

    cout << "Podaj wysokosc operacji: ";
    string amountStr = HelperMethods::checkComaInAmount(HelperMethods::loadLine());
    registry.setAmount(stof(amountStr));

    return registry;
}

void FinanceManager::addExpenses() {
    Registry registry = getNewRegistrationData();
    registry.setRegistryId(fileWithExpenses.getLastIdFromFile()+1);
    expenses.push_back(registry);
    sort(expenses.begin(), expenses.end());
    fileWithExpenses.addExpenseToXmlFile(registry);
}

char FinanceManager::selectDateOfOperation() {
    char choice;

    system("cls");
    cout << "   Wybierz date operacji   " << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dzisiejsza data" << endl;
    cout << "2. Inna data" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = HelperMethods::loadSign();

    return choice;
}

void FinanceManager::currentMonthsBalanceSheet() {
    system("cls");
    float sumOfIncomes = 0.00;
    float sumOfExpenses = 0.00;
    int lengthOfVector = incomes.size();
    if (!incomes.empty()) {
        cout << "               >>> Przychody <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (int i = 0; i < lengthOfVector; i++) {
            string dateOfRegistry = incomes[i].getDateOfRegistry();
            string todaysDate = checkCurrentDate();
            string monthOfRegistry = "", currentMonth = "";
            int monthOfRegistryInt = 0;
            int currentMonthInt = 0;
            for (int i = 0; i < 10; i++) {
                if (i > 4 && i < 7) {
                    monthOfRegistry += dateOfRegistry[i];
                    currentMonth += todaysDate[i];
                }
            }
            currentMonthInt = HelperMethods::convertStringToInt(currentMonth);
            monthOfRegistryInt = HelperMethods::convertStringToInt(monthOfRegistry);

            if (monthOfRegistryInt == currentMonthInt) {
                viewDataOfRegistry(incomes[i]);
                sumOfIncomes += incomes[i].getAmount();
            }
        }
        cout << endl;
    } else {
        cout << "               >>> Przychody <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << endl << "       Brak przychodow do wyswietlenia." << endl << endl;
    }

    int lengthOfVector2 = expenses.size();
    if (!expenses.empty()) {
        cout << "                >>> Wydatki <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (int j = 0; j < lengthOfVector2; j++) {
            string dateOfRegistry = expenses[j].getDateOfRegistry();
            string todaysDate = checkCurrentDate();
            string monthOfRegistry = "", currentMonth = "";
            int monthOfRegistryInt = 0;
            int currentMonthInt = 0;
            for (int i = 0; i < 10; i++) {
                if (i > 4 && i < 7) {
                    monthOfRegistry += dateOfRegistry[i];
                    currentMonth += todaysDate[i];
                }
            }
            currentMonthInt = HelperMethods::convertStringToInt(currentMonth);
            monthOfRegistryInt = HelperMethods::convertStringToInt(monthOfRegistry);

            if (monthOfRegistryInt == currentMonthInt) {
                viewDataOfRegistry(expenses[j]);
                sumOfExpenses += expenses[j].getAmount();
            } else if (sumOfExpenses == 0) {
                cout << endl << "        Brak wydatkow w biezacym miesiacu." << endl << endl;
            }
        }
        cout << endl;
    } else {
        cout << "                >>> Wydatki <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << endl << "        Brak wydatkow do wyswietlenia." << endl << endl;
    }
    if (sumOfExpenses == 0 && sumOfIncomes == 0) {
        cout << "                 >>> Saldo <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << endl << "                  Brak danych" << endl << endl;
    } else {
        cout << "                 >>> Saldo <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Przychody:                        " << sumOfIncomes << "zl" << endl;
        cout << "Wydatki:                          " << sumOfExpenses << "zl" << endl;
        cout << endl << "Bilans:                           " << sumOfIncomes - sumOfExpenses << "zl" << endl << endl;
    }
    system("pause");
}

void FinanceManager::viewDataOfRegistry(Registry registry) {
    cout << endl << "Data:                             " << registry.getDateOfRegistry() << endl;
    cout << "Rodzaj operacji:                  " << registry.getTypeOfRegistry() << endl;
    cout << "Kwota operacji:                   " << registry.getAmount() << "zl" << endl;
    cout << endl;
}

string FinanceManager::checkCurrentDate() {
    string todaysDate = "";
    string day = "", month = "", year = "";
    int change = 1;
    char bufor[64];
    time_t period;
    time(&period);
    tm periodTM = *localtime(&period);
    setlocale(LC_ALL, "Polish");
    strftime(bufor, sizeof(bufor), "%x", &periodTM);
    for (int i = 0; i < 10; i++) {
        if (bufor[i] == '.') {
            change++;
        } else {
            switch (change) {
            case 1:
                day += bufor[i];
                break;
            case 2:
                month += bufor[i];
                break;
            case 3:
                year += bufor[i];
                break;
            }
        }
    }
    todaysDate = year + '-' + month + '-' + day;
    return todaysDate;
}

bool FinanceManager::checkUsersDate(string date) {
    bool answer;
    string todaysDate = checkCurrentDate();
    int lengthOfStringDate = date.length();
    string year = "", month = "", day = "", currentMonth = "", currentYear = "";
    for (int i = 0; i < 10; i++) {
        if (i < 4) {
            year += date[i];
            currentYear += todaysDate[i];
        } else if (i > 4 && i < 7) {
            month += date[i];
            currentMonth += todaysDate[i];
        } else if (i > 7) {
            day += date[i];
        }
    }
    int yearInt = HelperMethods::convertStringToInt(year);
    int currentYearInt = HelperMethods::convertStringToInt(currentYear);
    int monthInt = HelperMethods::convertStringToInt(month);
    int currentMonthInt = HelperMethods::convertStringToInt(currentMonth);
    int dayInt = HelperMethods::convertStringToInt(day);
    bool leapYear = checkLeapYear(yearInt);

    if (date[4] == '-' && date[7] == '-' && lengthOfStringDate == 10 && yearInt >= 2000 && monthInt > 0 && monthInt <= 12 && dayInt > 0 && dayInt <=31) {
        answer = true;
        if (leapYear == true && monthInt == 2 && dayInt <= 29) {
            answer = true;
        } else if (leapYear == false && monthInt == 2 && dayInt > 28) {
            answer = false;
        } else if (leapYear == true && monthInt == 2 && dayInt > 28) {
            answer = false;
        }
    } else {
        answer = false;
    }
    if (monthInt > currentMonthInt && yearInt == currentYearInt) {
        answer = false;
    }
    if (monthInt == currentMonthInt && yearInt > currentYearInt) {
        answer = false;
    }
    return answer;
}

bool FinanceManager::checkLeapYear(int yearInt) {
    if (((yearInt%4==0)&&(yearInt%100!=0))||(yearInt%400==0)) {
        return true;
    } else {
        return false;
    }
}

void FinanceManager::previousMonthsBalanceSheet() {
    system("cls");
    float sumOfIncomes = 0.00;
    float sumOfExpenses = 0.00;
    int lengthOfVector = incomes.size();
    if (!incomes.empty()) {
        cout << "               >>> Przychody <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (int i = 0; i < lengthOfVector; i++) {
            string dateOfRegistry = incomes[i].getDateOfRegistry();
            string todaysDate = checkCurrentDate();
            string monthOfRegistry = "", currentMonth = "";
            int monthOfRegistryInt = 0;
            int currentMonthInt = 0;
            int previousMonthInt = 0;
            for (int i = 0; i < 10; i++) {
                if (i > 4 && i < 7) {
                    monthOfRegistry += dateOfRegistry[i];
                    currentMonth += todaysDate[i];
                }
            }
            currentMonthInt = HelperMethods::convertStringToInt(currentMonth);
            monthOfRegistryInt = HelperMethods::convertStringToInt(monthOfRegistry);
            if (currentMonthInt == 1) {
                previousMonthInt = 12;
            } else {
                previousMonthInt = currentMonthInt - 1;
            }
            if (monthOfRegistryInt == previousMonthInt) {
                viewDataOfRegistry(incomes[i]);
                sumOfIncomes += incomes[i].getAmount();
            }
        }
        cout << endl;
    } else {
        cout << "               >>> Przychody <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << endl << "       Brak przychodow do wyswietlenia." << endl << endl;
    }

    int lengthOfVector2 = expenses.size();
    if (!expenses.empty()) {
        cout << "                >>> Wydatki <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (int j = 0; j < lengthOfVector2; j++) {
            string dateOfRegistry = expenses[j].getDateOfRegistry();
            string todaysDate = checkCurrentDate();
            string monthOfRegistry = "", currentMonth = "";
            int monthOfRegistryInt = 0;
            int currentMonthInt = 0;
            int previousMonthInt = 0;
            for (int i = 0; i < 10; i++) {
                if (i > 4 && i < 7) {
                    monthOfRegistry += dateOfRegistry[i];
                    currentMonth += todaysDate[i];
                }
            }
            currentMonthInt = HelperMethods::convertStringToInt(currentMonth);
            monthOfRegistryInt = HelperMethods::convertStringToInt(monthOfRegistry);
            if (currentMonthInt == 1) {
                previousMonthInt = 12;
            } else {
                previousMonthInt = currentMonthInt - 1;
            }
            if (monthOfRegistryInt == previousMonthInt) {
                viewDataOfRegistry(expenses[j]);
                sumOfExpenses += expenses[j].getAmount();
            }
        }
        cout << endl;
    } else {
        cout << "                >>> Wydatki <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << endl << "        Brak wydatkow do wyswietlenia." << endl << endl;
    }
    if (sumOfExpenses == 0 && sumOfIncomes == 0) {
        cout << "                 >>> Saldo <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << endl << "                  Brak danych" << endl << endl;
    } else {
        cout << "                 >>> Saldo <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Przychody:                        " << sumOfIncomes << " zl" << endl;
        cout << "Wydatki:                          " << sumOfExpenses << " zl" << endl;
        cout << endl << "Bilans:                           " << sumOfIncomes - sumOfExpenses << " zl" << endl << endl;
    }
    system("pause");
}

void FinanceManager::balanceSheetForTheSelectedPeriod() {
    system("cls");
    float sumOfIncomes = 0.00;
    float sumOfExpenses = 0.00;

    cout << "Wskaz poczatek okresu: [RRRR-MM-DD]" << endl;
    string beginOfPeriod = HelperMethods::loadLine();

    while (!checkUsersDate(beginOfPeriod)) {
        cout << "Blad! Wpisz poprawna date z zakresu 2000-01-01 do ostatniego dnia";
        cout << endl <<"biezacego miesiaca, uwzgledniajac lata przestepne [RRRR-MM-DD]: " << endl;
        beginOfPeriod = HelperMethods::loadLine();
    }

    cout << "Wskaz koniec okresu: [RRRR-MM-DD]" << endl;
    string endOfPeriod = HelperMethods::loadLine();

    while (!checkUsersDate(endOfPeriod)) {
        cout << "Blad! Wpisz poprawna date z zakresu 2000-01-01 do ostatniego dnia";
        cout << endl <<"biezacego miesiaca, uwzgledniajac lata przestepne [RRRR-MM-DD]: " << endl;
        endOfPeriod = HelperMethods::loadLine();
    }

    int lengthOfVector = incomes.size();
    if (!incomes.empty()) {
        cout << "               >>> Przychody <<<" << endl;
        cout << "-----------------------------------------------" << endl;

        for (int i = 0; i < lengthOfVector; i++) {
            if (incomes[i].getDateOfRegistry() >= beginOfPeriod && incomes[i].getDateOfRegistry() <= endOfPeriod) {
                viewDataOfRegistry(incomes[i]);
                sumOfIncomes += incomes[i].getAmount();
            }
        }
    } else {
        cout << "               >>> Przychody <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << endl << "       Brak przychodow do wyswietlenia." << endl << endl;
    }

    int lengthOfVector2 = expenses.size();
    if (!expenses.empty()) {
        cout << "                >>> Wydatki <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (int j = 0; j < lengthOfVector2; j++) {
            if (expenses[j].getDateOfRegistry() >= beginOfPeriod && expenses[j].getDateOfRegistry() <= endOfPeriod) {
                viewDataOfRegistry(expenses[j]);
                sumOfExpenses += expenses[j].getAmount();
            }
        }
        cout << endl;
    } else {
        cout << "                >>> Wydatki <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << endl << "        Brak wydatkow do wyswietlenia." << endl << endl;
    }
    if (sumOfExpenses == 0 && sumOfIncomes == 0) {
        cout << "                 >>> Saldo <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << endl << "                  Brak danych" << endl << endl;
    } else {
        cout << "                 >>> Saldo <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Przychody:                        " << sumOfIncomes << " zl" << endl;
        cout << "Wydatki:                          " << sumOfExpenses << " zl" << endl;
        cout << endl << "Bilans:                           " << sumOfIncomes - sumOfExpenses << " zl" << endl << endl;
    }
    system("pause");
}
