#pragma once

#include <string>

struct pokemonData {
    std::string name;
    std::string type; // should this be an enum maybe? or its own typedef
    std::string battleFrontPath;
    std::string battleBackPath;
};