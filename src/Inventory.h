#ifndef MARKETSIMULATION_INVENTORY_H
#define MARKETSIMULATION_INVENTORY_H

#include <string>
#include <vector>

class Item
{
public:
    ///Creates an Item with given name and price (amount = 0)
    Item(std::string name, unsigned price);

    ///Returns price
    unsigned getPrice();

    ///Returns name
    std::string getName();

    ///Returns number of Items
    unsigned getAmount();

    ///Sets number of Items
    void setAmount(unsigned newAmount);

    ///Decrements number of Items
    void decrementAmount();

    ///Increments number of Items
    void incrementAmount();

    ~Item() = default;
private:
    ///Name of an Item
    std::string name;

    ///Price of an Item
    unsigned price;

    ///Number of Items
    unsigned amount;
};

class Inventory
{
public:
    ///Creates an Inventory with 0 money and 0 Items
    Inventory(unsigned money);

    ///Creates an Inventory with 0 money and 0 Items
    Inventory();

    ///Returns global prices
    static int getGlobalPrices();

    ///Sets global prices
    static void setGlobalPrices(int newGlobalPrices);

    ///Changes money
    void addMoney(int x);

    ///Returns money
    unsigned getMoney();

    ///Returns number of Items in Inventory
    unsigned getAmountOfItems();

    ///Returns Items
    std::vector<Item>* getItems();

    ///Adds Item
    void addItem(Item item);

    ///Default list of every Item available to buy
    const static std::vector<Item> defaultListOfItems;

    ~Inventory() = default;
private:
    ///Global prices are added to Items when Shopkeeper restocks
    static int GlobalPrices;

    ///Money
    unsigned money;

    ///Vector of Items
    std::vector<Item> items;
};


#endif //MARKETSIMULATION_INVENTORY_H
