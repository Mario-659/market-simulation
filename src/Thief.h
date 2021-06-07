#ifndef MARKETSIMULATION_THIEF_H
#define MARKETSIMULATION_THIEF_H

#include "Person.h"

/**
 * @class Thief
 *
 * @brief Represents shopkeeper
 *
 * @details Steals Items from Shopkeeper when near him. Can be caught by Guard
 */
class Thief :public Person
{
public:
    ///Creates Thief with 0 money and empty Inventory
    /**
     * Default constructor
     *
     * @post Gets 0 money and empty Inventory
     * @param position
     */
    Thief(Position* position);

    /**
     * Steals from Shopkeeper when near him
     *
     * For more details see Shopkeeper::steal
     *
     * @param map Map where other specimens are placed
     */
    void makeAction(Map* map);

    /**
     * Gets caught by Guard
     *
     * @post Gets killed
     * @param guard Pointer to Guard that caught Thief
     */
    void catchThief(Person* guard);

    ~Thief();
private:
    ///Probability of stealing an Item
    unsigned probabilityOfStealing;
};

#endif //MARKETSIMULATION_THIEF_H
