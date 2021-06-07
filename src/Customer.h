#ifndef MARKETSIMULATION_CUSTOMER_H
#define MARKETSIMULATION_CUSTOMER_H

#include "Person.h"

/**
 * @class Customer
 *
 * @brief Represents customer
 *
 * @details Buys Items from Shopkeeper
 */
class Customer :public Person
{
public:
    /**
     * Default constructor for Customer
     *
     * @post Gets random amount of money and random value of `probabilityOfBuying`
     * @param position Pointer to Position where Customer will be settled
     */
    Customer(Position *position);

    /**
     * Buys Items when near him
     *
     * @param map Pointer to map where other specimens are placed
     */
    void makeAction(Map* map);

    /**
     * Returns value of probabilityOfBuying
     *
     * @post Does not change the object
     * @return Probability of buying
     */
    unsigned getProbability();

    ~Customer();
private:
    ///Probability of buying an Item (in range 70%-100%)
    unsigned probabilityOfBuying;
};


#endif //MARKETSIMULATION_CUSTOMER_H
