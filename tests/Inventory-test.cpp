#include <gtest/gtest.h>

#include "Inventory.h"

TEST(InventoryTest, ItemConstructor){
    Item a("Potato", 20);

    EXPECT_EQ(a.getCost(), 20) << "Wrong cost";
    EXPECT_EQ(a.getName(), "Potato") << "Wrong name";
}

TEST(InventoryTest, InventoryConstructor){
    Inventory inventory(50);

    EXPECT_EQ(inventory.getGlobalPrices(), 0) << "Wrong GlobalPrices";
    EXPECT_EQ(inventory.getMoney(), 50);
}
