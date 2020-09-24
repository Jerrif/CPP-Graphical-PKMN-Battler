#include "Monster.hpp"
#include "CharacterData.hpp"

#include <iostream>
#include <string>

/* constructors */
Monster::Monster(int hp, pokemonData& pokemon) {
    // std::cout << "Monster constructor" << std::endl;
    printf("Constructor:\tMonster: %s\n", mMonsterName.c_str());
    Monster::mHealth = hp;
    Monster::mMonsterName = pokemon.name;
    Monster::mMonsterType = pokemon.type;
}
/* end constructors */

Monster::~Monster() {
    // std::cout << mMonsterName << "'s Monster destructor called" << std::endl;
    printf("Destructor:\tMonster: %s\n", mMonsterName.c_str());
}

int Monster::getHealth() {
    return Monster::mHealth;
}

void Monster::setHealth(int newHealth) {
    Monster::mHealth = newHealth;
}

std::string Monster::getName() {
    return Monster::mMonsterName;
}

std::string Monster::getType() {
    return Monster::mMonsterType;
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

/* ==================================== PlayerMonster ==================================== */

PlayerMonster::PlayerMonster(int hp, pokemonData& pokemon): Monster(hp, pokemon) {
    std::cout << "PlayerMonster constructor" << std::endl;
}

void PlayerMonster::printInfo() {
    printf("Name: %s, Health: %i\n", getName().c_str(), getHealth());
    printf("Type: %s\n", mMonsterType.c_str());
}

/* ===================================== WildMonster ===================================== */

WildMonster::WildMonster(int hp, pokemonData& pokemon): Monster(hp, pokemon) {
    std::cout << "WildMonster constructor" << std::endl;
}

void WildMonster::printInfo() {
    printf("Name: %s, Health: %i\n", getName().c_str(), getHealth());
    printf("Type: %s\n", mMonsterType.c_str());
}