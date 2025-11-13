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
        updateBattle();
        break;

        case Message::BATTLE_MENU_RUN:
        printf("You run from battle!\n");
        battleRunning = false;
        postMessage(Message::BATTLE_END);
        break;
    
        default:
        break;
    }

    /* okay, this is probably bad? Right now, there's no general 'update' method;
    each message sent on the message bus is basically the global 'update' call.
    so this just checks for battle win after the message has been handled in here */
    if(isBattleOver()) {
        Monster& winner = getWinner();
        printf("Winner:\t");
        winner.printInfo();
        postMessage(Message::BATTLE_END);
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
    handlePlayerTurn();
    if(!isBattleOver()) {
        handleEnemyTurn();
    }
}

bool BattleSystem::isBattleOver() { 
    if (player.getHealth() <= 0 || enemy.getHealth() <= 0) {
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
    std::cout << "You attack! Enemy takes " << enemy.takeDamage(getRandomInt(1, 5)) << " damage" << std::endl;
    isPlayerTurn = false;
}

void BattleSystem::handleEnemyTurn() {
    std::cout << "\nENEMY TURN" << std::endl;
    std::cout << "Enemy attacks! You take " << player.takeDamage(getRandomInt(1, 5)) << " damage" << std::endl;
    isPlayerTurn = true;
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