#include "Ehud.h"

Ehud::Ehud(int id, double salary, bool isBald) : BasicWorker("Ehud", id, salary, isBald) {
    // Add wise sentences
    sentences.emplace_back("Just because the message may never be received does not mean it is\n"
                             "not worth sending.");
    sentences.emplace_back("Ships are safe in harbor, but they were never meant to stay there.");
    sentences.emplace_back("Today's weirdness is tomorrow's reason why.\n"
                             "\t\t-- Hunter S. Thompson");
    sentences.emplace_back("After your lover has gone you will still have PEANUT BUTTER!");
    sentences.emplace_back("You have the capacity to learn from mistakes.  You'll learn a lot today.");
    sentences.emplace_back("Your lucky number is 3552664958674928.  Watch for it everywhere.");
    sentences.emplace_back("\"Life, loathe it or ignore it, you can't like it.\"\n"
                             "\t\t-- Marvin, \"Hitchhiker's Guide to the Galaxy\"");
    sentences.emplace_back("You don't become a failure until you're satisfied with being one.");
    sentences.emplace_back("Living your life is a task so difficult, it has never been attempted before.");
    sentences.emplace_back("Stay away from hurricanes for a while.");
}

Ehud &Ehud::getInstance(int id, double salary, bool isBald) {
    static Ehud instance{ id, salary, isBald };
    return instance;
}

void Ehud::eatBreakfast() {
    cout << BREAKFAST_MSG << endl;
}

void Ehud::run() {
    cout << WORKOUT_MSG << endl;
}

