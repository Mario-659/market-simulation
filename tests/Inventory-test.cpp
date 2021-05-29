#include <gtest/gtest.h>

#include "Inventory.h"

TEST(InventoryTest, ItemConstructor){
    Item a("Potato", 20);

    EXPECT_EQ(a.getPrice(), 20) << "Wrong price";
    EXPECT_EQ(a.getName(), "Potato") << "Wrong name";
}

TEST(InventoryTest, InventoryConstructor){
    Inventory inventory(50);

    EXPECT_EQ(inventory.getItems()->size(), 0) << "Wrong size of Inventory";
    EXPECT_EQ(Inventory::getGlobalPrices(), 0) << "Wrong GlobalPrices";
    EXPECT_EQ(inventory.getMoney(), 50) << "Wrong amount of money";

    Inventory inventory2;

    Inventory::setGlobalPrices(20);
    EXPECT_EQ(Inventory::getGlobalPrices(), 20) << "Wrong GlobalPrices";
    EXPECT_EQ(inventory2.getMoney(), 0) << "Wrong amount of money";
}

TEST(InventoryTest, addItem){
    Inventory inventory;
    Item item1("carrot",12), item2("potato", 5);

    inventory.addItem(item1);
    //EXPECT_EQ(inventory.getItems()->at(0), item1);      doesn't compile
    EXPECT_EQ(inventory.getItems()->at(0).getAmount(), 1) << "Wrong number of Item when added to empty Inventory";
    EXPECT_EQ(inventory.getItems()->size(), 1) << "Wrong size of Inventory when Item added to empty Inventory";

    inventory.addItem(item2);
    //EXPECT_EQ(inventory.getItems()->at(1), item1);      doesn't compile
    EXPECT_EQ(inventory.getItems()->at(1).getAmount(), 1) << "Wrong incrementation when added new Item";
    EXPECT_EQ(inventory.getItems()->at(0).getAmount(), 1) << "Wrong incrementation when added new Item";
    EXPECT_EQ(inventory.getItems()->size(), 2) << "Wrong size of Inventory when added new Item";

    inventory.addItem(item2);
    //EXPECT_EQ(inventory.getItems()->at(1), item1);      doesn't compile
    EXPECT_EQ(inventory.getItems()->at(0).getAmount(), 1) << "Wrong incrementation when added new Item that is already in Inventory";
    EXPECT_EQ(inventory.getItems()->at(1).getAmount(), 2) << "Wrong incrementation when added new Item that is already in Inventory";
    EXPECT_EQ(inventory.getItems()->size(), 2) << "Wrong size of Inventory when added Item that is already in Inventory";
}
