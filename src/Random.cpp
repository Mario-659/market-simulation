#include "Random.h"

#include <ctime>

std::default_random_engine Random::generator(std::time(0));

double Random::getRandDouble(double min, double max)
{
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(generator);
}

int Random::getRandInt(int min, int max)
{
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}