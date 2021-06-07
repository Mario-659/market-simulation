#ifndef MARKETSIMULATION_GUARD_H
#define MARKETSIMULATION_GUARD_H

#include "Person.h"

/**
 * Catches Thief when near him
 *
 *
 */
class Guard :public Person
{
public:
    ///Catches Thief if near him, returns stolen Items and deletes Thief
    void makeAction(Map* map);

    Guard(Position* position);

    ~Guard();
};


#endif //MARKETSIMULATION_GUARD_H
