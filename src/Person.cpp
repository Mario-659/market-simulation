#include <vector>
#include <cstdlib>  //to be changed
#include <time.h>

#include "Person.h"


Person::Person(Position *x, unsigned money)
{
    this->position = x;
    increaseCounter();
    this->id = counter;
    x->changePointer(this);
    this->inventory = new Inventory(money);
}

Person::Person(Position *x)
{
    this->position = x;
    increaseCounter();
    this->id = counter;
    x->changePointer(this);
    this->inventory = new Inventory(0);

}

void Person::move(Map *map)
{

    unsigned x, y;

    x = this->position->getX();
    y = this->position->getY();

    std::vector<Position*> freePositions;

    //checks near Positions
    for(int i=-1; i<2 ;i++)
    {
        if (x+i<0 || x+i>=map->getSize()) continue;  //checks if out of border
        for(int j=-1; j<2 ;j++)
        {
            if (y+j<0 || y+j>=map->getSize()) continue;   //checks if out of border
            if(map->getPosition(x+i, y+j)->getPerson() == nullptr) freePositions.push_back(map->getPosition(x+i, y+j));
        }
    }

    if(freePositions.empty()) return; //no Positions available

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

Position * Person::getPosition()
{
    return this->position;
}

Inventory * Person::getInventory()
{
    return this->inventory;
}

void Person::increaseCounter(){this->counter++;}

void Person::decreaseCounter(){this->counter--;}

unsigned Person::counter = 0;

void Person::makeAction() {return;}