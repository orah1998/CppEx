#ifndef UNTITLED_YOUNGSTER_H
#define UNTITLED_YOUNGSTER_H

#include "BasicWorker.h"
#include <vector>
using namespace std;

class Youngster : public BasicWorker{
private:
    static constexpr auto UNBALD_MSG{"Don't worry, it's just a matter of time..."};

public:
    Youngster(const string &name, int id, double salary, bool isBald);

    // Override goUnBald since unusable for youngsters
    void goUnBald() override final;

};


#endif //UNTITLED_YOUNGSTER_H
