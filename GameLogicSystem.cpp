#include "GameLogicSystem.hpp"
#include "CharacterData.hpp"
#include "Monster.hpp"
#include "BattleSystem.hpp"
#include <iostream>
#include <cassert>

GameLogicSystem::GameLogicSystem() {
    printf("Constructor:\tGameLogicSystem\n");
    systemName = "GameLogicSystem";
}

GameLogicSystem::~GameLogicSystem() {
    printf("Destructor:\tGameLogicSystem\n");
}

void GameLogicSystem::update() {
    // if(inBattle) {
    //     activeBattle->updateBattle();
    // }
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

        playerMonster = createPlayerMonster(bulbasaur);
        printMonsterInfo(playerMonster);

        // starting the game just goes straight into a battle for now
        postMessage(Message::GUI_MAIN_MENU_CLOSE);
        postMessage(Message::BATTLE_START);
        break;

        default:
        break;
    }
}

void GameLogicSystem::handleMessageGameRunning(Message& msg) {
    switch(msg.type) {
        case Message::BATTLE_START:
        if(playerMonster->getHealth() <= 0) {
            printf("Your monster is dead!\n");
        break;
        }
        if(!inBattle) {
            printf("Starting another battle from GLS\n");
            startBattle();
        }
        break;

        case Message::BATTLE_END:
        if(inBattle) {
            printf("Ending battle from GameLogicSystem\n");
            endBattle(activeBattle);
        }
        break;

        default:
        break;
    }
}

void GameLogicSystem::startBattle() {
    printf("=====================\n");
    printf("=  BATTLE STARTING  =\n");
    printf("=====================\n");
    postMessage(Message::BATTLE_MENU_OPEN);

    wildMonster = createWildMonster(magnemite);
    activeBattle = createBattle(*playerMonster, *wildMonster);
    // attachToMessageBus(activeBattle); // this should probably go in createBattle
    activeBattle->printMonsters();

    inBattle = true;
}

BattleSystem* GameLogicSystem::createBattle(Monster& pPlayerMonster, Monster& pWildMonster) {
    BattleSystem* battle = new BattleSystem{pPlayerMonster, pWildMonster};
    attachToMessageBus(battle);
    battle->initBattle();
    return battle;
}

void GameLogicSystem::attachToMessageBus(System* s) {
    msgBus->attachToSystem(*s);
}

// I could just act straight on the member variable, without passing it in here
void GameLogicSystem::detachFromMessageBus(System* s) {
    assert(s != NULL);
    msgBus->detachSystem(*s);
}

void GameLogicSystem::endBattle(System* battle) {
    // this method should remove all traces of the battle, ready for a new one to start
    postMessage(Message::BATTLE_MENU_CLOSE);

    detachFromMessageBus(battle);

    // TODO: free resources?
    assert(activeBattle != NULL);
    delete activeBattle;
    activeBattle = NULL;
    assert(wildMonster != NULL);
    delete wildMonster;
    wildMonster = NULL;

    inBattle = false;
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
    delete playerMonster;
    playerMonster = NULL;
}

void GameLogicSystem::printMonsterInfo(Monster* m) {
    printf("%s, %s, %i\n", m->getName().c_str(), m->getType().c_str(), m->getHealth());
}