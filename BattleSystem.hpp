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

    void doBattle();
    bool isBattleOver();
    bool escapeFromBattle();
    void handlePlayerTurn();
    void handleEnemyTurn();

private:
    bool battleRunning = true;

    bool isPlayerTurn = true;
    
    GuiBattleCommands guiBattleCommands{};

    Monster& player;
    Monster& enemy;
    // Monster* player = new Monster{50, magnemite}; // JUST DOING THIS FOR NOW TO SILENCE ERRORS
    // Monster* enemy = new Monster{100, magnemite};// ITS BAD AND NEEDS TO BE THOUGHT THROUGH
    // Monster* player;
    // Monster* enemy;

    // bool battleOver = false;
};