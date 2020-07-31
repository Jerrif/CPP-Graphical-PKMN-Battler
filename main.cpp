#include "monster.hpp"

#include <iostream>
#include <vector>
#include <time.h>
#include <string> // already #included in monster.hpp

#define RAND() (rand()&0x7ffff) /* ensure only 15-bits. For func randGen */

uint32_t randGen()
{
    uint64_t n = 0;
    n+=RAND();
    n+=(((uint32_t)RAND()) << 15);
    n+=(((uint32_t)RAND()) << 30);
    return n;
}

int getRandomInt(int min, int max) {
    return (randGen() % max) + min;
}

int main() {

    time_t t;
    srand((unsigned) time(&t));

    //TODO: REMEMBER RAII!

    Monster JMon(100, "Jerriforz");
    Monster MattMon(100, "MattsCool");
    Monster GraceMon(100, "GraceMon");
    Monster dood;

    std::vector<Monster> monsters {JMon, MattMon, GraceMon, dood};

    // for (auto mon : monsters) {
    for (Monster mon : monsters) {
        std::cout << mon.monsterName << " health: " << mon.getHealth() << std::endl;
        mon.setHealth(getRandomInt(1, 27));
        std::cout << "OUTS!" << std::endl;
        std::cout << mon.monsterName << " health: " << mon.getHealth() << std::endl << std::endl;
    }
}