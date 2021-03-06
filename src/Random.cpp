#include "Random.h"

#include <ctime>

std::default_random_engine Random::generator(std::time(0));



int Random::getRandInt(int min, int max)
{
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

bool Random::getDecision(unsigned int probability)
{
    int rand = Random::getRandInt(0,100);
    if(rand <= probability) return true;
    else return false;
}

std::default_random_engine * Random::getGenerator()
{
    return &Random::generator;
}

//double Random::getRandDouble(double min, double max)
//{
//    std::uniform_real_distribution<double> distribution(min, max);
//    return distribution(generator);
//}
