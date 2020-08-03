#include <iostream>
#include <time.h>
#include <random>

void initRNG() {
    time_t t;
    std::srand((unsigned) time(&t));
}

int getRandomInt(int min, int max) {
    if (min > max) {
        std::cout << "getRandomInt error: min > max" << std::endl;
        return 1;
    }

    auto diff = (max - min) + 1;
    return (rand() % diff) + min;
}