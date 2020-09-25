#pragma once

#include "System.hpp"
// #include "CharacterData.hpp" // TAKE THIS OUT
#include "Monster.hpp"

#include <iostream>
#include <string>

class Monster;

class BattleSystem : public System {
public:
    BattleSystem(Monster& playerMonster, Monster& enemyMonster);
    // BattleSystem();
    ~BattleSystem();

    void handleMessage(Message& msg);

    // void initBattle(Monster* playerMonster, Monster* enemyMonster);

    void printMonsters();

    void doBattle();
    bool isBattleOver();
    bool escapeFromBattle();
    void handlePlayerTurn();
    void handleEnemyTurn();

private:
    
    // pokemonData magnemite{"Magnemite", "steel", "images/081.png", "images/081b.png"};

    bool battleRunning = false;

    bool isPlayerTurn = true;
    Monster& player;
    Monster& enemy;
    // Monster* player = new Monster{50, magnemite}; // JUST DOING THIS FOR NOW TO SILENCE ERRORS
    // Monster* enemy = new Monster{100, magnemite};// ITS BAD AND NEEDS TO BE THOUGHT THROUGH
    // Monster* player;
    // Monster* enemy;

    // bool battleOver = false;
};