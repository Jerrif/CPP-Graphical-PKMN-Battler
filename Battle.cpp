// #include "Battle.hpp"
// #include "Monster.hpp"
// #include "RNG.hpp"

// #include <iostream>
// #include <string>

// static bool isPlayerTurn = true;
// // static bool selected = false;

// // just a test for now
// void playBattle(Monster& player, Monster& enemy) {
//     if (!battleOver(player, enemy)) {
//         if (isPlayerTurn) {
//             handlePlayerTurn(player, enemy);
//         } else {
//             handleEnemyTurn(player, enemy);
//         }
//     } else {
//         std::cout << "\nBATTLE OVER!" << std::endl;
//     }
// }

// bool battleOver(Monster& player, Monster& enemy) { 
//     if (player.getHealth() <= 0 || enemy.getHealth() <= 0)
//         return true;

//     return false;
    
//     // return escapeFromBattle();
// }

// void handlePlayerTurn(Monster& player, Monster& enemy) {

//     // TODO: change battle menu selection in the battle GUI

//     // if (selected && sceneHandler.selectedOption == 1) {
//     // TODO: this will be something like: if(MSG == PLAYER_ATTACK) {
//         std::cout << "\nPLAYER TURN" << std::endl;
//         std::cout << "-----------------\nHealth: " << player.getHealth() << ", Enemy health: " << enemy.getHealth() << std::endl;
//         std::cout << "You attack! Enemy takes " << enemy.takeDamage(getRandomInt(1, 4)) << " damage" << std::endl;
//         isPlayerTurn = false;
//     // }
//     // else {
//     //     selected = false;
//     // }
// }

// void handleEnemyTurn(Monster& player, Monster& enemy) {
//     std::cout << "\nENEMY TURN" << std::endl;
//     isPlayerTurn = true;
//     std::cout << "Enemy attacks! You take " << player.takeDamage(getRandomInt(1, 2)) << " damage" << std::endl;
// }