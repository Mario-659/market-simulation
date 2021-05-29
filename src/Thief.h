#ifndef MARKETSIMULATION_THIEF_H
#define MARKETSIMULATION_THIEF_H

#include "Person.h"

class Thief :public Person
{
public:
    ///Steals from Shopkeeper if near him
    void makeAction();

    Thief(Position* position);
private:
    ///Steals from Shopkeeper
    void steal();

    //bool isNearShopkeeper;
};

#endif //MARKETSIMULATION_THIEF_H