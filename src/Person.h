#ifndef MARKETSIMULATION_PERSON_H
#define MARKETSIMULATION_PERSON_H

#include "Map.h"
#include "Inventory.h"


class Person
{
public:

    ///Moves a Person to a random nearby Position if possible
    virtual void move(Map *map);

    ///Returns ID
    unsigned getID();

    ///Returns counter
    static unsigned getCounter();

    ///Returns a pointer to Person's Position
    Position* getPosition();

    ///Returns a pointer to Person's Inventory
    Inventory* getInventory();

    ///Creates a Person on given position and with given money in Inventory
    Person(Position*, unsigned money);

    ///Creates a Person on given position and with 0 money in Inventory
    Person(Position*);


    virtual ~Person();

    ///Makes action according to it's type
    virtual void makeAction(Map* map);

    virtual void sell(Person* buyer, unsigned probabilityOfBuying);

    virtual void steal(Person* thief, unsigned probability);

    virtual void catchThief(Person* guard);

private:

    ///Person's Inventory
    Inventory* inventory;

    ///Counter for assigning ID
    static unsigned counter;

    ///ID
    unsigned id;

    ///Person's position
    Position* position;

    ///Increments counter
    void incrementCounter();
};


#endif //MARKETSIMULATION_PERSON_H
