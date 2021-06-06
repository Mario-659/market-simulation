#include <iostream>
#include "Simulation.h"

int main()
{
    while(true)
    {
        for (int i = 0; i < 65; i++) std::cout << "=";
        std::cout << std::endl << "\t\tWelcome in Market Simulation" << std::endl;
        for (int i = 0; i < 65; i++) std::cout << "=";
        std::cout << std::endl << std::endl << "Please type parameters of the simulation" << std::endl;
        unsigned nCustomers, nShopkeepers, nThieves, nGuards, size, nIterations;
        std::cout << "Size of the board: ";
        std::cin >> size;
        std::cout << "Number of customers: ";
        std::cin >> nCustomers;
        std::cout << "Number of shopkeepers: ";
        std::cin >> nShopkeepers;
        std::cout << "Number of thieves: ";
        std::cin >> nThieves;
        std::cout << "Number of guards: ";
        std::cin >> nGuards;
        std::cout << "Number of iterations: ";
        std::cin >> nIterations;

        try
        {
            Simulation simulation(size, nCustomers, nShopkeepers, nThieves, nGuards);
            for (int i = 0; i < nIterations; i++)
            {
                simulation.exportEvents(i);
                simulation.exportSpecies(i);
                simulation.nextIteration();
            }

            std::cout << "Data have been saved to \"Species.txt\" and to \"Events.csv\"";
            break;
        }
        catch(std::invalid_argument &e)
        {
            std::cout << e.what() << std::endl;
            continue;
        }
    }
    return 0;
}

