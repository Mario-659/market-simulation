#ifndef MARKETSIMULATION_GUARD_H
#define MARKETSIMULATION_GUARD_H

#include "Person.h"

class Guard :public Person
{
public:
    ///Catches Thief if near him, returns stolen Items and deletes Thief
    void makeAction(Map* map);

    Guard(Position* position);

    ~Guard();
private:

};


#endif //MARKETSIMULATION_GUARD_H
