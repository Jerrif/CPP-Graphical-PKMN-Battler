#include "monster.hpp"

// #include <string>
// #include <iostream>

Monster::Monster(int hp, std::string name) {
    Monster::health = hp;
    Monster::monsterName = name;
}

Monster::Monster(int hp) {
    Monster::health = hp;
}

int Monster::getHealth()
{
    return Monster::health;
}

void Monster::setHealth(int newHealth)
{
    Monster::health = newHealth;
}