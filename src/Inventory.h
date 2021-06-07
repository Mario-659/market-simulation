#ifndef MARKETSIMULATION_INVENTORY_H
#define MARKETSIMULATION_INVENTORY_H

#include <string>
#include <vector>

/**
 * @class Item
 * @brief A class representing type of item in Inventory
 *
 * This class represents a type of item not item itself so that it also consists of number of items. For example `name = "carrot"`, `price = 3`, `amount = 4`
 */
class Item
{
public:

    /**
     * Default constructor
     *
     * @param Name name of item
     * @param Price price of item
     * @param Amount number of items
     */
    Item(std::string name, unsigned price, unsigned amount);
    /**
     * Overloaded constructor
     *
     * @post Amount of items is 0
     * @param name Name of the Item
     * @param price Price of an Item
     */
    Item(std::string name, unsigned price);

    /**
     * Returns price of an item
     *
     * @post Does not change the object
     * @return Price of an item
     */
    unsigned getPrice();

    /**
     * Returns name of an item
     *
     * @post Does not change the object
     * @return Name of Item
     */
    std::string getName();

    /**
     * Returns amount of items
     *
     * @post Does not change the object
     * @return Number of items
     */
    unsigned getAmount();

    /**
     * Sets number of items
     *
     * @post Amount of items will be updated with new value
     * @param newAmount New amount of items
     */
    void setAmount(unsigned newAmount);

    /**
     * Decrements amount of items
     *
     * @post The amount of items will be decremented
     */
    void decrementAmount();

    /**
     * Increments amount of items
     *
     * @post The amount of items will be incremented
     */
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

/**
 * @class Inventory
 *
 * @brief A class representing Person's inventory
 */
class Inventory
{
public:
    /**
     * Default constructor
     *
     * @post Inventory does not have any items, money = 0
     */
    Inventory();

    /**
     * Overloaded constructor
     *
     * @post Inventory does not have any items
     * @param money Amount of money
     */
    Inventory(unsigned money);

    /**
     * Adds money to inventory
     *
     * @pre Amount to be added can be below 0
     * @post Money will be updated with added value. If (x <= money) money will be updated to 0
     * @param x Money to be added
     */
    void addMoney(int x);

    /**
     * Returns money in inventory
     *
     * @post Does not change the object
     * @return Money in inventory
     */
    unsigned getMoney();

    /**
     * Counts and returns amount of every type of items in inventory
     *
     * @post Does not change the object
     * @return Amount of all items in inventory
     */
    unsigned getAmountOfItems();

    /**
     * Returns pointer to vector with items
     *
     * @post Does not change the object
     * @return Pointer to vector with items
     */
    std::vector<Item>* getItems();

    /**
     * Adds one item of given type
     *
     * @post If given type is already in inventory then it increments it's amount, if not adds new type of item with 1 amount
     * @param item Type of item to be added
     */
    void addItem(Item item);

    ///Vector with types of all items available during simulation
    const static std::vector<Item> defaultListOfItems;

    /**
     * Sets new global prices
     *
     * @post Global prices will be updated with new value
     * @param newGlobalPrices New global prices
     */
    static void setGlobalPrices(int newGlobalPrices);

    /**
     * Returns global prices
     *
     * @post Does not change the object
     * @return Global prices
     */
    static int getGlobalPrices();

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
