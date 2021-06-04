#ifndef MARKETSIMULATION_SIMULATION_H
#define MARKETSIMULATION_SIMULATION_H

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
    void exportData();

    ///Prints state of all species
    void printSpecies();
private:
    ///Draws
    void draw();

    Map* map;

    unsigned shopkeepersCounter;

    unsigned customersCounter;

    unsigned thievesCounter;

    unsigned guardsCounter;

    std::vector<Person*> population;
};


#endif //MARKETSIMULATION_SIMULATION_H
