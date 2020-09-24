#pragma once

#include <iostream>
#include <string>

class Monster;

class BattleSystem {
public:
    BattleSystem(Monster& playerMonster, Monster& enemyMonster);
    ~BattleSystem();

    void printMonsters();

    void doBattle();
    bool isBattleOver();
    bool escapeFromBattle();
    void handlePlayerTurn();
    void handleEnemyTurn();

private:
    bool isPlayerTurn = true;
    Monster& player;
    Monster& enemy;
    // bool battleOver = false;
};