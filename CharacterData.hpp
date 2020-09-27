#pragma once

#include <string>

/* NOTE: this should definitely be data, rather than code.
it should be read in through a text file, probably in JSON */

struct pokemonData {
    std::string name;
    std::string type; // should this be an enum maybe? or its own typedef
    std::string battleFrontPath;
    std::string battleBackPath;
};