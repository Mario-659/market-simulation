#include <iostream>
#include "Simulation.h"

int main()
{
    Simulation simulation(2, 10, 5, 0, 0);

    for(int i=0; i<30; i++) {
        simulation.printSpecies();
        simulation.nextIteration();
        std::cout << "Iteration: " << i << "\n";
    }
    return 0;
}

