#include "Youngster.h"

Youngster::Youngster(const string &name, int id, double salary, bool isBald) : BasicWorker(name, id, salary, isBald) {
    // Add youngsters sentences
    sentences.emplace_back("Do you have to pay for courses?");
    sentences.emplace_back("Do we need to stay in uniform in team meetings outside working hours?");
    sentences.emplace_back("Should I salute to every officer I come across?");
    sentences.emplace_back("Do soldiers have discounts in buses and trains?");
    sentences.emplace_back("I started working here exactly 10 months ago today. I feel so experienced!");
    sentences.emplace_back("Until when?!");
    sentences.emplace_back("Citrix seems like a really great app!!");
    sentences.emplace_back("Do I really need to make up ten sentences for a programming exercise?");
}

void Youngster::goUnBald() {
    cout << UNBALD_MSG << endl;
}
