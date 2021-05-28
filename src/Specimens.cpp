#include "Specimens.h"
#include "Random.h"

Shopkeeper::Shopkeeper(Position *position) : Person(position)
{
    this->margin = Random::getRandInt(0, 20);
    for(const auto & defaultItem : Inventory::defaultListOfItems)
    {
        this->getInventory()->addItem(defaultItem);
        int numberOfItems = Random::getRandInt(0, 6);
        this->getInventory()->getItems()->back().setAmount(numberOfItems);
    }
}

void Shopkeeper::restock()
{
    int itemToRestock;
    Inventory* shopInventory = this->getInventory();

    while(true)
    {
        itemToRestock = Random::getRandInt(0, shopInventory->getItems()->size()-1);
        int priceOfItem = shopInventory->getItems()->at(itemToRestock).getPrice() + this->getInventory()->getGlobalPrices();

        if(shopInventory->getMoney() >= priceOfItem)
        {
            shopInventory->changeMoney(-1 * priceOfItem);
            shopInventory->getItems()->at(itemToRestock).incrementAmount();
        }
        else return;
    }
}

void Shopkeeper::makeAction()
{
    static int turnsCounter = 0;

    turnsCounter++;
    if(turnsCounter == 10)
    {
        turnsCounter = 0;
        this->restock();
    }
}