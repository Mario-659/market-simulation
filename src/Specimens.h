#ifndef MARKETSIMULATION_SPECIMENS_H
#define MARKETSIMULATION_SPECIMENS_H


#include "Person.h"
#include "Inventory.h"

class Customer :public Person
{
public:
    void makeAction();

    Customer();

private:
    void buy();

    bool isNearShopkeeper;

    unsigned probabilityOfBuying;

};

class Shopkeeper :public Person
{
public:

    void makeAction();

    void move();

    Shopkeeper();

private:
    void restock();

    unsigned margin;

    Inventory inventory;
};

class Thief :public Person
{
public:

    void makeAction();

    Thief();

private:

    void steal();

    bool isNearShopkeeper;
};

class Guard :public Person
{
public:

    void makeAction();

    Guard();

private:

    void catchThief();

    bool isNearThief;
};

#endif //MARKETSIMULATION_SPECIMENS_H
