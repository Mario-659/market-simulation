#include "Shopkeeper.h"
#include "Random.h"
#include "Simulation.h"

#include <algorithm>

Shopkeeper::Shopkeeper(Position *position) : Person(position)
{
    this->restockCounter = 0;
    this->margin = Random::getRandInt(0, 5);
    for(const auto & defaultItem : Inventory::defaultListOfItems)
    {
        this->getInventory()->addItem(defaultItem);
        int numberOfItems = Random::getRandInt(0, 6);
        this->getInventory()->getItems()->back().setAmount(numberOfItems);
        this->getInventory()->getItems()->back().addMargin(this->margin);
    }
}

void Shopkeeper::restock()
{
    Inventory inventoryBefore = *this->getInventory();

    int itemToRestock;
    Inventory* shopInventory = this->getInventory();

    bool restocked;
    while(true)
    {
        itemToRestock = Random::getRandInt(0, Inventory::defaultListOfItems.size()-1);
        int priceOfItem = shopInventory->getItems()->at(itemToRestock).getPrice() + this->getInventory()->getGlobalPrices();

        if(shopInventory->getMoney() >= priceOfItem)
        {
            shopInventory->addMoney(-1 * priceOfItem);
            shopInventory->getItems()->at(itemToRestock).incrementAmount();
            restocked = true;
        }
        else break;
    }
    if(restocked)
    {
        unsigned exchangedItems, exchangedMoney;
        exchangedItems = this->getInventory()->getAmountOfItems() - inventoryBefore.getAmountOfItems();
        exchangedMoney = inventoryBefore.getMoney() - this->getInventory()->getMoney();

        Simulation::addEvent("restocked", this, exchangedItems, exchangedMoney);     //adds data about event
    }
}

void Shopkeeper::makeAction(Map* map)
{
    this->restockCounter++;

    if(this->restockCounter == 10)
    {
        this->restockCounter = 0;
        this->restock();
    }
}

void Shopkeeper::sell(Person* buyer, unsigned probabilityOfBuying)
{
    Inventory inventoryBefore = *this->getInventory();

    unsigned sizeOfInventory = this->getInventory()->getItems()->size();    //size of Shopkeeper's Inventory

    std::vector<int> sequenceOfBuying;
    for(int i=0; i<sizeOfInventory; i++) sequenceOfBuying.push_back(i);   // fills vector with {0, 1, 2, 3, ..., sizeOfInventory-1}
    std::shuffle(sequenceOfBuying.begin(), sequenceOfBuying.end(), *Random::getGenerator());  //creates random order of buying Items

    bool canBuy = true, bought = false;
    for(int i=0, j=0; Random::getDecision(probabilityOfBuying) && (canBuy==true); i++)    //int j counts Items customer cannot buy either because Shopkeeper has 0 number of given Item or the price is too high)
    {
        if(i >= sequenceOfBuying.size()) i = 0;

        Item* itemToBuy = &(this->getInventory()->getItems()->at(sequenceOfBuying.at(i)));
        unsigned priceOfItem = itemToBuy->getPrice();

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
        this->getInventory()->addMoney(priceOfItem);

        buyer->getInventory()->addMoney(-1 * priceOfItem);
        buyer->getInventory()->addItem(*itemToBuy);
        bought = true;
    }
    if(bought)
    {
        unsigned exchangedItems, exchangedMoney;
        exchangedItems = inventoryBefore.getAmountOfItems() - this->getInventory()->getAmountOfItems();
        exchangedMoney = this->getInventory()->getMoney() - inventoryBefore.getMoney();
        Simulation::addEvent("bought", buyer, this, exchangedItems, exchangedMoney);     //adds data about event
    }
}

void Shopkeeper::steal(Person* thief, unsigned probability)
{
    unsigned sizeOfInventory = this->getInventory()->getItems()->size();    //size of Shopkeeper's Inventory

    Inventory inventoryBefore = *this->getInventory();

    bool stole = false;
    for(int i=0; i < sizeOfInventory; i++)                     //loop for every type of Item in Inventory
    {
        Item item = this->getInventory()->getItems()->at(i);
        for(unsigned j=item.getAmount(); j > 0; j--)           //loop for every number of Item
        {
            if(Random::getDecision(probability))
            {
                thief->getInventory()->addItem(item);
                this->getInventory()->getItems()->at(i).decrementAmount();
                stole = true;
            }
        }
    }

    if(stole)
    {
        unsigned exchangedItems, exchangedMoney;
        exchangedItems = inventoryBefore.getAmountOfItems() - this->getInventory()->getAmountOfItems();
        exchangedMoney = inventoryBefore.getMoney() - this->getInventory()->getMoney();

        Simulation::addEvent("stole", thief, this, exchangedItems, exchangedMoney);     //adds data about event
    }
}

Shopkeeper::~Shopkeeper()
{
    this->getPosition()->setPointer(nullptr);
    delete this->getInventory();
}

void Shopkeeper::move(Map *map) {}
