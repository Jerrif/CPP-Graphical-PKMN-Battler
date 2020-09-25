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

void GameLogicSystem::handleMessage(Message& msg) {
    if(gameRunning) {
        handleMessageGameRunning(msg);
    } else {
        handleMessageGamePaused(msg);
    }
}

void GameLogicSystem::handleMessageGamePaused(Message& msg) {
    switch(msg.type) {
        case Message::GAME_START:
        printf("=====================\n");
        printf("=   GAME STARTING   =\n");
        printf("=====================\n");
        gameRunning = true;
        postMessage(Message::GUI_MAIN_MENU_CLOSE);

        playerMonster = createPlayerMonster(bulbasaur);
        printMonsterInfo(playerMonster);

        postMessage(Message::BATTLE_START);
        startBattle();
        break;

        default:
        break;
    }
}

void GameLogicSystem::handleMessageGameRunning(Message& msg) {
    switch(msg.type) {
        // case Message::BATTLE_START:
        // {
        // startBattle();
        // break;
        // }

        default:
        break;
    }
}

Monster* GameLogicSystem::createPlayerMonster(pokemonData &pokemon) {
    Monster* m = new PlayerMonster{100, pokemon};
    return m;
}

Monster* GameLogicSystem::createWildMonster(pokemonData &pokemon) {
    Monster* m = new WildMonster{50, pokemon};
    return m;
}

void GameLogicSystem::destroyPlayerMonster() {
    // TODO: free resources
}

void GameLogicSystem::printMonsterInfo(Monster* m) {
    printf("%s, %s, %i\n", m->getName().c_str(), m->getType().c_str(), m->getHealth());
}

// void GameLogicSystem::printMonsterInfo(Monster m) {
//     printf("%s, %s, %i\n", m.getName().c_str(), m.getType().c_str(), m.getHealth());
// }

void GameLogicSystem::startBattle() {
    printf("=====================\n");
    printf("=  BATTLE STARTING  =\n");
    printf("=====================\n");
    inBattle = true;
    postMessage(Message::BATTLE_MENU_OPEN);
    // BattleSystem activeBattle{*playerMonster, wildMonster};
    // activeBattle.printMonsters();
    // activeBattle.doBattle();

    // WildMonster* wildMonster = new WildMonster{50, magnemite};
    // WildMonster wildMonster{50, magnemite};
    wildMonster = createWildMonster(magnemite);
    activeBattle = createBattle(*playerMonster, *wildMonster);
    activeBattle->printMonsters();
    attachToMessageBus();
    detachFromMessageBus();
    printf("asf\n");
}

BattleSystem* GameLogicSystem::createBattle(Monster& pPlayerMonster, Monster& pWildMonster) {
    BattleSystem* battle = new BattleSystem{pPlayerMonster, pWildMonster};
    return battle;
}

void GameLogicSystem::attachToMessageBus() {
    /* this is really bad because msgBus isn't designed to keep track of where systems are attached.
    so when you go to detach this, if another system has been attached subsequently,
    it will detach THAT system, and not this one.
    Potential solution: a separate message bus system array? */
    msgBus->attachToSystem(*activeBattle);


}

void GameLogicSystem::detachFromMessageBus() {
    if(activeBattle == NULL) {
        printf("WOAH you're trying to detach activebattle when it hasn't even been created yet\n");
        return;
    }
    msgBus->detachSystem(*activeBattle);
}

void GameLogicSystem::endBattle() {
    // TODO: detach from msg bus?
    // TODO: free resources?
}