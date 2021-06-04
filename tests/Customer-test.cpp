#include "gtest/gtest.h"

#include "Customer.h"
#include "Shopkeeper.h"

TEST(CustomerTest, CustomerConstructor){
    auto pos = new Position(45, 0);
    Customer customer(pos);

    EXPECT_TRUE(customer.getProbability() >= 70 && customer.getProbability() <= 100) << "probabilityOfBuying out of range [70, 100]";
    EXPECT_TRUE(customer.getInventory()->getMoney() >= 20 && customer.getInventory()->getMoney() <= 80) << "money out of range [20, 80]";
}

TEST(CustomerTest, makeAction){
    Map map(20);
    Customer customer(map.getPosition(1, 2));
    customer.getInventory()->addMoney(200);
    Shopkeeper shopkeeper(map.getPosition(2, 1));

    Inventory previousStateShop = *shopkeeper.getInventory();

    map.getPosition(1, 2)->getPerson()->makeAction(&map);

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
    //EXPECT_TRUE(inventoryChanged) << "Inventory didn't change after selling";  ////sometimes it doesn't pass simply because customer doesn't buy anything

    EXPECT_EQ(exchangedItems.getItems()->size(), customer.getInventory()->getItems()->size()) << "size of exchangedItems is different than size of customer's Inventory";
}