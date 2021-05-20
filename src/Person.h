#ifndef MARKETSIMULATION_PERSON_H
#define MARKETSIMULATION_PERSON_H

#include "Map.h"

class Person
{
public:

    void move(Map *map);

    unsigned getID();

//    void checkNeighbours();

    Position* getPosition();

    Person(Position*);

    ~Person();
private:

    //static unsigned counter;

    unsigned id;

    Position* position;

    void increaseCounter();

    void decreaseCounter();
};


#endif //MARKETSIMULATION_PERSON_H
