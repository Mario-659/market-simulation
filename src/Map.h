#ifndef MARKETSIMULATION_MAP_H
#define MARKETSIMULATION_MAP_H

#include <vector>

class Person;

class Position
{
public:

    Position(unsigned, unsigned);

    Person* getPerson();

    unsigned getX();

    unsigned getY();

    void changePointer(Person*);
private:

    Person* ptr;

    unsigned x;

    unsigned y;
};



class Map
{
public:
    Map(const unsigned);

    Position* getPosition(unsigned, unsigned);

    unsigned getSize();

private:

    const unsigned size;

    std::vector<Position*> board;
};




#endif //MARKETSIMULATION_MAP_H
