#include <iostream>
#include "Simulation.h"

int main()
{
    Simulation simulation(20, 15, 10, 5, 5);

    for(int i=0; i<1000; i++) {
        simulation.nextIteration();
        simulation.exportData();
    }


    return 0;
}
