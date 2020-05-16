#ifndef UNTITLED_PINI_H
#define UNTITLED_PINI_H

#include <utility>

#include "BasicWorker.h"

using namespace std;

// 'Pini' class is a Singleton manager-typed class
class Pini : public BasicWorker{
private:
    static constexpr auto MISSING_FACTORY_MSG{"Missing factory pointer."};
    static constexpr auto MIN_SALARY_EXCEEDED_MSG{"Can't lower worker's salary below minimum salary."};
    static constexpr auto NO_SALARIES_MSG{"The factory can't afford workers' salaries. Please be patient."};
    Factory* factoryPtr{nullptr};

    Pini(int id, double salary, bool isBald, Factory* factoryPtr)
            : BasicWorker("Pini", id, salary, isBald), factoryPtr(factoryPtr){}

public:
    static Pini& getInstance(int id=0, double salary=0, bool isBald= false, Factory* factoryPtr=nullptr);
    // Disable copying methods for this singleton class
    Pini(Pini const&) = delete;
    void operator=(Pini const&) = delete;

    void addWorker(const shared_ptr<BasicWorker>& worker);
    void fireWorker(int id);
    void lowerSalary(int workerId, double reduction);
    void paySalaries();
    void tellSentence() override{}
};


#endif //UNTITLED_PINI_H
