#include <iostream>
#include "Simulation.h"

int main()
{
    Simulation simulation(3, 2, 2, 1, 0);



    for(int i=1; i<30; i++) {
        //simulation.printSpecies();
        simulation.nextIteration();
        //simulation.printEvents(i);
        simulation.exportEvents(i);
        simulation.exportSpecies(i);
        std::cout << "Iteration: " << i << "\n";
    }
    return 0;
}

