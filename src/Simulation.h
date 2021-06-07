#ifndef MARKETSIMULATION_SIMULATION_H
#define MARKETSIMULATION_SIMULATION_H

#include <string>
#include "Map.h"

/**
 * @class Simulation
 *
 *
 */
class Simulation
{
public:
    /**
     * Default constructor
     *
     * Makes Map with given size and randomly populates it with specimens
     *
     * @pre Population must be smaller than number of Positions (size*size)
     * @param size Size of map
     * @param n_customers Number of Customers
     * @param n_shopkeepers Number of Shopkeepers
     * @param n_thieves Number of Thieves
     * @param n_guards Number of Guards
     */
    Simulation(unsigned size, unsigned n_customers, unsigned n_shopkeepers, unsigned n_thieves, unsigned n_guards);

    /**
     * Runs Simulation for given number of iterations
     *
     * After each iterations saves exports data
     *
     * @param n_iterations Number of iterations to run
     */
    void runSimulation(unsigned n_iterations);

    /**
     * Exports data about events to Events.csv
     *
     * @param turn
     */
    void exportEvents(unsigned turn);

    /**
     * Exports data about state of species for every turn to Species.txt
     */
    void exportSpecies(unsigned turn);

    /**
     * Prints data about state of species
     */
    void printSpecies();

    /**
     * Prints data about events
     */
    void printEvents(unsigned turn);

    /**
     * Adds data about an event to static buffer
     *
     * @param type Type of event
     * @param person Pointer to first Person
     * @param otherPerson Pointer to other Person
     * @param numberOfItems Number of exchanged Items
     * @param money Amount of exchanged money
     */
    static void addEvent(std::string type, Person* person, Person* otherPerson, unsigned numberOfItems, unsigned money);

    /**
     * Adds data about an event to static buffer
     *
     * @param type Type of event
     * @param person Pointer to first Person
     * @param numberOfItems Number of exchanged Items
     * @param money Amount of exchanged money
     */
    static void addEvent(std::string type, Person* person, unsigned numberOfItems, unsigned money);
private:
    ///Pointer to Map
    Map* map;

    ///Counts turns
    unsigned turn;

    ///Buffer used for exporting data about state of species
    static std::string data;

    ///Vector of pointers to string for storing data about events
    static std::vector<std::string*> events;

    ///Deletes data from previous run
    void deletePreviousFiles();

    ///Prints events to file
    void printEvents(unsigned turn, std::fstream* fstream);

    ///Next turn
    void nextIteration();

    ///Counts population of Shopkeepers
    unsigned shopkeepersCounter;

    ///Counts population of Customers
    unsigned customersCounter;

    ///Counts population of Thieves
    unsigned thievesCounter;

    ///Counts population of Guards
    unsigned guardsCounter;

    ///Vector of pointers to every specimen in Simulation
    std::vector<Person*> population;
};


#endif //MARKETSIMULATION_SIMULATION_H
