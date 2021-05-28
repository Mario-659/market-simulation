#include "gtest/gtest.h"

#include "Random.h"
#include "Specimens.h"


TEST(MarketTest, ShopkeeperConstructor){
    auto pos = new Position(3, 6);
    Shopkeeper shopkeeper(pos);

    std::vector<Item> listOfItems = Inventory::defaultListOfItems;

    ASSERT_EQ(shopkeeper.getInventory()->getItems()->size(), listOfItems.size()) << "Vector items and defaultListItems are of unequal length";
//    for(int i=0; i<listOfItems.size(); i++)
//    {
//        EXPECT_EQ((*shopkeeper.getInventory()->getItems())[i], listOfItems[i]);   //doesn't compile
//    }

    int amountOfItems;

    for(int i=0; i<listOfItems.size(); i++)
    {
        amountOfItems = shopkeeper.getInventory()->getItems()->at(i).getAmount();
        EXPECT_TRUE(amountOfItems>=0 && amountOfItems <=6) << "Amount of Items is in wrong range";
    }

}
