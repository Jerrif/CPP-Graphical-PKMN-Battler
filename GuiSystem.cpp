#include "GuiSystem.hpp"
// #include "Message.hpp"
#include <iostream>

GuiSystem::GuiSystem() {
    printf("Constructor:\tGuiSystem\n");
}

GuiSystem::~GuiSystem() {
    printf("Destructor:\tGuiSystem\n");
}

void GuiSystem::handleMessage(Message& msg) {
    switch(msg.type) {
        // case Message::GUI_LEFT_PRESSED:
        // printf("Gui system move selection left\n");
        // postMessage(Message::PLAY_SOUND);
        // break;

        // case Message::GUI_RIGHT_PRESSED:
        // printf("Gui system move selection right\n");
        // postMessage(Message::PLAY_SOUND);
        // break;

        // case Message::GUI_UP_PRESSED:
        // printf("Gui system move selection up\n");
        // postMessage(Message::PLAY_SOUND);
        // break;

        // case Message::GUI_DOWN_PRESSED:
        // printf("Gui system move selection down\n");
        // postMessage(Message::PLAY_SOUND);
        // break;

        // case Message::GUI_ENTER_PRESSED:
        // printf("Gui system confirm selection\n");
        // postMessage(Message::PLAY_SOUND);
        // break;

        default:
        break;
    }
}