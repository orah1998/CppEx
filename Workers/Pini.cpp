#include "Pini.h"

#include <utility>
#include "../Factory.h"

void Pini::lowerSalary(int workerId, double reduction) {
    if (factoryPtr == nullptr) {
        cout << MISSING_FACTORY_MSG << endl;
        return;
    }
    auto worker = factoryPtr->workers[workerId];
    double newSalary = worker->getSalary() - reduction;

    if (newSalary < factoryPtr->minSalary)
        cout << MIN_SALARY_EXCEEDED_MSG << endl;
    else
        worker->setSalary(newSalary);
}

Pini &Pini::getInstance(int id, double salary, bool isBald, Factory* factoryPtr) {
    static Pini instance{ id, salary, isBald, factoryPtr };
    return instance;
}

void Pini::addWorker(const shared_ptr<BasicWorker>& worker) {
    if (factoryPtr == nullptr) {
        cout << MISSING_FACTORY_MSG << endl;
        return;
    }
    factoryPtr->workers[worker->getId()] = worker;
}

void Pini::fireWorker(int id) {
    if (factoryPtr == nullptr) {
        cout << MISSING_FACTORY_MSG << endl;
        return;
    }
    factoryPtr->workers.erase(id);
}

// Pay salaries of all workers out of the factory's balance, if it can afford them
void Pini::paySalaries() {
    double salariesSum = 0;
    if (factoryPtr == nullptr) {
        cout << MISSING_FACTORY_MSG << endl;
        return;
    }
    for (auto &workerEntry : factoryPtr->workers) {
        salariesSum += workerEntry.second->getSalary();
    }
    // Check if the factory can afford the salaries
    if (factoryPtr->balance >= salariesSum)
        factoryPtr->balance -= salariesSum;
    else
        cout << NO_SALARIES_MSG << endl;
}
