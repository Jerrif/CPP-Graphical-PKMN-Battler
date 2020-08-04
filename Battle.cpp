#include "Battle.hpp"
#include "Monster.hpp"
#include "RNG.hpp"

#include <iostream>
#include <string>

void doBattle(Monster& player, Monster& enemy) {
    bool isPlayerTurn = true;

    // std::cout << "\nBATTLE START!\n-----------------" << std::endl;
    std::cout << "\nBATTLE START!\n" << std::endl;

    while (!battleOver(player, enemy)) {
        if (isPlayerTurn) {
            std::cout << "-----------------\nHealth: " << player.getHealth() << ", Enemy health: " << enemy.getHealth() << std::endl;
            handlePlayerTurn(player, enemy);
            isPlayerTurn = false;
        } else {
            handleEnemyTurn(player, enemy);
            isPlayerTurn = true;
        }
    }
    std::cout << "\nBATTLE OVER!" << std::endl;
}

bool battleOver(Monster& player, Monster& enemy) { 
    if (player.getHealth() <= 0 || enemy.getHealth() <= 0)
        return true;

    return false;
    
    // return escapeFromBattle();
}

void handlePlayerTurn(Monster& player, Monster& enemy) {
    std::cout << "\nPLAYER TURN" << std::endl;

    std::string action;
    std::cin >> action;
    if (!action.compare("attack")) {
        std::cout << "You attack! Enemy takes " << enemy.takeDamage(getRandomInt(1, 4)) << " damage" << std::endl;
    }
    else {
        std::cout << "Error in compare" << std::endl;
    }
}

void handleEnemyTurn(Monster& player, Monster& enemy) {
    std::cout << "\nENEMY TURN" << std::endl;
    std::cout << "Enemy attacks! You take " << player.takeDamage(getRandomInt(1, 2)) << " damage" << std::endl;
}