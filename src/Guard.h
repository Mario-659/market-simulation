#ifndef MARKETSIMULATION_GUARD_H
#define MARKETSIMULATION_GUARD_H

#include "Person.h"

class Guard :public Person
{
public:
    ///Catches Thief if near him
    void makeAction();

    Guard();
private:
    ///Returns stolen Items and deletes Thief
    void catchThief();

    //bool isNearThief;
};


#endif //MARKETSIMULATION_GUARD_H
