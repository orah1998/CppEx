#include <iostream>
#include "Factory.h"

using namespace std;

int main() {
    Factory& factory = Factory::getInstance();
    Pini &pini(Pini::getInstance());
    Ehud &ehud(Ehud::getInstance());

    return 0;
}
