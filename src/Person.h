#ifndef MARKETSIMULATION_PERSON_H
#define MARKETSIMULATION_PERSON_H

#include "Map.h"
#include "Inventory.h"

/**
 * @class Person
 *
 * Base class for species
 */
class Person
{
public:
    /**
     * Default constructor for Person
     *
     * @post Person's Inventory has no items
     * @param position Pointer to Position where Person is settled
     * @param money Money in Person's Inventory
     */
    Person(Position* position, unsigned money);

    /**
     * Overloaded constructor for Person
     *
     * @post Person's Inventory has no items and 0 money
     * @param position Pointer to Position where Person is settled
     */
    Person(Position* position);

    /**
     * Moves a Person to a random nearby Position if possible
     *
     * @post If move is possible Person changes Position
     * @param map Pointer to map
     */
    virtual void move(Map* map);

    /**
     * Returns ID
     *
     * @post Does not change object
     * @return ID
     */
    unsigned getID();

    /**
     * Returns value of counter
     *
     * @post Does not change object
     * @return Value of counter
     */
    static unsigned getCounter();

    /**
     * Returns pointer to Person's Position
     *
     * @post Does not change object
     * @return Pointer to Person's Position
     */
    Position* getPosition();

    /**
     * Returns pointer to Person's Inventory
     *
     * @post Does not change object
     * @return Pointer to Person's Inventory
     */
    Inventory* getInventory();

    /**
     * Sets `isAlive` to `false`
     *
     * @post `isAlive` is set to `false`
     */
    void kill();

    /**
     * Returns `true` if `isAlive = false`
     *
     * @post Does not change object
     * @return Bool value
     */
    bool isKilled();

    /**
     * Makes actions according to it's type
     *
     * For more information see:
     * * Shopkeeper::makeAction
     * * Customer::makeAction
     * * Thief::makeAction
     * * Guard::makeAction
     *
     * @param map Pointer to Map with other specimens
     */
    virtual void makeAction(Map* map);

    /**
     * Sells Items
     *
     * For more information see Shopkeeper::sell
     *
     * @param buyer Pointer to Customer that is buying
     * @param probabilityOfBuying Probability of buying an Item
     */
    virtual void sell(Person* buyer, unsigned probabilityOfBuying);

    /**
     * Gets robbed
     *
     * For more information see Shopkeeper::steal
     *
     * @param thief Pointer to Thief that is stealing
     * @param probability Probability of stealing
     */
    virtual void steal(Person* thief, unsigned probability);

    /**
     * Gets caught
     *
     * For more information see Thief::catchThief
     *
     * @param guard Pointer to Guard that is catching
     */
    virtual void catchThief(Person* guard);

    virtual ~Person();
private:

    ///Person's Inventory
    Inventory* inventory;

    ///Counter for assigning ID
    static unsigned counter;

    ///ID
    unsigned id;

    ///Person's position
    Position* position;

    ///Increments counter
    void incrementCounter();

    ///Person's state
    bool isAlive;
};


#endif //MARKETSIMULATION_PERSON_H
