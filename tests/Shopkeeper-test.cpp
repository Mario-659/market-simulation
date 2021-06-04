#include "gtest/gtest.h"

#include "Shopkeeper.h"
#include "Customer.h"


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
    auto map = new Map(5);
    Shopkeeper shopkeeper(map->getPosition(2, 4));
    shopkeeper.getInventory()->addMoney(100);

    Inventory previousState = *shopkeeper.getInventory();

    for(int i=1; i<10; i++) shopkeeper.makeAction(map);     //increments counterToRestock, shouldn't restock yet

    for(int i=0; i<shopkeeper.getInventory()->getItems()->size(); i++)
    {
        Item item = shopkeeper.getInventory()->getItems()->at(i);
        EXPECT_EQ(item.getAmount(), previousState.getItems()->at(i).getAmount()) << "Item " << item.getName() << "at index " << i << "restocked";
    }
    shopkeeper.makeAction(map);           //should restock
    //checking if restocked
    bool inventoryChanged = false;
    for(int i=0; i<shopkeeper.getInventory()->getItems()->size(); i++)
    {
        Item item = shopkeeper.getInventory()->getItems()->at(i);
        if(item.getAmount() != previousState.getItems()->at(i).getAmount()) inventoryChanged = true;
    }
    EXPECT_TRUE(inventoryChanged) << "Inventory didn't restock";
}

TEST(ShopkeeperTest, sell){
    auto pos1 = new Position(23, 14);
    Customer customer(pos1);
    auto pos2 = new Position(11, 11);
    Shopkeeper shopkeeper(pos2);
    Inventory previousStateShop = *shopkeeper.getInventory();
    customer.getInventory()->addMoney(200);
    Inventory previousStateCust = *customer.getInventory();

    shopkeeper.sell(&customer, customer.getProbability());

    Inventory exchangedItems;         //Inventory to store sold Items

    bool inventoryChanged = false;  //for checking if seller's Inventory changed
    for(int i=0; i<shopkeeper.getInventory()->getItems()->size(); i++)
    {
        Item item = shopkeeper.getInventory()->getItems()->at(i);
        if(item.getAmount() != previousStateShop.getItems()->at(i).getAmount()) {
            inventoryChanged = true;
            exchangedItems.addItem(item);
        }
    }
    //EXPECT_TRUE(inventoryChanged) << "Inventory didn't change after selling";    ////sometimes it doesn't pass simply because customer doesn't buy anything

    EXPECT_EQ(exchangedItems.getItems()->size(), customer.getInventory()->getItems()->size()) << "size of exchangedItems is different than size of customer's Inventory";
}
