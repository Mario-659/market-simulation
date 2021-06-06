#include "Thief.h"
#include "Random.h"
#include "Simulation.h"

Thief::Thief(Position *position) : Person(position) {
    this->probabilityOfStealing = Random::getRandInt(0, 40);
}

void Thief::makeAction(Map* map)
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
            if(otherPerson != nullptr) otherPerson->steal(this, this->probabilityOfStealing);
        }
    }
}

void Thief::catchThief(Person *guard)
{
    if(isKilled()) return;

    unsigned sizeOfInventory = this->getInventory()->getItems()->size();    //size of Thief's Inventory
    for(int i=0; i < sizeOfInventory; i++)                     //loop for every type of Item in Inventory
    {
        Item item = this->getInventory()->getItems()->at(i);
        guard->getInventory()->addItem(item);
    }
    this->kill();
    unsigned exchangedItems, exchangedMoney;
    exchangedItems = this->getInventory()->getAmountOfItems();
    exchangedMoney = this->getInventory()->getMoney();
    Simulation::addEvent("caught", guard, this, exchangedItems, exchangedMoney);     //adds data about event

}

Thief::~Thief(){
    this->getPosition()->changePointer(nullptr);
    delete this->getInventory();
}