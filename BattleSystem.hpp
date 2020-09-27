#pragma once

#include "System.hpp"
#include "Monster.hpp"
#include "GuiBattleCommands.hpp"

#include <iostream>
#include <string>

class Monster;

class BattleSystem : public System {
public:
    BattleSystem(Monster& playerMonster, Monster& enemyMonster);
    ~BattleSystem();

    void handleMessage(Message& msg);

    void attachToMessageBus(System& s);
    void detachFromMessageBus(System& s);

    // void initBattle(Monster* playerMonster, Monster* enemyMonster);

    void printMonsters();

    void initBattle();

    void updateBattle();
    bool isBattleOver();
    bool escapeFromBattle();
    void handlePlayerTurn();
    void handleEnemyTurn();

    Monster& getWinner();

private:
    bool battleRunning = true;

    bool isPlayerTurn = true;
    
    GuiBattleCommands guiBattleCommands{};

    Monster& player;
    Monster& enemy;

    // bool battleOver = false;
};