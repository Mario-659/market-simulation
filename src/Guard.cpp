#include "Guard.h"

Guard::Guard(Position* position) :Person(position) {}

void Guard::makeAction(Map* map)
{
    unsigned x, y;

    x = this->getPosition()->getX();
    y = this->getPosition()->getY();

    //checks near Positions
    for(int i=-1; i<2 ;i++)
    {
        if (x+i<0 || x+i>=map->getSize()) continue;  //checks if out of border
        for(int j=-1; j<2 ;j++)
        {
            if (y+j<0 || y+j>=map->getSize()) continue;   //checks if out of border

            Person *otherPerson = map->getPosition(x+i, y+j)->getPerson();
            if(otherPerson != nullptr) otherPerson->catchThief(this);
        }
    }
}