// graphics includes
#include "LWindow.hpp"
#include "LTexture.hpp" // maybe don't need here?

// logic includes
#include "Message.hpp"
#include "MessageBus.hpp"
#include "System.hpp"
#include "MessageConsole.hpp"
#include "InputSystem.hpp"
#include "AudioSystem.hpp"
#include "GuiSystem.hpp"
#include "GuiMainMenu.hpp"
#include "GuiBattleCommands.hpp"
#include "GameLogicSystem.hpp"
#include "BattleSystem.hpp"

// data includes
#include "CharacterData.hpp"

// SDL / framework includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

// standard library includes
#include <iostream>
#include <vector>
#include <string>

//TODO: REMEMBER RAII!

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

bool init();

int main(int arg, char *argv[]) {

    LWindow gameWindow{SCREEN_WIDTH, SCREEN_HEIGHT};

    MessageBus* msgBus = new MessageBus{};

    MessageConsole messageConsole{};
    InputSystem inputSystem{};
    AudioSystem audioSystem{};
    GuiMainMenu guiMainMenu{};
    // GuiBattleCommands guiBattleCommands{};
    GameLogicSystem gameLogicSystem{};
    // BattleSystem battleSystem{};

    msgBus->MessageBus::attachToSystem(messageConsole);
    msgBus->MessageBus::attachToSystem(inputSystem);
    msgBus->MessageBus::attachToSystem(audioSystem);
    msgBus->MessageBus::attachToSystem(guiMainMenu);
    msgBus->MessageBus::attachToSystem(gameLogicSystem);

    // msgBus->MessageBus::attachToSystem(guiBattleCommands);
    // msgBus->MessageBus::attachToSystem(battleSystem);

    if( !init() ) {
        printf("Yo can't init SDL stuff\n");
        return EXIT_FAILURE;
    }

    if( !gameWindow.init() ) {
        printf("Yo some ting wong\n");
        return EXIT_FAILURE;
    }

    const auto renderer = gameWindow.getRenderer();
    std::cout << "Renderer: " << &renderer << "\n" << std::endl;

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
            inputSystem.handleInput(e);
        }
        msgBus->sendMessages();
        // gameLogicSystem.update();

        gameWindow.clearScreen();
        gameWindow.render();
    }

    return EXIT_SUCCESS;
}

bool init() {
    // init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return false;
    }
    //Set texture filtering to linear
    // if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0")) { // this isn't actually linear texture filtering I think
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