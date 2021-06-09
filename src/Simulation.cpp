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
#include <fstream>

std::vector<std::string*> Simulation::events;

std::string Simulation::data;

void Simulation::nextIteration()
{
    for(auto person: this->population) person->move(this->map);              //every Person other than Shopkeeper moves
    for(auto person: this->population) person->makeAction(this->map);       //every Person makes action

    for(int i=0; i<this->population.size(); i++)
    {
        if(this->population[i]->isKilled())
        {
            Position* position = population[i]->getPosition();
            delete this->population[i];

            if(i<customersCounter) population[i] = new Customer(position);
            else if(i<customersCounter+shopkeepersCounter) population[i] = new Shopkeeper(position);
            else if(i<customersCounter+shopkeepersCounter+thievesCounter) population[i] = new Thief(position);
            else population[i] = new Guard(position);
        }
    }
}

        //version below works for species that cannot move out of border (doesn't make new person when killed)
//void Simulation::nextIteration()
//{
//    for(auto person: this->population) person->move(this->map);              //every Person other than Shopkeeper moves
//    for(auto person: this->population) person->makeAction(this->map);       //every Person makes action
//
//    for(int i=0; i<this->population.size(); i++)
//    {
//        if(this->population[i]->isKilled())
//        {
//            delete this->population[i];
//            this->population.erase(this->population.begin()+i);
//            if(i<customersCounter) customersCounter--;
//            else if(i<customersCounter+shopkeepersCounter) shopkeepersCounter--;
//            else if(i<customersCounter+shopkeepersCounter+thievesCounter) thievesCounter--;
//            else guardsCounter--;
//        }
//    }
//}

Simulation::Simulation(unsigned int size, unsigned int n_customers, unsigned int n_shopkeepers, unsigned int n_thieves,
                       unsigned int n_guards)
{
    if(size*size < n_customers+n_shopkeepers+n_thieves+n_guards) throw std::invalid_argument("Size of the map is too small for given number of species");

    this->deletePreviousFiles();

    std::fstream fst;
    fst.open("Events.csv",  std::fstream::in | std::fstream::out | std::fstream::app);
    if(fst.is_open())
    {
        fst << "turn,typeOfAction,firstID,firstType,secondID,secondType,numberOfExchangedItems,exchangedMoney" << std::endl;
    }
    fst.close();

    this->map = new Map(size);

    std::vector<unsigned> specimenPlacement;
    for(int i=0; i<size*size; i++) specimenPlacement.push_back(i);
    std::shuffle(specimenPlacement.begin(), specimenPlacement.end(), *Random::getGenerator());

    this->customersCounter = 0;
    this->shopkeepersCounter = 0;
    this->thievesCounter = 0;
    this->guardsCounter = 0;

    for (unsigned i=0; i<n_customers; i++)                    //populating map with customers
    {
        unsigned specimenPosition = specimenPlacement.at(i);
        Position* position = map->getPosition(specimenPosition);
        this->population.push_back(new Customer(position));
        position->setPointer(this->population.back());
        this->customersCounter++;
    }

    for (unsigned i = n_customers; i<n_customers+n_shopkeepers; i++)                    //populating map with shopkeepers
    {
        unsigned specimenPosition = specimenPlacement.at(i);
        Position* position = map->getPosition(specimenPosition);
        this->population.push_back(new Shopkeeper(position));
        position->setPointer(this->population.back());
        this->shopkeepersCounter++;
    }

    for (unsigned i = n_customers+n_shopkeepers; i<n_customers+n_shopkeepers+n_thieves; i++)                    //populating map with thieves
    {
        unsigned specimenPosition = specimenPlacement.at(i);
        Position* position = map->getPosition(specimenPosition);
        this->population.push_back(new Thief(position));
        position->setPointer(this->population.back());
        this->thievesCounter++;
    }

    for (unsigned i = n_customers+n_shopkeepers+n_thieves; i<n_customers+n_shopkeepers+n_thieves+n_guards; i++)                    //populating map with guards
    {
        unsigned specimenPosition = specimenPlacement.at(i);
        Position* position = map->getPosition(specimenPosition);
        this->population.push_back(new Guard(position));
        position->setPointer(this->population.back());
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

void Simulation::addEvent(std::string type, Person* person, Person* otherPerson, unsigned numberOfItems, unsigned money)
{
    std::string specimen1, specimen2;
    if(type == "bought")
    {
        specimen1 = "customer";
        specimen2 = "shopkeeper";
    }
    else if (type == "stole")
    {
        specimen1 = "thief";
        specimen2 = "shopkeeper";
    }
    else if (type == "caught")
    {
        specimen1 = "guard";
        specimen2 = "thief";
    }
    else
    {
        specimen1 = "error";
        specimen2 = "error";
    }

    std::string comma = ",";
    std::string event = comma + type + comma + std::to_string(person->getID()) + comma + specimen1 + comma +
            std::to_string(otherPerson->getID()) + comma + specimen2 +  comma + std::to_string(numberOfItems) + comma + std::to_string(money);
    Simulation::events.push_back(new std::string(event));
}

void Simulation::addEvent(std::string type, Person* person, unsigned numberOfItems, unsigned money)
{
    std::string specimen1;
    if(type == "restocked"){ specimen1 = "shopkeeper"; }
    else if(type =="movedOutOfBorder"){specimen1 = "-";}
    else{ specimen1 = "error"; }

    std::string comma = ",";
    std::string event = comma + type + comma + std::to_string(person->getID()) + comma + specimen1 + comma + "-" + comma + "-" + comma + std::to_string(numberOfItems) + comma + std::to_string(money);
    Simulation::events.push_back(new std::string(event));
}

void Simulation::printEvents(unsigned turn)
{
    for(auto event: Simulation::events)
    {
        event->insert(0, std::to_string(turn));
        std::cout << *event << std::endl;
    }
    for(auto event:Simulation::events) delete event;
    Simulation::events.clear();
}

void Simulation::printEvents(unsigned turn, std::fstream* fstream)
{
    for(auto event: Simulation::events)
    {
        event->insert(0, std::to_string(turn));
        *fstream << *event << std::endl;
    }
    for(auto event:Simulation::events) delete event;
    Simulation::events.clear();
}


void Simulation::exportEvents(unsigned turn)
{
    std::fstream fs;
    fs.open("Events.csv", std::fstream::in | std::fstream::out | std::fstream::app);
    if(fs.is_open())
    {
        this->printEvents(turn, &fs);
    }
    else std::cout << "couldn't open file" << std::endl;       //to be changed

    fs.close();
}

void Simulation::exportSpecies(unsigned int turn)
{
    std::fstream fs;
    fs.open("Species.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    if(fs.is_open())
    {
        fs << "________________________________________________________________________________" << std::endl;
        fs << "Turn: " << turn << " Population: " << this->population.size() << " Shopkeepers: " << this->shopkeepersCounter <<
                                                                                " Customers:  " << this->customersCounter <<
                                                                                " Guards: " << this->guardsCounter <<
                                                                                " Thieves: " << this->thievesCounter << std::endl;
        int i = 1;
        for(auto person: this->population)
        {
            std::string type;
            if(i <= customersCounter) type = "Customer";
            else if( i<= shopkeepersCounter + customersCounter) type = "Shopkeeper";
            else if( i<= thievesCounter + customersCounter + shopkeepersCounter) type = "Thief";
            else type = "Guard";
            i++;

            fs << type << " ID: " << person->getID() << " Position: ( " << person->getPosition()->getX() << ", "
                      << person->getPosition()->getY() <<
                      ") Money: " << person->getInventory()->getMoney() << std::endl;
            if (person->getInventory()->getItems()->size() >= 1)
            {
                for (int i = 0; i < person->getInventory()->getItems()->size(); i++)
                {
                    fs << "\t Item nr " << i << ": " << person->getInventory()->getItems()->at(i).getName()
                              << " Amount: " << person->getInventory()->getItems()->at(i).getAmount() << " Price: "
                              << person->getInventory()->getItems()->at(i).getPrice() << std::endl;
                }
            }
            else
            {
                fs << " No Items" << std::endl;
            }
        }
    }
    fs.close();
}

void Simulation::deletePreviousFiles()
{
    std::remove("Species.txt");
    std::remove("Events.csv");
}

void Simulation::runSimulation(unsigned int n_iterations)
{
    this->turn = 1;
    this->exportSpecies(0);         //exports data before first iteration
    while(this->turn < n_iterations)
    {
        this->nextIteration();
        this->exportEvents(turn);
        this->exportSpecies(turn);
        turn++;
    }
    std::cout << R"(Data have been saved to "Species.txt" and to "Events.csv")";
}