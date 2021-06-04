#ifndef MARKETSIMULATION_THIEF_H
#define MARKETSIMULATION_THIEF_H

#include "Person.h"

class Thief :public Person
{
public:
    ///Steals from Shopkeeper if near him
    void makeAction(Map* map);

    ///Is caught by guard
    void catchThief(Person* guard);

    ///Creates Thief with 0 money and empty Inventory
    Thief(Position* position);

    ~Thief();
private:
    ///Probability of stealing an Item
    unsigned probabilityOfStealing;
};

#endif //MARKETSIMULATION_THIEF_H
