#include "Battle.hpp"
#include "Monster.hpp"
#include "RNG.hpp"

#include <iostream>
#include <string>

void doBattle(Monster player, Monster enemy) {
    std::cout << "BATTLE START!\n-----------------" << std::endl;

    while (!battleOver(player, enemy)) {
        std::string action;
        std::cout << "Health: " << player.getHealth() << ", Enemy health: " << enemy.getHealth() << std::endl;
        std::cin >> action;
        if (!action.compare("attack")) {
            std::cout << "You attack" << std::endl;
            enemy.takeDamage(getRandomInt(1, 4));
        }
        else {
            std::cout << "Error in compare" << std::endl;
        }
    }
    std::cout << "Battle over!" << std::endl;
}

bool battleOver(Monster player, Monster enemy) { 
    if (player.getHealth() <= 0 || enemy.getHealth() <= 0)
        return true;

    return false;
    
    // return escapeFromBattle();
}