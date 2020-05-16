#include "Factory.h"

Factory::Factory() : pini(Pini::getInstance(8888,10000, false, this)),
                     ehud(Ehud::getInstance(7777,10000, false)) {
    setOpen(true);
    // Initialize 10 youngsters
    vector<string> names{
            "Ron", "Ofer", "Xavier", "Einav", "Netta", "Ronit", "Gil", "Greg", "Sapir", "Antonia"
    };
    for (int i = 0; i < names.size(); ++i) {
        workers[1111 + i] = make_shared<Youngster>(names[i], 1111 + i, 15000, true);
    }
    // Initialize 5 drugs
    drugs["Propecia"] = make_unique<Drug>("Propecia", 130, 300, 7);
    drugs["Asparnol"] = make_unique<Drug>("Asparnol", 145, 350, 2);
    drugs["Mitrospen"] = make_unique<Drug>("Mitrospen", 115, 265, 1);
    drugs["Ezpro"] = make_unique<Drug>("Ezpro", 155, 370, 3);
    drugs["Robaven"] = make_unique<Drug>("Robaven", 200, 400, 4);
}

Factory &Factory::getInstance() {
    static Factory instance;
    return instance;
}

bool Factory::isOpen() const {
    return open;
}

void Factory::setOpen(bool value) {
    // If the factory is closed, tell all workers to exit
    if (!value) {
        for (auto &workerEntry : workers) {
            workerEntry.second->exitFactory(*this);
        }
    }
    open = value;
}

void Factory::produceDrug(const string& drugName, double productionCost, double price) {
    // Check whether or not the factory can afford to produce the drug
    if (balance >= productionCost)
        balance -= productionCost;
    else {
        cout << NO_MONEY_MSG << endl;
        return;
    }
    auto producedDrug = drugs.find(drugName);
    if (producedDrug == drugs.end())
        drugs[drugName] = make_unique<Drug>(drugName, productionCost, price, 1);
    else
        (producedDrug->second->amount)++;
}

void Factory::sellDrug(const string& drugName, int amount) {
    auto producedDrug = drugs.find(drugName);
    // Check if the factory has enough units of the requested drug
    if (producedDrug == drugs.end() or producedDrug->second->amount < amount)
        cout << NO_DRUG_MSG << endl;
    else {
        producedDrug->second->amount -= amount;
        balance += (amount * producedDrug->second->price);
    }
}
