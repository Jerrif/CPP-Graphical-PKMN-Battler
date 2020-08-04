#include "monster.hpp"

#include <iostream>
#include <string>

/* constructors */
Monster::Monster(int hp, std::string name) {
    Monster::health = hp;
    Monster::monsterName = name;
}

Monster::Monster(int hp) {
    Monster::health = hp;
    Monster::monsterName = "DEFAULT NAME 456";
}

Monster::Monster() {
    Monster::health = 100;
    Monster::monsterName = "DEFAULT NAME 123";
}
/* end constructors */

Monster::~Monster() {
    std::cout << monsterName << "'s Monster destructor called" << std::endl;
}

int Monster::getHealth() {
    return Monster::health;
}

void Monster::setHealth(int newHealth) {
    Monster::health = newHealth;
}

std::string Monster::getName(){
    return Monster::monsterName;
}

int Monster::takeDamage(int damageAmount) {
    // std::cout << "Taking " << damageAmount << " damage!" << std::endl;

    if (health < damageAmount) {
        auto lastHealth = health;
        health = 0;
        return lastHealth;
    }

    health -= damageAmount;

    return damageAmount;
}