#pragma once

#include "Monster.hpp"

#include <iostream>
#include <string>

void doBattle(Monster player, Monster enemy);
bool battleOver(Monster player, Monster enemy);
bool escapeFromBattle(Monster mon); // TODO: implement this