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

    ///Exports data to .csv
    void exportEvents(unsigned turn);

    void exportSpecies(unsigned turn);

    ///Prints state of all species
    void printSpecies();

    void printEvents(unsigned turn);

    void printEvents(unsigned turn, std::fstream* fstream);

    static void addEvent(std::string type, Person* person, Person* otherPerson, unsigned numberOfItems, unsigned money);

    static void addEvent(std::string type, Person* person, unsigned numberOfItems, unsigned money);
private:
    ///Draws
    void draw();

    Map* map;

    ///Counts turns
    unsigned turn;

    static std::string data;

    static std::vector<std::string*> events;

    void deletePreviousFiles();

    unsigned shopkeepersCounter;

    unsigned customersCounter;

    unsigned thievesCounter;

    unsigned guardsCounter;

    std::vector<Person*> population;
};


#endif //MARKETSIMULATION_SIMULATION_H
