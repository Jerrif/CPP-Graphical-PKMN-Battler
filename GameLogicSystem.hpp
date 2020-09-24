#pragma once

#include "System.hpp"
#include "CharacterData.hpp"
// #include "BattleSystem.hpp"
// #include "Monster.hpp"

class Monster;

class GameLogicSystem : public System {
public:
    GameLogicSystem();
    ~GameLogicSystem();

    void handleMessage(Message* msg);
    void handleMessageGamePaused(Message* msg);
    void handleMessageGameRunning(Message* msg);

    void startBattle();
    Monster* createMonster(pokemonData &pokemon);
    void printMonsterInfo(Monster* m);

private:

    pokemonData bulbasaur{"Bulbasaur", "grass", "images/001.png", "images/001b.png"};
    pokemonData charmander{"Charmander", "fire", "images/004.png", "images/004b.png"};
    pokemonData squirtle{"Squirtle", "water", "images/007.png", "images/007b.png"};
    pokemonData meowth{"Meowth", "normal", "images/052.png", "images/052b.png"};
    pokemonData magnemite{"Magnemite", "steel", "images/081.png", "images/081b.png"};

    bool gameRunning = false;
    bool inBattle = false;
    Monster* playerMonster;
    // Monster* wildMonster;
};