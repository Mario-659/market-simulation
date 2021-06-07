#ifndef MARKETSIMULATION_GUARD_H
#define MARKETSIMULATION_GUARD_H

#include "Person.h"

/**
 * @class Guard
 *
 * @brief Represents guard
 *
 * @details Catches Thief when on nearby Position
 */
class Guard :public Person
{
public:
    /**
     * Default constructor for Guard
     *
     * @post Gets empty Inventory with 0 money
     * @param position Pointer to Position where Guard will be placed
     */
    Guard(Position* position);

    /**
     * Catches Thief (see Thief::catchThief) and takes his Inventory
     *
     * @param map Pointer to Map where other specimens are placed
     */
    void makeAction(Map* map);

    ~Guard();
};


#endif //MARKETSIMULATION_GUARD_H
