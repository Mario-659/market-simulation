#include "gtest/gtest.h"

#include "Shopkeeper.h"


TEST(ShopkeeperTest, ShopkeeperConstructor){
    auto pos = new Position(3, 6);
    Shopkeeper shopkeeper(pos);

    EXPECT_TRUE(shopkeeper.getInventory()->getMoney() == 0);

    std::vector<Item> listOfItems = Inventory::defaultListOfItems;

    ASSERT_EQ(shopkeeper.getInventory()->getItems()->size(), listOfItems.size()) << "Vector items and defaultListItems are of unequal length";
    for(int i=0; i<listOfItems.size(); i++)
    {
        Item item = shopkeeper.getInventory()->getItems()->at(i);
        EXPECT_EQ(item.getPrice(), listOfItems[i].getPrice());
        EXPECT_EQ(item.getName(), listOfItems[i].getName());

        EXPECT_TRUE(item.getAmount() >= 0   && item.getAmount() <= 6) << "Amount of " << item.getName() << " is out of range [0, 6]";

    }

    int amountOfItems;

    for(int i=0; i<listOfItems.size(); i++)
    {
        amountOfItems = shopkeeper.getInventory()->getItems()->at(i).getAmount();
        EXPECT_TRUE(amountOfItems>=0 && amountOfItems <=6) << "Amount of Items is in wrong range";
    }
}

TEST(ShopkeeperTest, makeAction){
    auto pos = new Position(13, 37);
    Shopkeeper shopkeeper(pos);
    shopkeeper.getInventory()->changeMoney(100);

    Inventory previousState = *shopkeeper.getInventory();

    for(int i=1; i<10; i++) shopkeeper.makeAction();     //increments counterToRestock, shouldn't restock yet

    for(int i=0; i<shopkeeper.getInventory()->getItems()->size(); i++)
    {
        Item item = shopkeeper.getInventory()->getItems()->at(i);
        EXPECT_EQ(item.getAmount(), previousState.getItems()->at(i).getAmount()) << "Item " << item.getName() << "at index " << i << "restocked";
    }
    shopkeeper.makeAction();           //should restock
    //checking if restocked
    bool inventoryChanged = false;
    for(int i=0; i<shopkeeper.getInventory()->getItems()->size(); i++)
    {
        Item item = shopkeeper.getInventory()->getItems()->at(i);
        if(item.getAmount() != previousState.getItems()->at(i).getAmount()) inventoryChanged = true;
    }
    EXPECT_TRUE(inventoryChanged) << "Inventory didn't restock";
}

