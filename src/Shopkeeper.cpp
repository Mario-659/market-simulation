#include "Shopkeeper.h"
#include "Random.h"

#include <algorithm>




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

void Shopkeeper::sell(Person* buyer, unsigned probabilityOfBuying)
{
    unsigned sizeOfInventory = this->getInventory()->getItems()->size();    //size of Shopkeeper's Inventory

    std::vector<int> sequenceOfBuying;
    for(int i=0; i<sizeOfInventory; i++) sequenceOfBuying.push_back(i);   // fills vector with {0, 1, 2, 3, ..., sizeOfInventory}
    std::shuffle(sequenceOfBuying.begin(), sequenceOfBuying.end(), *Random::getGenerator());  //creates random order of buying Items

    bool canBuy = true;
    for(int i=0, j=0; Random::getDecision(probabilityOfBuying) && (canBuy==true); i++)    //int j counts Items customer cannot buy either because Shopkeeper has 0 number of given Item or the price is too high)
    {
        Item* itemToBuy = &(this->getInventory()->getItems()->at(sequenceOfBuying.at(i)));
        unsigned priceOfItem = itemToBuy->getPrice() + this->margin;

        if(itemToBuy->getAmount() == 0)        //checks if number of given Item in sellersInventory is != 0
        {
            j++;                                                        // number of Items is 0
            if(j >= sizeOfInventory) canBuy = false;
            continue;
        }

        if(buyer->getInventory()->getMoney() < priceOfItem)
        {
            j++;                                                        // price is too high
            if(j >= sizeOfInventory) canBuy = false;
            continue;
        }

        itemToBuy->decrementAmount();
        buyer->getInventory()->changeMoney(priceOfItem);

        buyer->getInventory()->changeMoney(-1 * priceOfItem);
        buyer->getInventory()->addItem(*itemToBuy);
    }



}

void Shopkeeper::steal()
{

}
