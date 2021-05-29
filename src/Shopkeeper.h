#ifndef MARKETSIMULATION_SHOPKEEPER_H
#define MARKETSIMULATION_SHOPKEEPER_H

#include "Person.h"
#include "Inventory.h"

class Shopkeeper :public Person
{
public:
    ///After 10 uses of this makeAction it will restock
    void makeAction();

    void steal();

    void sell(Person* buyer, unsigned probabilityOfBuying);

    Shopkeeper(Position *position);
private:
    ///Restocks it's inventory
    void restock();

    ///Margin is added to Item price when selling
    unsigned margin;
};


#endif //MARKETSIMULATION_SHOPKEEPER_H
