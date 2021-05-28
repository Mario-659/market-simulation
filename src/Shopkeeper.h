#ifndef MARKETSIMULATION_SHOPKEEPER_H
#define MARKETSIMULATION_SHOPKEEPER_H

#include "Person.h"
#include "Inventory.h"

class Shopkeeper :public Person
{
public:
    ///After 10 uses of this makeAction it will restock
    void makeAction();

    Shopkeeper(Position *position);
private:
    ///Restocks it's inventory
    void restock();

    ///Margin is added to Item price
    unsigned margin;

    ///Counts when to restock
    unsigned counterToRestock;
};


#endif //MARKETSIMULATION_SHOPKEEPER_H
