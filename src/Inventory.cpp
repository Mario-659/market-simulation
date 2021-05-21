#include "Inventory.h"



Item::Item(std::string name, unsigned int price)
{
    this->name = name;
    this->price = price;
}

unsigned int Item::getPrice(){ return price; }

std::string Item::getName(){ return name; }






Inventory::Inventory(unsigned money)
{
    this->money = money;
}

void Inventory::addItem(Item item)
{
    this->items.push_back(item);        //to be changed
}

void Inventory::changeGlobalPrices(int change)
{
    GlobalPrices += change;
}

int Inventory::getGlobalPrices()
{
    return GlobalPrices;
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

