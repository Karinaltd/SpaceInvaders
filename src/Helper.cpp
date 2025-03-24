#include "Helper.h"
#include <random>

int getRandomNumber(int min, int max) {
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int> distr(min, max); 

    return distr(gen);
}