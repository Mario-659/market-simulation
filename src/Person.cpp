#include <vector>

#include "Simulation.h"
#include "Person.h"
#include "Random.h"

Person::Person(Position* position, unsigned money)
{
    this->position = position;
    incrementCounter();
    this->id = counter;
    position->setPointer(this);
    this->inventory = new Inventory(money);
    this->isAlive = true;
}

Person::Person(Position* position) : Person(position, 0){}


void Person::move(Map *map)
{

    unsigned x, y;

    x = this->position->getX();
    y = this->position->getY();

    std::vector<Position*> freePositions;

    //checks near Positions
    for(int i=-1; i<2 ;i++)
    {
        for(int j=-1; j<2 ;j++)
        {
            if(x+i<0 || x+i>=map->getSize() || y+j<0 || y+j>=map->getSize()) freePositions.push_back(nullptr); //if position out of border add nullptr to freePositions

            else if(map->getPosition(x+i, y+j)->getPerson() == nullptr) freePositions.push_back(map->getPosition(x+i, y+j));   //else if position is free adds it to freePositions
        }
    }

    if(freePositions.empty()) return; //no Positions available

    unsigned newPosition = Random::getRandInt(0, freePositions.size()-1);
    this->position->setPointer(nullptr);

    if(freePositions[newPosition] == nullptr)                  //drawn position is out of border
    {
        this->kill();
        Simulation::addEvent("movedOutOfBorder", this, this->inventory->getAmountOfItems(), this->inventory->getMoney());
    }
    else                                                       //drawn position in not out of border
    {
        this->position = freePositions[newPosition];
        this->position->setPointer(this);
    }
}


void Person::kill(){ this->isAlive = false; }

bool Person::isKilled(){ return (!this->isAlive); }

unsigned int Person::getID() { return this->id; }

unsigned int Person::getCounter() { return counter; }

Position * Person::getPosition() { return this->position; }

Inventory * Person::getInventory() { return this->inventory; }

Person::~Person()
{
    this->position->setPointer(nullptr);
}

void Person::incrementCounter(){this->counter++;}

unsigned Person::counter = 0;

void Person::makeAction(Map* map) {};

void Person::sell(Person* buyer, unsigned probabilityOfBuying) {};

void Person::steal(Person* thief, unsigned probability) {};

void Person::catchThief(Person* guard) {};

//version below does not allow moving out of border
//void Person::move(Map *map)
//{
//
//    unsigned x, y;
//
//    x = this->position->getX();
//    y = this->position->getY();
//
//    std::vector<Position*> freePositions;
//
//    //checks near Positions
//    for(int i=-1; i<2 ;i++)
//    {
//        if (x+i<0 || x+i>=map->getSize()) continue;  //checks if out of border
//        for(int j=-1; j<2 ;j++)
//        {
//            if (y+j<0 || y+j>=map->getSize()) continue;   //checks if out of border
//            if(map->getPosition(x+i, y+j)->getPerson() == nullptr) freePositions.push_back(map->getPosition(x+i, y+j));
//        }
//    }
//
//    if(freePositions.empty()) return; //no Positions available
//
//
//    unsigned newPosition = Random::getRandInt(0, freePositions.size()-1);
//    this->position->setPointer(nullptr);
//    this->position = freePositions[newPosition];
//    this->position->setPointer(this);
//}
