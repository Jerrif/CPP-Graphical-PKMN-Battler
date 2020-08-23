// graphics includes
#include "LWindow.hpp"
#include "LTexture.hpp" // maybe don't need here?

// logic includes
#include "Monster.hpp"
#include "RNG.hpp"
#include "Battle.hpp"

#include "CharacterData.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <vector>
#include <string>

//TODO: REMEMBER RAII!

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

pokemonData bulbasaur{"Bulbasaur", "grass", "images/001.png", "images/001b.png"};
pokemonData charmander{"Charmander", "fire", "images/004.png", "images/004b.png"};
pokemonData squirtle{"Squirtle", "water", "images/007.png", "images/007b.png"};

bool init();


int main(int arg, char *argv[]) {

    // printf("%s: %s\n", bulbasaur.name.c_str(), bulbasaur.type.c_str());

    LWindow gameWindow(SCREEN_WIDTH, SCREEN_HEIGHT);

    initRNG();

    if( !init() ) {
        printf("Yo can't init SDL stuff");
        return EXIT_FAILURE;
    }

    if( !gameWindow.init() ) {
        printf("Yo some ting wong\n");
        return EXIT_FAILURE;
    }

    // const auto renderer = gameWindow.getRenderer();
    SDL_Renderer* renderer = gameWindow.getRenderer();

    printf("Renderer: %p\n\n", renderer);

    // PlayerMonster JMon(renderer, 15, squirtle);
    PlayerMonster JMon(15, squirtle);
    printf("R: %p\n\n", renderer);
    PlayerMonster MattMon(10, charmander);
    printf("R: %p\n\n", renderer);
    PlayerMonster dickMon(22, bulbasaur);
    printf("R: %p\n\n", renderer);
    JMon.printInfo();
    MattMon.printInfo();
    dickMon.printInfo();

    // JMon.loadSprite(squirtle);
    // MattMon.loadSprite(charmander);

    // printf("%s, %s\n%s, %s\n", JMon.getName().c_str(), JMon.mBattleSprite.c_str(), MattMon.getName().c_str(), MattMon.mBattleSprite.c_str());

    SDL_Event e;
    bool quit = false;

    // main game loop?
    while (!quit)
    {
        // handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            // user requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
        gameWindow.render();
    }


    // doBattle(JMon, MattMon);
    // doBattle(JMon, GraceMon);
    // doBattle(JMon, dood);

    return EXIT_SUCCESS;
}

bool init() {
    // init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return false;
    }
    //Set texture filtering to linear
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        printf("Warning: Linear texture filtering not enabled!");
    }
    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }

    //Initialize SDL_ttf
    if (TTF_Init() == -1)
    {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return false;
    }

    return true;
}