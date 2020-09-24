#pragma once

#include "System.hpp"

class InputSystem : public System {
public:
    InputSystem();
    ~InputSystem();

    void handleInput(SDL_Event &e);
    void handleGuiOpen(SDL_Event &e);
    void handleGuiClosed(SDL_Event &e);

    void handleMessage(Message& msg);

private:
    bool guiOpen = true;
    // Message* myMsg = new Message{};
};