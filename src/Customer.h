#ifndef MARKETSIMULATION_CUSTOMER_H
#define MARKETSIMULATION_CUSTOMER_H

#include "Person.h"

class Customer :public Person
{
public:
    ///Buys Items if near Shopkeeper
    void makeAction(Map* map);

    ///Creates a Customer on given position with random probabilityOfBuying
    Customer(Position *position);
private:
    ///Probability of buying an Item (in range [70, 100] / 100)
    unsigned probabilityOfBuying;
};


#endif //MARKETSIMULATION_CUSTOMER_H
