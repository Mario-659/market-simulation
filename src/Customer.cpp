#include "Customer.h"

#include "Random.h"
#include <algorithm>

Customer::Customer(Position *position) : Person(position)
{
    probabilityOfBuying = Random::getRandInt(70, 100);   //probability of buying is in range [70, 100] / 100
}

void Customer::buy(Inventory* sellersInventory)
{
    std::vector<int> sequenceOfBuying;
    for(int i=0; i<sellersInventory->getItems()->size(); i++) sequenceOfBuying.push_back(i);   // fills vector with {0, 1, 2, 3, ..., items.size()}

    std::shuffle(sequenceOfBuying.begin(), sequenceOfBuying.end(), *Random::getGenerator());    //creates random order of buying Items

//    bool canBuy = true;
//    int itemToBuy;
//    for(int i=0, j=0; Random::getDecision(probabilityOfBuying) && (canBuy==true); i++)    //int j counts Items customer cannot buy either because Shopkeeper has 0 number of given Item or the price is too high
//    {
//        itemToBuy = sequenceOfBuying.at(i);
//
//        if(sellersInventory->getItems()->at(itemToBuy).getAmount() == 0)        //checks if number of given Item in sellersInventory is != 0
//        {
//            j++;                                                        // number of Items is 0
//            if(j >= sellersInventory->getItems()->size()) canBuy = false;
//            continue;
//        }
//
//        if(this->getInventory()->getMoney() < sellersInventory->getItems()->at(itemToBuy).getPrice())
//        {
//            j++;                                                        // price is too high
//            if(j >= sellersInventory->getItems()->size()) canBuy = false;
//            continue;
//        }
//
//        sellersInventory->getItems()->at(itemToBuy).decrementAmount();
//        sellersInventory->changeMoney(sellersInventory->getItems()->at(itemToBuy).getPrice());
//
//        this->getInventory()->changeMoney(-1 * sellersInventory->getItems()->at(itemToBuy).getPrice());
//        this->getInventory()->addItem(sellersInventory->getItems()->at(itemToBuy));
//    }

//version above is messier but make sure the version below works well

    bool canBuy = true;
    for(int i=0, j=0; Random::getDecision(probabilityOfBuying) && (canBuy==true); i++)    //int j counts Items customer cannot buy either because Shopkeeper has 0 number of given Item or the price is too high
    {
        Item* itemToBuy = &(sellersInventory->getItems()->at(sequenceOfBuying.at(i)));

        if(itemToBuy->getAmount() == 0)        //checks if number of given Item in sellersInventory is != 0
        {
            j++;                                                        // number of Items is 0
            if(j >= sellersInventory->getItems()->size()) canBuy = false;
            continue;
        }

        if(this->getInventory()->getMoney() < itemToBuy->getPrice())
        {
            j++;                                                        // price is too high
            if(j >= sellersInventory->getItems()->size()) canBuy = false;
            continue;
        }

        itemToBuy->decrementAmount();
        sellersInventory->changeMoney(itemToBuy->getPrice());

        this->getInventory()->changeMoney(-1 * itemToBuy->getPrice());
        this->getInventory()->addItem(*itemToBuy);
    }
}

void Customer::makeAction(Map* map)
{
//    unsigned x, y;
//
//    x = this->getPosition()->getX();
//    y = this->getPosition()->getY();
//
//    std::vector<Shopkeeper*> nearShopkeepers;
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
}
