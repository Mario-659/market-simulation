#ifndef MARKETSIMULATION_SHOPKEEPER_H
#define MARKETSIMULATION_SHOPKEEPER_H

#include "Person.h"
#include "Inventory.h"

class Shopkeeper :public Person
{
public:
    ///After 10 uses of this makeAction it will restock
    void makeAction(Map* map);

    ///Stays in position
    void move(Map *map);

    ///Gets robbed (every Item can be stolen with a chance of probability/100)
    void steal(Person* thief, unsigned probability);

    ///Sells Items
    void sell(Person* buyer, unsigned probabilityOfBuying);

    ///Creates a Shopkeeper with random Inventory and 0 money
    Shopkeeper(Position *position);

    ~Shopkeeper();
private:
    ///Restocks it's inventory
    void restock();

    ///Margin is added to Item price when selling
    unsigned margin;
};


#endif //MARKETSIMULATION_SHOPKEEPER_H
