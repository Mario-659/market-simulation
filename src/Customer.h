#ifndef MARKETSIMULATION_CUSTOMER_H
#define MARKETSIMULATION_CUSTOMER_H

#include "Person.h"

class Customer :public Person
{
public:
    ///Buys Items if near Shopkeeper
    void makeAction(Map* map);

    Customer(Position *position);
private:
    ///Buys Items
    void buy(Inventory* sellersInventory);

//    bool isNearShopkeeper;

    ///Probability of buying an Item
    unsigned probabilityOfBuying;
};


#endif //MARKETSIMULATION_CUSTOMER_H
