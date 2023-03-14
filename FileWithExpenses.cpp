#include "FileWithExpenses.h"

void FileWithExpenses::addExpenseToXmlFile(Registry registry) {
    string amountStr = HelperMethods::checkDotInAmount(to_string(registry.getAmount()));
    string correctAmountStr = HelperMethods::cutFloat(amountStr);

    CMarkup xml;
    bool xmlExist = xml.Load(getFileName());

    if (!xmlExist) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Recorder");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Registry");
    xml.IntoElem();
    xml.AddElem("ExpenseId", registry.getRegistryId());
    xml.AddElem("UserId", registry.getUserId());
    xml.AddElem("Date", registry.getDateOfRegistry());
    xml.AddElem("Type", registry.getTypeOfRegistry());
    xml.AddElem("Amount", correctAmountStr);
    xml.Save(getFileName());
}

vector<Registry> FileWithExpenses::loadExpensesFromFile(int userId){
    Registry registry;
    vector<Registry> expenses;
    CMarkup xml;

    xml.Load(getFileName());
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem()) {
        xml.IntoElem();
        xml.FindElem();
        registry.setRegistryId(HelperMethods::convertStringToInt(xml.GetData()));
        xml.FindElem();
        registry.setUserId(HelperMethods::convertStringToInt(xml.GetData()));
        xml.FindElem();
        registry.setDate(xml.GetData());
        xml.FindElem();
        registry.setType(xml.GetData());
        xml.FindElem();
        registry.setAmount(stof(xml.GetData()));
        if (registry.getUserId() == userId){
            expenses.push_back(registry);
        }
        xml.OutOfElem();
    }
    sort(expenses.begin(), expenses.end());
    return expenses;
}

int FileWithExpenses::getLastIdFromFile() {
    int lastId = 0;
    CMarkup xml;
    xml.Load(getFileName());
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem()) {
        xml.IntoElem();
        xml.FindElem();
        lastId = HelperMethods::convertStringToInt(xml.GetData());
        xml.OutOfElem();
    }
    return lastId;
}
