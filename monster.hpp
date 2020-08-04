#pragma once

#include <string>

class Monster {
public:
    // constructors
    Monster(int, std::string);
    Monster(int);
    Monster();

    ~Monster();

    int getHealth();
    void setHealth(int newHealth);
    std::string getName();
    int takeDamage(int damageAmount);
private:
    int health;
    std::string monsterName; // TODO: make this const somehow?
};