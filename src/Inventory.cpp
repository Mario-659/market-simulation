#include "Inventory.h"



Item::Item(std::string name, unsigned int price)
{
    this->name = std::move(name);
    this->price = price;
    this->amount = 0;
}

unsigned int Item::getPrice(){ return price; }

std::string Item::getName(){ return name; }

unsigned int Item::getAmount() { return amount; }

void Item::setAmount(unsigned newAmount)
{
    this->amount = newAmount;
}

void Item::decrementAmount()
{
    this->amount--;
}

void Item::incrementAmount()
{
    this->amount++;
}




Inventory::Inventory(unsigned money)
{
    this->money = money;
}

Inventory::Inventory()
{
    this->money = 0;
}


void Inventory::addItem(Item item)
{
    int sizeOfInventory = this->getItems()->size();
    for(int i=0; i<sizeOfInventory && sizeOfInventory != 0; i++)
    {
        if(this->getItems()->at(i).getName() == item.getName())         //if given Item is already in Inventory then increments amount and returns
        {
            this->getItems()->at(i).incrementAmount();
            return;
        }
    }
    this->items.push_back(item);        //adds new item
    this->items.back().setAmount(1);
}

void Inventory::setGlobalPrices(int newGlobalPrices)
{
    Inventory::GlobalPrices = newGlobalPrices;
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

const std::vector<Item> Inventory::defaultListOfItems = {
        Item("carrot", 3),
        Item("apple", 5),
        Item("potato", 2),
        Item("chicken", 8),
        Item("milk", 6),
        Item("beef", 14)
        };


