#ifndef MARKETSIMULATION_MAP_H
#define MARKETSIMULATION_MAP_H

#include <vector>

class Person;

class Position
{
public:
    ///Creates a position with given coordinates and nullptr
    Position(unsigned X, unsigned Y);

    ///Returns Person
    Person* getPerson();

    ///Returns x coordinate
    unsigned getX();

    ///Returns y coordinate
    unsigned getY();

    ///Changes pointer
    void changePointer(Person*);

    ~Position();
private:
    ///Person
    Person* ptr;

    ///X coordinate
    unsigned x;

    ///Y coordinate
    unsigned y;
};



class Map
{
public:
    ///Creates a map with given size (square with a side of size)
    Map(const unsigned size);

    ///Returns Position
    Position* getPosition(unsigned, unsigned);

    ///Returns Position
    Position* getPosition(unsigned);

    ///Returns size
    unsigned getSize();

    ~Map();
private:
    ///Size of map
    const unsigned size;

    ///Board with positions
    std::vector<Position*> board;
};




#endif //MARKETSIMULATION_MAP_H
