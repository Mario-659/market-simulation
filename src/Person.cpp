#include <vector>
#include <cstdlib>
#include <ctime>

#include "Person.h"


Person::Person(Position* x)
{
    this->position = x;
    //increaseCounter();
    //this->id = counter;
}


void Person::move(Map *map)
{
    //give near free positions
    unsigned x, y;

    x = this->position->getX();
    y = this->position->getY();

    std::vector<Position*> freePositions;

    for(int i=-1; i<2 ;i++)
    {
        if (x+i<0 || x+i>=map->getSize()) continue;  //checks if out of border
        for(int j=-1; j<2 ;j++)
        {
            if (y+j<0 || y+j>=map->getSize()) continue;   //checks if out of border
            if(map->getPosition(x, y)->getPerson() == nullptr) freePositions.push_back(map->getPosition(x, y));
        }
    }

    srand(time(NULL));
    unsigned newPosition = rand() % freePositions.size();
    this->position->changePointer(nullptr);
    this->position = freePositions[newPosition];
    this->position->changePointer(this);
}


unsigned int Person::getID()
{
    return this->id;
}

//void Person::increaseCounter(){this->counter++;}

//void Person::decreaseCounter(){this->counter--;}