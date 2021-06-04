#include "Simulation.h"
#include "Shopkeeper.h"
#include "Customer.h"
#include "Thief.h"
#include "Guard.h"

#include "Random.h"
#include "Map.h"
#include <algorithm>
#include "vector"

#include <iostream>



void Simulation::nextIteration()
{
    for(auto person: this->population) person->move(this->map);
    for(auto person: this->population) person->makeAction(this->map);
}

Simulation::Simulation(unsigned int size, unsigned int n_customers, unsigned int n_shopkeepers, unsigned int n_thieves,
                       unsigned int n_guards)
{
    if(size*size < n_customers+n_shopkeepers+n_thieves+n_guards) throw std::invalid_argument("Size of the map is too small for given number of species");

    this->map = new Map(size);


    std::vector<unsigned> specimenPlacement;
    for(int i=0; i<size*size; i++) specimenPlacement.push_back(i);
    std::shuffle(specimenPlacement.begin(), specimenPlacement.end(), *Random::getGenerator());

    for (unsigned i=0; i<n_customers; i++)                    //populating map with customers
    {
        unsigned specimenPosition = specimenPlacement.at(i);
        Position* position = map->getPosition(specimenPosition);
        this->population.push_back(new Customer(position));
        position->changePointer(this->population.back());
        this->customersCounter++;
    }

    for (unsigned i = n_customers; i<n_customers+n_shopkeepers; i++)                    //populating map with shopkeepers
    {
        unsigned specimenPosition = specimenPlacement.at(i);
        Position* position = map->getPosition(specimenPosition);
        this->population.push_back(new Shopkeeper(position));
        position->changePointer(this->population.back());
        this->shopkeepersCounter++;
    }

    for (unsigned i = n_customers+n_shopkeepers; i<n_customers+n_shopkeepers+n_thieves; i++)                    //populating map with thieves
    {
        unsigned specimenPosition = specimenPlacement.at(i);
        Position* position = map->getPosition(specimenPosition);
        this->population.push_back(new Thief(position));
        position->changePointer(this->population.back());
        this->thievesCounter++;
    }

    for (unsigned i = n_customers+n_shopkeepers+n_thieves; i<n_customers+n_shopkeepers+n_thieves+n_guards; i++)                    //populating map with guards
    {
        unsigned specimenPosition = specimenPlacement.at(i);
        Position* position = map->getPosition(specimenPosition);
        this->population.push_back(new Guard(position));
        position->changePointer(this->population.back());
        this->guardsCounter++;
    }
}

void Simulation::printSpecies()
{
    for(auto testPerson: this->population)
    {
        std::cout << testPerson->getID() << " Pozycja: ( " << testPerson->getPosition()->getX() << ", " << testPerson->getPosition()->getY() <<
                  ") Pieniadze: " << testPerson->getInventory()->getMoney() << std::endl;
        if(testPerson->getInventory()->getItems()->size()>=1)
        {
            for(int i = 0; i<testPerson->getInventory()->getItems()->size(); i++)
            {
                std::cout << "\t Item nr " << i << ": " << testPerson->getInventory()->getItems()->at(i).getName()
                          << " Ilosc: " << testPerson->getInventory()->getItems()->at(i).getAmount() << " cena: "
                          << testPerson->getInventory()->getItems()->at(i).getPrice() << std::endl;
            }
        }
        else
        {
            std::cout << " Brak itemow" << std::endl;
        }
    }

}

