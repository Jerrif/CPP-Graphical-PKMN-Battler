#include "GameLogicSystem.hpp"
#include "CharacterData.hpp"
#include "Monster.hpp"
#include "BattleSystem.hpp"
#include <iostream>

GameLogicSystem::GameLogicSystem() {
    printf("Constructor:\tGameLogicSystem\n");
}

GameLogicSystem::~GameLogicSystem() {
    printf("Destructor:\tGameLogicSystem\n");
}

void GameLogicSystem::handleMessage(Message* msg) {
    if(gameRunning) {
        handleMessageGameRunning(msg);
    } else {
        handleMessageGamePaused(msg);
    }
}

void GameLogicSystem::handleMessageGamePaused(Message* msg) {
    switch(msg->type) {
        case Message::GAME_START:
        printf("=====================\n");
        printf("=   GAME STARTING   =\n");
        printf("=====================\n");
        gameRunning = true;

        playerMonster = createMonster(bulbasaur);
        printMonsterInfo(playerMonster);

        printf("POSTING MESSAGE: MAIN MENU CLOSE\n");
        postMessage(Message::GUI_MAIN_MENU_CLOSE);
        printf("POSTING MESSAGE: BATTLE START\n");
        postMessage(Message::BATTLE_START);
        break;

        default:
        break;
    }
}

void GameLogicSystem::handleMessageGameRunning(Message* msg) {
    switch(msg->type) {
        case Message::BATTLE_START:
        {
        startBattle();
        break;
        }

        default:
        break;
    }
}

Monster* GameLogicSystem::createMonster(pokemonData &pokemon) {
    Monster* m = new PlayerMonster{100, pokemon};
    return m;
}

void GameLogicSystem::printMonsterInfo(Monster* m) {
    printf("%s, %s, %i\n", m->getName().c_str(), m->getType().c_str(), m->getHealth());
}

void GameLogicSystem::startBattle() {
    printf("=====================\n");
    printf("=  BATTLE STARTING  =\n");
    printf("=====================\n");
    inBattle = true;
    postMessage(Message::BATTLE_MENU_OPEN);
    Monster wildMonster{50, magnemite};
    // Monster testMonster{120, charmander};
    // BattleSystem activeBattle{testMonster, wildMonster};
    BattleSystem activeBattle{*playerMonster, wildMonster};
    activeBattle.printMonsters();
    // activeBattle.doBattle();
}