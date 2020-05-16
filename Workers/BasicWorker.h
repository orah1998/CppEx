#ifndef UNTITLED_BASICWORKER_H
#define UNTITLED_BASICWORKER_H

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

using namespace std;

// Forward declaration of the factory class
class Factory;

// A base class for workers
class BasicWorker {
protected:
    const string name;
    const int id;
    double salary;
    bool isPresent;
    bool isBald;
    vector<string> sentences;
    static constexpr auto FACTORY_CLOSED_MSG{"Factory is closed"};
    static constexpr auto ALREADY_PRESENT_MSG{"Worker is already present in factory"};
    static constexpr auto ALREADY_NOTPRESENT_MSG{"Worker is already not present in factory"};

public:
    BasicWorker(string name, int id, double salary, bool isBald)
        : name(move(name)), id(id), salary(salary), isBald(isBald), isPresent(true){}

    const string &getName() const;
    int getId() const;
    double getSalary() const;
    void setSalary(double salary);
    void goBald();
    virtual void goUnBald();
    void enterFactory(const Factory& factory);
    void exitFactory(const Factory& factory);
    virtual void tellSentence();
};


#endif //UNTITLED_BASICWORKER_H
