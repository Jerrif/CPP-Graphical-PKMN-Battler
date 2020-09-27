#include "BattleSystem.hpp"
#include "GuiBattleCommands.hpp"

#include "Monster.hpp"
#include "RNG.hpp"

#include <iostream>
#include <string>

BattleSystem::BattleSystem(Monster& playerMonster, Monster& enemyMonster) 
: player{playerMonster}, enemy{enemyMonster} {
// BattleSystem::BattleSystem() {
    printf("Constructor:\tBattleSystem\n");
    systemName = "BattleSystem";
}

BattleSystem::~BattleSystem() {
    printf("Destructor:\tBattleSystem\n");
    detachFromMessageBus(guiBattleCommands);
}

void BattleSystem::handleMessage(Message& msg) {
    switch (msg.type) {
        case Message::BATTLE_MENU_OPEN:
        
        break;

        case Message::BATTLE_MENU_RUN:
        printf("You run from battle!\n");
        battleRunning = false;
        postMessage(Message::BATTLE_END);
        break;
    
        default:
        break;
    }
}

void BattleSystem::initBattle() {
    attachToMessageBus(guiBattleCommands);
}

void BattleSystem::printMonsters() {
    player.printInfo();
    enemy.printInfo();
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
    std::string poop;
    std::cin >> poop;
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

void BattleSystem::attachToMessageBus(System& s) {
    // assert(s != NULL && msgBus != NULL);
    msgBus->attachToSystem(guiBattleCommands);
    msgBus->printSystemAddresses();
}

void BattleSystem::detachFromMessageBus(System& s) {
    // assert(s != NULL);
    msgBus->detachSystem(guiBattleCommands);
}