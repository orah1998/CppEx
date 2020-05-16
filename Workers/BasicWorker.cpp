//#include "BasicWorker.h"
#include "../Factory.h"

void BasicWorker::goBald() {
    isBald = true;
}

void BasicWorker::goUnBald() {
    isBald = false;
}

void BasicWorker::enterFactory(const Factory& factory) {
    if (isPresent) {
        cout << ALREADY_PRESENT_MSG << endl;
        return;
    }
    if (factory.isOpen())
        isPresent = true;
    else
        cout << FACTORY_CLOSED_MSG << endl;
}

void BasicWorker::exitFactory(const Factory &factory) {
    if (!isPresent) {
        cout << ALREADY_NOTPRESENT_MSG << endl;
        return;
    }
    if (factory.isOpen())
        isPresent = false;
    else
        cout << FACTORY_CLOSED_MSG << endl;
}

void BasicWorker::tellSentence() {
    srand(time(nullptr));
    cout << sentences[rand() % sentences.size()] << endl;
}

double BasicWorker::getSalary() const {
    return salary;
}

void BasicWorker::setSalary(double newSalary) {
    BasicWorker::salary = newSalary;
}

const string &BasicWorker::getName() const {
    return name;
}

int BasicWorker::getId() const {
    return id;
}
