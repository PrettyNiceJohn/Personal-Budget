#include "FileWithIncomes.h"

void FileWithIncomes::addIncomeToXmlFile(Registry registry) {
    string amountStr = HelperMethods::checkDotInAmount(to_string(registry.getAmount()));
    string correctAmountStr = HelperMethods::cutDouble(amountStr);
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
    xml.AddElem("IncomeId", registry.getRegistryId());
    xml.AddElem("UserId", registry.getUserId());
    xml.AddElem("Date", registry.getDateOfRegistry());
    xml.AddElem("Type", registry.getTypeOfRegistry());
    xml.AddElem("Amount", correctAmountStr);
    xml.Save(getFileName());
}

vector<Registry> FileWithIncomes::loadIncomesFromFile(int userId) {
    Registry registry;
    vector<Registry> incomes;
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
        registry.setAmount(stod(xml.GetData()));
        if(registry.getUserId() == userId) {
            incomes.push_back(registry);
        }
        xml.OutOfElem();
    }
    sort(incomes.begin(), incomes.end());
    return incomes;
}

int FileWithIncomes::getLastIdFromFile() {
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
