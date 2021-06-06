#include <iostream>
#include <fstream>
#include "Simulation.h"

int main()
{
    Simulation simulation(3, 1, 2, 3, 2);

    std::fstream fst;
    fst.open("Events.csv",  std::fstream::in | std::fstream::out | std::fstream::app);
    if(fst.is_open())
    {
        fst << "turn,typeOfAction,firstID,firstType,secondID,secondType,numberOfExchangedItems,exchangedMoney" << std::endl;
    }
    fst.close();

    for(int i=1; i<30; i++) {
        //simulation.printSpecies();
        //simulation.printEvents(i);
        simulation.exportEvents(i);
        simulation.exportSpecies(i);
        simulation.nextIteration();
        std::cout << "Iteration: " << i << "\n";
    }
    return 0;
}

