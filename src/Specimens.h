#ifndef MARKETSIMULATION_SPECIMENS_H
#define MARKETSIMULATION_SPECIMENS_H


#include "Person.h"
#include "Inventory.h"

class Customer :public Person
{
public:
    ///Buys Items if near Shopkeeper
    void makeAction();

    Customer();
private:
    ///Buys Items
    void buy();

//    bool isNearShopkeeper;

    ///Probability of buying an Item
    unsigned probabilityOfBuying;
};

class Shopkeeper :public Person
{
public:
    ///After 10 uses of this makeAction it will restock
    void makeAction();

    Shopkeeper();
private:
    ///Restocks it's inventory
    void restock();

    ///Margin is added to Item price
    unsigned margin;

    ///Shopkeepers Inventory
    Inventory inventory;

    ///Counts when to restock
    unsigned counterToRestock;
};

class Thief :public Person
{
public:
    ///Steals from Shopkeeper if near him
    void makeAction();

    Thief();
private:
    ///Steals from Shopkeeper
    void steal();

    //bool isNearShopkeeper;
};

class Guard :public Person
{
public:
    ///Catches Thief if near him
    void makeAction();

    Guard();
private:
    ///Returns stolen Items and deletes Thief
    void catchThief();

    //bool isNearThief;
};

#endif //MARKETSIMULATION_SPECIMENS_H
