#include "InputSystem.hpp"
// #include "Message.hpp"
#include <iostream>

InputSystem::InputSystem() {
    printf("Constructor:\tInputSystem\n");
    systemName = "InputSystem";
}

InputSystem::~InputSystem() {
    printf("Destructor:\tInputSystem\n");
}

void InputSystem::handleInput(SDL_Event &e) {
    if (e.type == SDL_KEYDOWN) {
        if(guiOpen) {
            handleGuiOpen(e);
        } else {
            handleGuiClosed(e);
        }
    }
}

void InputSystem::handleGuiOpen(SDL_Event &e) {
    switch(e.key.keysym.sym) {
        case SDLK_LEFT:
        // printf("Input:\t\tLeft pressed\n");
        postMessage(Message::GUI_LEFT_PRESSED);
        break;

        case SDLK_RIGHT:
        // printf("Input:\t\tRight pressed\n");
        postMessage(Message::GUI_RIGHT_PRESSED);
        break;

        case SDLK_UP:
        // printf("Input:\t\tUp pressed\n");
        postMessage(Message::GUI_UP_PRESSED);
        break;

        case SDLK_DOWN:
        // printf("Input:\t\tDown pressed\n");
        postMessage(Message::GUI_DOWN_PRESSED);
        break;

        case SDLK_RETURN:
        // printf("Input:\t\tEnter pressed\n");
        postMessage(Message::GUI_ENTER_PRESSED);
        break;

        // case SDLK_i:
        // printf("Input:\t\tClosing inventory\n");
        // guiOpen = false;
        // postMessage(Message::GUI_CLOSE);
        // break;

        case SDLK_a:
        postMessage(Message::PLAY_SOUND);
        break;

    }
}

void InputSystem::handleGuiClosed(SDL_Event &e) {
    switch(e.key.keysym.sym) {
        case SDLK_LEFT:
        // printf("Input:\t\tLeft pressed\n");
        postMessage(Message::PLAYER_MOVE_LEFT);
        break;

        case SDLK_RIGHT:
        // printf("Input:\t\tRight pressed\n");
        postMessage(Message::PLAYER_MOVE_RIGHT);
        break;

        case SDLK_UP:
        // printf("Input:\t\tUp pressed\n");
        postMessage(Message::PLAYER_MOVE_UP);
        break;

        case SDLK_DOWN:
        // printf("Input:\t\tDown pressed\n");
        postMessage(Message::PLAYER_MOVE_DOWN);
        break;
        
        // case SDLK_i:
        // printf("Input:\t\tOpening inventory\n");
        // guiOpen = true;
        // postMessage(Message::GUI_OPEN);
        // break;

        case SDLK_a:
        postMessage(Message::PLAY_SOUND);
        break;

        case SDLK_b:
        postMessage(Message::BATTLE_START);
        break;
    }

}

void InputSystem::handleMessage(Message& msg) {
    switch(msg.type) {
        case Message::GUI_CLOSE:
        // printf("Gui closed\n");
        guiOpen = false;
        break;

        case Message::GUI_OPEN:
        // printf("Gui opened\n");
        guiOpen = true;
        break;

        case Message::GUI_MAIN_MENU_OPEN:
        // printf("Main menu opened\n");
        guiOpen = true;
        break;

        case Message::GUI_MAIN_MENU_CLOSE:
        // printf("Main menu closed\n");
        guiOpen = false;
        break;

        case Message::BATTLE_MENU_OPEN:
        // printf("Battle menu opened\n");
        guiOpen = true;
        break;

        case Message::BATTLE_MENU_CLOSE:
        // printf("Battle menu closed\n");
        guiOpen = false;
        break;

        default:
        break;

    }
}