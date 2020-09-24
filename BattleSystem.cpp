#include "BattleSystem.hpp"

#include "Monster.hpp"
#include "RNG.hpp"

#include <iostream>
#include <string>

// static bool selected = false;
// Button::Button(std::string pButtonText, Message::types msgType, bool pSelected) : buttonText{pButtonText}, tempMsg{msgType}, selected{pSelected} {
BattleSystem::BattleSystem(Monster& playerMonster, Monster& enemyMonster) 
: player{playerMonster}, enemy{enemyMonster} {
    printf("Constructor:\tBattleSystem\n");
}

BattleSystem::~BattleSystem() {
    printf("Destructor:\tBattleSystem\n");
}

void BattleSystem::printMonsters() {
    printf("%s, %s, %i\n", player.getName().c_str(), player.getType().c_str(), player.getHealth());
    printf("%s, %s, %i\n", enemy.getName().c_str(), enemy.getType().c_str(), enemy.getHealth());
}

void BattleSystem::doBattle() {
    while (!isBattleOver()) {
        if (isPlayerTurn) {
            handlePlayerTurn();
        } else {
            handleEnemyTurn();
        }
    }
    std::cout << "\nBATTLE OVER!" << std::endl;
}

bool BattleSystem::isBattleOver() { 
    if (player.getHealth() <= 0 || enemy.getHealth() <= 0)
        return true;

    return false;
    
    // return escapeFromBattle();
}

void BattleSystem::handlePlayerTurn() {

    // TODO: change battle menu selection in the battle GUI

    // if (selected && sceneHandler.selectedOption == 1) {
    // TODO: this will be something like: if(MSG == PLAYER_ATTACK) {
        std::cout << "\nPLAYER TURN" << std::endl;
        std::cout << "-----------------\nHealth: " << player.getHealth() << ", Enemy health: " << enemy.getHealth() << std::endl;
        std::cout << "You attack! Enemy takes " << enemy.takeDamage(getRandomInt(1, 4)) << " damage" << std::endl;
        isPlayerTurn = false;
    // }
    // else {
    //     selected = false;
    // }
}

void BattleSystem::handleEnemyTurn() {
    std::cout << "\nENEMY TURN" << std::endl;
    isPlayerTurn = true;
    std::cout << "Enemy attacks! You take " << player.takeDamage(getRandomInt(1, 2)) << " damage" << std::endl;
}