#include "utils.h"

#include <random>
#include <chrono>

int randint(int min, int max) {
    static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution distribution(min, max);
    return distribution(generator);
}