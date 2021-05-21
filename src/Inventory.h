#ifndef MARKETSIMULATION_INVENTORY_H
#define MARKETSIMULATION_INVENTORY_H

#include <string>
#include <vector>

class Item
{
public:
    Item(std::string name, unsigned price);

    unsigned getPrice();

    std::string getName();

private:
    std::string name;

    unsigned price;
};

class Inventory
{
public:
    Inventory(unsigned money);

    int getGlobalPrices();

    void changeGlobalPrices(int change);

    void changeMoney(int x);

    unsigned getMoney();

    std::vector<Item>* getItems();

    void addItem(Item item);
private:
    static int GlobalPrices;

    unsigned money;

    std::vector<Item> items;
};


#endif //MARKETSIMULATION_INVENTORY_H
