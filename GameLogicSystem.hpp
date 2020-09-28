#pragma once

#include "System.hpp"
#include "CharacterData.hpp"

// TEXTURE TESTING
#include "LTexture.hpp"

#include <SDL2/SDL.h>

class Monster;
class BattleSystem;

class GameLogicSystem : public System {
public:
    GameLogicSystem();
    ~GameLogicSystem();

    void handleMessage(Message& msg);
    void handleMessageGamePaused(Message& msg);
    void handleMessageGameRunning(Message& msg);

    Monster* createPlayerMonster(pokemonData &pokemon);
    Monster* createWildMonster(pokemonData &pokemon);
    BattleSystem* createBattle(Monster& playerMonster, Monster& wildMonster);
    void startBattle(); // necessary?
    void endBattle(System* battle);

    void update();

    // TEXTURE TESTING

private:

    // TEXTURE TESTING
    // SDL_Renderer* r;
    LTexture* tex;
    int x=150;
    int y=150;

    void destroyPlayerMonster();
    void destroyWildMonster();

    void printMonsterInfo(Monster* m);

    void attachToMessageBus(System* s);
    void detachFromMessageBus(System* s);

    bool gameRunning = false;
    bool inBattle = false;
    Monster* playerMonster;
    Monster* wildMonster;
    BattleSystem* activeBattle {};

    pokemonData bulbasaur{"Bulbasaur", "grass", "images/001.png", "images/001b.png"};
    pokemonData charmander{"Charmander", "fire", "images/004.png", "images/004b.png"};
    pokemonData squirtle{"Squirtle", "water", "images/007.png", "images/007b.png"};
    pokemonData meowth{"Meowth", "normal", "images/052.png", "images/052b.png"};
    pokemonData magnemite{"Magnemite", "steel", "images/081.png", "images/081b.png"};

};