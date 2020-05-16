#ifndef UNTITLED_EHUD_H
#define UNTITLED_EHUD_H

#include <ctime>
#include "BasicWorker.h"
using namespace std;

// 'Ehud' class is a Singleton supervisor-typed class
class Ehud : public BasicWorker {
private:
    static constexpr auto BREAKFAST_MSG{"Good Morning!"};
    static constexpr auto WORKOUT_MSG{"I am working out.."};

    Ehud(int id, double salary, bool isBald);

public:
    static Ehud& getInstance(int id=0, double salary=0.0, bool isBald=false);
    // Disable copying methods for this singleton class
    Ehud(Ehud const&) = delete;
    void operator=(Ehud const&) = delete;

    void eatBreakfast();
    void run();
};


#endif //UNTITLED_EHUD_H
