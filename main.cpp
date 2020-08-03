#include "Monster.hpp"
#include "ConsoleColor.hpp"
#include "RNG.hpp"
#include "Battle.hpp"

#include <iostream>
#include <vector>
#include <string>

//TODO: REMEMBER RAII!

int main() {

    initRNG();

    Monster JMon(15, "Jerriforz");
    Monster MattMon(10, "MattsCool");
    Monster GraceMon(5);
    Monster dood;

    std::vector<Monster> monsters {JMon, MattMon, GraceMon, dood};

    doBattle(JMon, MattMon);
    doBattle(JMon, GraceMon);

    // for (auto mon : monsters) {
    //     std::cout << ccolor::green << mon.getName() << ccolor::white << " health: " << mon.getHealth() << std::endl;
    //     auto damageTaken = mon.takeDamage(getRandomInt(12, 15));
    //     std::cout << ccolor::red << "OUTS!" << ccolor::white << std::endl;
    //     std::cout << mon.getName() << " health: " << mon.getHealth() << " damage taken: " << damageTaken << std::endl << std::endl;
    // }
}