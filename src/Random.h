#ifndef MARKETSIMULATION_RANDOM_H
#define MARKETSIMULATION_RANDOM_H

#include <random>
#include <algorithm>

/**
 * @class Random
 *
 * @brief Static class that generates random outcomes
 */
class Random
{
public:
    /**
     * Returns random int in given range
     *
     * @param min Minimal value
     * @param max Maximal value
     * @return Random int value in range [min, max]
     */
    static int getRandInt(int min, int max);

    /**
     * Returns random bool value
     *
     * For example for probability of 70 there is 70% chance of returning `true`
     *
     * @pre Probability <= 100. Otherwise returns false
     * @param probability Probability of returning true value
     * @return Random bool value
     */
    static bool getDecision(unsigned probability);

    /**
     * Returns pointer to random number generator
     *
     * @return Pointer to random number generator
     */
    static std::default_random_engine* getGenerator();

    //static double getRandDouble(double min, double max);  //remove?
private:
    ///Random number generator
    static std::default_random_engine generator;
};



#endif //MARKETSIMULATION_RANDOM_H
