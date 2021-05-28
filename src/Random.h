#ifndef MARKETSIMULATION_RANDOM_H
#define MARKETSIMULATION_RANDOM_H

#include <random>

class Random
{
public:
    ///Returns double in range [min, max)
    static double getRandDouble(double min, double max);

    ///Returns integer in range [min, max]
    static int getRandInt(int min, int max);

    ///Returns random decision
    static bool getDecision(unsigned probability);

    static std::default_random_engine* getGenerator();

    // ///Returns double in range in Normal Distribution
    //static double getNormalDistr();
private:
    ///Random number generator
    static std::default_random_engine generator;
};



#endif //MARKETSIMULATION_RANDOM_H
