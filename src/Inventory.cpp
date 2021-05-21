#include "Inventory.h"

Item::Item(std::string Name, unsigned int Cost)
{
    this->name = Name;
    this->cost = Cost;
}

unsigned int Item::getCost(){ return cost; }

std::string Item::getName(){ return name; }



Inventory::Inventory(unsigned money)
{
    this->money = money;
}

void Inventory::changeGlobalPrices(int change)
{
    this->GlobalPrices += change;
}

int Inventory::getGlobalPrices()
{
    return this->GlobalPrices;
}

unsigned int Inventory::getMoney()
{
    return this->money;
}

void Inventory::changeMoney(int change)
{
    if (change<0 && change*-1 >= this->money)  //checks if money + change <= 0
    {
        this->money = 0;
    }
    else this->money += change;

}

std::vector<Item>* Inventory::getItems()
{
    return &items;
}

int Inventory::GlobalPrices = 0;

