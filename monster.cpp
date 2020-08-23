#include "Monster.hpp"
#include "CharacterData.hpp"
#include "LTexture.hpp"

#include <iostream>
#include <string>

/* constructors */
Monster::Monster(int hp, pokemonData& pokemon) {
// Monster::Monster(SDL_Renderer* renderer, int hp, pokemonData& pokemon) {
// Monster::Monster(LTexture pokemonTexture, int hp, pokemonData& pokemon) {
    std::cout << "Monster constructor" << std::endl;
    Monster::mHealth = hp;
    Monster::mMonsterName = pokemon.name;
    Monster::mMonsterType = pokemon.type;
    Monster::mFrontSprite = pokemon.battleFrontPath;
    Monster::mBackSprite = pokemon.battleBackPath;
    // Monster::mRenderer = renderer;
}
/* end constructors */

Monster::~Monster() {
    std::cout << mMonsterName << "'s Monster destructor called" << std::endl;
}

int Monster::getHealth() {
    return Monster::mHealth;
}

void Monster::setHealth(int newHealth) {
    Monster::mHealth = newHealth;
}

std::string Monster::getName(){
    return Monster::mMonsterName;
}

int Monster::takeDamage(int damageAmount) {
    // std::cout << "Taking " << damageAmount << " damage!" << std::endl;

    if (mHealth < damageAmount) {
        auto lastHealth = mHealth;
        mHealth = 0;
        return lastHealth;
    }

    mHealth -= damageAmount;

    return damageAmount;
}

/* ======================================================================================= */
/* ==================================== PlayerMonster ==================================== */
/* ======================================================================================= */

// PlayerMonster::PlayerMonster(SDL_Renderer* ren, int hp, pokemonData& pokemon): Monster(ren, hp, pokemon) {
// PlayerMonster::PlayerMonster(LTexture& pokemonTexture, int hp, pokemonData& pokemon): Monster(hp, pokemon) {
PlayerMonster::PlayerMonster(int hp, pokemonData& pokemon): Monster(hp, pokemon) {
    std::cout << "PlayerMonster constructor" << std::endl;
    // PlayerMonster::mRen = ren;
    // PlayerMonster::mBattleSprite(mRenderer);
    // PlayerMonster::mBattleSprite();
    // PlayerMonster::mBattleSprite = pokemonTexture;

}

// void PlayerMonster::loadSprite(SDL_Renderer* renderer, pokemonData& pokemon) {
// void PlayerMonster::loadSprite(pokemonData& pokemon) {
//     // mBattleSprite = pokemon.battleBackPath;
//         printf("Attempting to load PlayerMonster battle sprite\n");
//         mBattleSprite().loadFromFile(pokemon.battleBackPath);
//     // if (!PlayerMonster::mBattleSprite.loadFromFile(pokemon.battleBackPath)) {
//         // printf("Error loading sprite in class PlayerMonster\n");
//     // }
// }

// void render(int x, int y) {
//     printf("Attempting to render PlayerMonster sprite\n");
//     mBattleSprite.render(x, y);
// }

void PlayerMonster::printInfo() {
    printf("Name: %s, Health: %i\n", getName().c_str(), getHealth());
    printf("Type: %s\n", mMonsterType.c_str());
    // printf("Renderer: %p\n\n", mRenderer);
}

/* ======================================================================================= */
/* ===================================== WildMonster ===================================== */
/* ======================================================================================= */

// WildMonster::WildMonster(SDL_Renderer* renderer, int hp, pokemonData& pokemon): Monster(renderer, hp, pokemon) {
//     std::cout << "WildMonster constructor" << std::endl;
//     mBattleSprite(mRenderer);
// }

// // void WildMonster::loadSprite(SDL_Renderer* renderer, pokemonData& pokemon) {
// void WildMonster::loadSprite(pokemonData& pokemon) {
//     // mBattleSprite = pokemon.battleBackPath;
//         printf("Attempting to load WildMonster battle sprite\n");
//     if (!mBattleSprite.loadFromFile(pokemon.battleBackPath)) {
//         printf("Error loading sprite in class WildMonster\n");
//     }
// }

// void WildMonster::render(int x, int y) {
//     printf("Attempting to render WildMonster sprite\n");
//     mBattleSprite.render(x, y);
// }