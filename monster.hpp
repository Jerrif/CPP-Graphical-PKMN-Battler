#include <string>

class Monster {
public:
    std::string monsterName = "DEFAULT NAME"; // TODO: make this const?

    Monster(int, std::string); // constructor
    Monster(int); // constructor
    Monster() = default; // constructor

    // int getHealth() { return health; };
    int getHealth();
    void setHealth(int newHealth);
private:
    int health = 100;
};