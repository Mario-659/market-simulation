#ifndef MARKETSIMULATION_MAP_H
#define MARKETSIMULATION_MAP_H

#include <vector>

class Person;

/**
 * @class Position
 *
 * @brief A class representing position on Map
 */
class Position
{
public:
    /**
     * Default constructor
     *
     * @post Pointer is initialized to nullptr
     * @param X X coordinate
     * @param Y Y coordinate
     */
    Position(unsigned X, unsigned Y);

    /**
     * Returns pointer to Person
     *
     * @post Does not change the object
     * @return Pointer to Person
     */
    Person* getPerson();

    /**
     * Returns x coordinate
     *
     * @post Does not change the object
     * @return x coordinate
     */
    unsigned getX();

    /**
     * Returns y coordinate
     *
     * @post Does not change the object
     * @return y coordinate
     */
    unsigned getY();

    /**
     * Sets new pointer
     *
     * @post Pointer will be updated with new value
     * @param newPtr New value of pointer
     */
    void setPointer(Person* newPtr);

    ~Position() = default;
private:
    ///Pointer to Person on position
    Person* ptr;

    ///X coordinate
    unsigned x;

    ///Y coordinate
    unsigned y;
};


/**
 * @class Map
 *
 * @brief Stores board with Positions
 */
class Map
{
public:
    /**
     * Default constructor
     *
     * Creates a square map with side of size and every position with nullptr
     *
     * @param size Size of map
     */
    Map(unsigned size);

    /**
     * Returns Position with given coordinates
     *
     * @post Does not change the object
     * @param x X coordinate
     * @param y Y coordinate
     * @return Pointer to Position
     */
    Position* getPosition(unsigned x, unsigned y);

    /**
     * Returns Position with given index
     *
     * @post Does not change the object
     * @param i Index of position in board
     * @return Pointer to Position
     */
    Position* getPosition(unsigned i);

    /**
     * Returns size of the map
     *
     * @post Does not change the object
     * @return Size of the map
     */
    unsigned getSize();

    ~Map();
private:
    ///Size of map
    const unsigned size;

    ///Board with positions
    std::vector<Position*> board;
};




#endif //MARKETSIMULATION_MAP_H
