#pragma once

#include "CharacterData.hpp"
#include "LTexture.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Monster {
public:
    // constructors
    Monster(SDL_Renderer* renderer, int hp, pokemonData& pokemon);
    // Monster(int hp, pokemonData& pokemon);

    ~Monster();

    int getHealth();
    void setHealth(int newHealth);
    std::string getName();
    int takeDamage(int damageAmount);

protected:
    SDL_Renderer* mRenderer;

    int mHealth;
    std::string mMonsterName; // TODO: make this const somehow?
    std::string mMonsterType;
    std::string mFrontSprite;
    std::string mBackSprite;

};

/* ======================================================================================= */
/* ==================================== PlayerMonster ==================================== */
/* ======================================================================================= */

class PlayerMonster : public Monster {
public:
    // PlayerMonster(SDL_Renderer* ren, int hp, pokemonData& pokemon);
    // PlayerMonster(LTexture& pokemonTexture, int hp, pokemonData& pokemon);
    PlayerMonster(SDL_Renderer* renderer, int hp, pokemonData& pokemon);
    // void loadSprite(SDL_Renderer* renderer, pokemonData& pokemon);
    // void loadSprite(SDL_Renderer* renderer);
    void loadSprite();
    // void loadSprite(pokemonData& pokemon);
    void render(int x, int y);

    void printInfo();

private:
    // SDL_Renderer* mRen;
    // std::string mBattleSprite;
    // LTexture mBattleSprite(SDL_Renderer* mRenderer);
    LTexture mBattleSprite;
};

/* ======================================================================================= */
/* ===================================== WildMonster ===================================== */
/* ======================================================================================= */

// class WildMonster : public Monster {
// public:
//     WildMonster(SDL_Renderer* renderer, int hp, pokemonData& pokemon);
//     // void loadSprite(SDL_Renderer* renderer, pokemonData& pokemon);
//     void loadSprite(pokemonData& pokemon);
//     void render(int x, int y);

// private:
//     SDL_Renderer* mRenderer;
//     // std::string mBattleSprite;
//     LTexture mBattleSprite;
// };