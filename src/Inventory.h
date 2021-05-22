#ifndef MARKETSIMULATION_INVENTORY_H
#define MARKETSIMULATION_INVENTORY_H

#include <string>
#include <vector>

class Item
{
public:
    ///Creates an Item with given name and price
    Item(std::string name, unsigned price);

    ///Returns price
    unsigned getPrice();

    ///Returns name
    std::string getName();
private:
    ///Name of an Item
    std::string name;

    ///Price of an Item
    unsigned price;
};

class Inventory
{
public:
    ///Creates an Inventory with given money and no Items
    Inventory(unsigned money);

    ///Returns global prices
    int getGlobalPrices();

    ///Changes global prices
    void changeGlobalPrices(int change);

    ///Changes money
    void changeMoney(int x);

    ///Returns money
    unsigned getMoney();

    ///Returns Items
    std::vector<Item>* getItems();

    ///Adds Item
    void addItem(Item item);
private:
    ///Global prices that are added to Items when Shopkeeper restocks
    static int GlobalPrices;

    ///Money
    unsigned money;

    ///Vector of Items
    std::vector<Item> items;       //change to pointer???
};


#endif //MARKETSIMULATION_INVENTORY_H
