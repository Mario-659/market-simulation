#ifndef MARKETSIMULATION_THIEF_H
#define MARKETSIMULATION_THIEF_H

#include "Person.h"

class Thief :public Person
{
public:
    ///Steals from Shopkeeper if near him (25% of Inventory)
    void makeAction(Map* map);

    Thief(Position* position);
private:
/*    ///Steals from Shopkeeper
    void steal();*/

    unsigned probabilityOfBuying;
};

#endif //MARKETSIMULATION_THIEF_H
