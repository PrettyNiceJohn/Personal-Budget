#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>

#include "Registry.h"
#include "HelperMethods.h"
#include "XmlFile.h"
#include "Markup.h"

using namespace std;

class FileWithExpenses : public XmlFile {
public:
    FileWithExpenses(string fileName) : XmlFile(fileName) {};
    void addExpenseToXmlFile(Registry registry);
    vector<Registry> loadExpensesFromFile(int userId);
    int getLastIdFromFile();
};

#endif
