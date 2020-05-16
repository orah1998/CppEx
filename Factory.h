#ifndef UNTITLED_FACTORY_H
#define UNTITLED_FACTORY_H

#include <unordered_map>
#include <utility>
#include "Workers/Pini.h"
#include "Workers/Ehud.h"
#include "Workers/Youngster.h"
using namespace std;

typedef struct Drug {
    string name;
    double productionCost;
    double price;
    int amount;

    Drug(string name, double productionCost, double price, int amount=0)
    : name(std::move(name))
    , productionCost(productionCost)
    , price(price)
    , amount(amount)
    {}
} Drug;

class Factory : public enable_shared_from_this<Factory> {
private:
    bool open{false};
    Pini& pini;
    Ehud& ehud;
    unordered_map<int, shared_ptr<BasicWorker>> workers;
    unordered_map<string, unique_ptr<Drug>> drugs;
    double balance{200.0};
    double minSalary{5000.0};
    static constexpr auto NO_MONEY_MSG{"The factory can't afford to produce given drug."};
    static constexpr auto NO_DRUG_MSG{"The factory does not have the requested amount of the given drug."};
    friend class Pini;

    Factory();
    void setOpen(bool open);
    void produceDrug(const string& drugName, double productionCost, double price);
    void sellDrug(const string& drugName, int amount);

public:
    static Factory& getInstance();
    // Disable copying methods for this singleton class
    Factory(Factory const&) = delete;
    void operator=(Factory const&) = delete;

    bool isOpen() const;

};


#endif //UNTITLED_FACTORY_H
