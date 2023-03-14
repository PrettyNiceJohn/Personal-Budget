#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>

#include "Registry.h"
#include "HelperMethods.h"
#include "XmlFile.h"
#include "Markup.h"

using namespace std;

class FileWithIncomes : public XmlFile {
public:
    FileWithIncomes(string fileName) : XmlFile(fileName) {};
    vector<Registry> loadIncomesFromFile(int userId);
    void addIncomeToXmlFile(Registry registry);
    int getLastIdFromFile();
};

#endif
