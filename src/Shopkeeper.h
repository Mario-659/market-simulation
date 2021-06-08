#ifndef MARKETSIMULATION_SHOPKEEPER_H
#define MARKETSIMULATION_SHOPKEEPER_H

#include "Person.h"
#include "Inventory.h"

/**
 * @class Shopkeeper
 *
 * @brief Represents shopkeeper
 *
 * @details Doesn't move. When initialized gets Inventory with items from Inventory::defaultListOfItems with random amount of every Item.
 * Can trade with Customer and be robbed by Thief
 */
class Shopkeeper :public Person
{
public:
    ///Creates a Shopkeeper with random Inventory and 0 money
    /**
     * Default constructor for Shopkeeper
     *
     * @post Gets 0 money
     * @param position Position where Shopkeeper will be settled
     */
    Shopkeeper(Position *position);

    /**
     * After 10 calls it will restock (Shopkeeper::restock)
     *
     * @param map Map where other specimens are placed
     */
    void makeAction(Map* map);

    /**
     * Stays in position
     *
     * @param map Map where other specimens are placed
     */
    void move(Map *map);

    /**
     * Gets robbed by Thief
     *
     * There is `probability` chance of stealing an Item, loops for every Item
     *
     * @param thief Pointer to Thief
     * @param probability Probability of stealing (see Random::getDecision)
     */
    void steal(Person* thief, unsigned probability);

    /**
     * Sells Items to buyer
     *
     * @param buyer Pointer to Customer
     * @param probabilityOfBuying Probability of buying (see Random::getDecision)
     */
    void sell(Person* buyer, unsigned probabilityOfBuying);

    ~Shopkeeper();
private:
    ///Restocks it's inventory
    void restock();

    ///Margin is added to Item price when selling
    unsigned margin;

    ///Counter to restock
    unsigned restockCounter;
};


#endif //MARKETSIMULATION_SHOPKEEPER_H
