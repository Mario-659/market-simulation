#ifndef MARKETSIMULATION_SPECIMENS_H
#define MARKETSIMULATION_SPECIMENS_H


#include "Person.h"
#include "Inventory.h"

class Customer :public Person
{
public:
    void buy();

    Customer();

private:
    bool isNearShopkeeper;

    unsigned probabilityOfBuying;

    Inventory inventory;
};

class Shopkeeper :public Person
{
public:
    void restock();

    Shopkeeper();

private:
    unsigned margin;

    Inventory inventory;
};

class Thief :public Person
{
public:
    void steal();

    Thief();

private:
    bool isNearShopkeeper;
};

class Guard :public Person
{
public:
    void catchThief();

    Guard();

private:
    bool isNearThief;
};

#endif //MARKETSIMULATION_SPECIMENS_H
