#pragma once

#include "GuiSystem.hpp"

class GuiBattleCommands : public GuiSystem {
public:
    GuiBattleCommands();
    ~GuiBattleCommands();

    void handleMessage(Message* msg);

private:
    enum directions {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    void addButton(std::string buttonText, Message::types msg, int xPos, int yPos);
    void selectNextButton(directions direction);
    void confirmSelection();

    bool battleMenuOpen = false;
    static const int MAX_BUTTONS = 2;
    int totalButtonsX = 0;
    int totalButtonsY = 0;
    int currentSelectedX = 0; // 0 based
    int currentSelectedY = 0; // 0 based
    directions direction = RIGHT;
    Button* buttons[MAX_BUTTONS][MAX_BUTTONS] = {};
};