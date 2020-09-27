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
        case Message::BATTLE_MENU_FIGHT:
        if(!isBattleOver()) {
            updateBattle();
        } else {
            printf("BATTLE OVER!\n");
            battleRunning = false;
            postMessage(Message::BATTLE_END);
        }
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

void BattleSystem::updateBattle() {
    if(!isBattleOver()) {
        handlePlayerTurn();
    }
    if(!isBattleOver()) {
        handleEnemyTurn();
    }
    if(isBattleOver()) {
        battleRunning = false;
        printf("BATTLE OVER!123\n");
        postMessage(Message::BATTLE_END);
    }
}

bool BattleSystem::isBattleOver() { 
    if (player.getHealth() <= 0 || enemy.getHealth() <= 0) {
        Monster& winner = getWinner();
        printf("Winner:\t");
        winner.printInfo();
        return true;
    }
    return false;
}

Monster& BattleSystem::getWinner() {
    if(player.getHealth() <= 0) {
        return enemy;
    } else {
        return player;
    }
}

void BattleSystem::handlePlayerTurn() {
    std::cout << "\nPLAYER TURN" << std::endl;
    std::cout << "-----------------\nHealth: " << player.getHealth() << ", Enemy health: " << enemy.getHealth() << std::endl;
    std::cout << "You attack! Enemy takes " << enemy.takeDamage(getRandomInt(1, 4)) << " damage" << std::endl;
    isPlayerTurn = false;
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