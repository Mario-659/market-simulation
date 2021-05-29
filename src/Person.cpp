#include <vector>

#include "Person.h"
#include "Random.h"

Person::Person(Position *x, unsigned money)
{
    this->position = x;
    incrementCounter();
    this->id = counter;
    x->changePointer(this);
    this->inventory = new Inventory(money);
}

Person::Person(Position *x)
{
    this->position = x;
    incrementCounter();
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


    unsigned newPosition = Random::getRandInt(0, freePositions.size()-1);
    this->position->changePointer(nullptr);
    this->position = freePositions[newPosition];
    this->position->changePointer(this);
}

//void Person::checkNeighbours(void (*action)(), Map* map)
//{
//    unsigned x, y;
//
//    x = this->position->getX();
//    y = this->position->getY();
//
//    //checks near Positions
//    for(int i=-1; i<2 ;i++)
//    {
//        if (x+i<0 || x+i>=map->getSize()) continue;  //checks if out of border
//        for(int j=-1; j<2 ;j++)
//        {
//            if (y+j<0 || y+j>=map->getSize()) continue;   //checks if out of border
//
//            Person *otherPerson = map->getPosition(x+i, y+j)->getPerson();
//            //if(otherPerson != nullptr) otherPerson->;
//        }
//    }
//}

unsigned int Person::getID()
{
    return this->id;
}

unsigned int Person::getCounter()
{
    return counter;
}

Position * Person::getPosition()
{
    return this->position;
}

Inventory * Person::getInventory()
{
    return this->inventory;
}

void Person::incrementCounter(){this->counter++;}

unsigned Person::counter = 0;

void Person::makeAction(Map* map) {};

void Person::sell(Person* buyer, unsigned probabilityOfBuying) {};

void Person::steal(Person* thief, unsigned probability) {};

void Person::catchThief(Person* guard) {};