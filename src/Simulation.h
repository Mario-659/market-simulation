#ifndef MARKETSIMULATION_SIMULATION_H
#define MARKETSIMULATION_SIMULATION_H

#include <string>
#include "Map.h"

class Simulation
{
public:
    ///Makes and populates map with given number of specimens
    Simulation(unsigned size, unsigned n_customers, unsigned n_shopkeepers, unsigned n_thieves, unsigned n_guards);

    ///Runs simulation for given number of iterations
    void runSimulation(unsigned n_iterations);

    ///Next turn
    void nextIteration();

    ///Exports data about events to Events.csv
    void exportEvents(unsigned turn);

    ///Exports data about state of species for every turn to Species.txt
    void exportSpecies(unsigned turn);

    ///Prints state of all species
    void printSpecies();

    ///Prints every event
    void printEvents(unsigned turn);

    ///Adds data about an event to buffer
    static void addEvent(std::string type, Person* person, Person* otherPerson, unsigned numberOfItems, unsigned money);

    ///Adds data about an event to buffer
    static void addEvent(std::string type, Person* person, unsigned numberOfItems, unsigned money);

    static void printWelcome();
private:

    Map* map;

    ///Counts turns
    unsigned turn;

    static std::string data;

    static std::vector<std::string*> events;

    ///Deletes data from previous run
    void deletePreviousFiles();

    void printEvents(unsigned turn, std::fstream* fstream);

    unsigned shopkeepersCounter;

    unsigned customersCounter;

    unsigned thievesCounter;

    unsigned guardsCounter;

    std::vector<Person*> population;
};


#endif //MARKETSIMULATION_SIMULATION_H
