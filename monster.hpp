#pragma once

#include "CharacterData.hpp"

class Monster {
public:
    // constructors
    Monster(int hp, pokemonData& pokemon);

    ~Monster();

    int getHealth();
    std::string getType();
    std::string getName();
    void printInfo();
    void setHealth(int newHealth);
    int takeDamage(int damageAmount);

protected:
    int mHealth;
    std::string mMonsterName; // TODO: make this const somehow?
    std::string mMonsterType;
};


/* ==================================== PlayerMonster ==================================== */

class PlayerMonster : public Monster {
public:
    PlayerMonster(int hp, pokemonData& pokemon);

    void printInfo();

private:
};

/* ===================================== WildMonster ===================================== */

class WildMonster : public Monster {
public:
    WildMonster(int hp, pokemonData& pokemon);

    void printInfo();

private:
};