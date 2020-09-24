#include "Monster.hpp"
#include "CharacterData.hpp"

#include <iostream>
#include <string>

/* constructors */
Monster::Monster(int hp, pokemonData& pokemon) {
    printf("Constructor:\tMonster\n");
    Monster::mHealth = hp;
    Monster::mMonsterName = pokemon.name;
    Monster::mMonsterType = pokemon.type;
}
/* end constructors */

Monster::~Monster() {
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

void Monster::printInfo() {
    printf("%s, %s, %i\n", mMonsterName.c_str(), mMonsterType.c_str(), mHealth);
}

int Monster::takeDamage(int damageAmount) {
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
    std::cout << "Constructor:\tPlayerMonster" << std::endl;
}

/* ===================================== WildMonster ===================================== */

WildMonster::WildMonster(int hp, pokemonData& pokemon): Monster(hp, pokemon) {
    std::cout << "Constructor:\tWildMonster" << std::endl;
}
