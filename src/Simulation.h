#ifndef MARKETSIMULATION_SIMULATION_H
#define MARKETSIMULATION_SIMULATION_H

#include "Map.h"

class Simulation
{
public:
    Simulation(unsigned size, unsigned n_customers, unsigned n_shopkeepers, unsigned n_thieves, unsigned n_guards);

    ///Runs simulation for given number of iterations
    void runSimulation(unsigned n_iterations);

    ///Next turn
    void nextIteration();

    ///Exports data to .csv
    void exportData();


private:

    ///Makes and populates map with given number of specimens
    void makeMap(unsigned size, unsigned n_customers, unsigned n_shopkeepers, unsigned n_thieves, unsigned n_guards);



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
