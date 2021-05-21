#ifndef MARKETSIMULATION_INVENTORY_H
#define MARKETSIMULATION_INVENTORY_H

#include <string>
#include <vector>

class Item
{
public:
    Item(std::string, unsigned);

    unsigned getCost();

    std::string getName();

private:
    std::string name;

    unsigned cost;
};

class Inventory
{
public:
    Inventory(unsigned );

    int getGlobalPrices();

    void changeGlobalPrices(int);

    void changeMoney(int x);

    unsigned getMoney();

    std::vector<Item>* getItems();

    //void addItem(Item);
private:
    static int GlobalPrices;

    unsigned money;

    std::vector<Item> items;
};


#endif //MARKETSIMULATION_INVENTORY_H
