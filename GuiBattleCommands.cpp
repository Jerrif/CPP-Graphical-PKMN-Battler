#include "GuiBattleCommands.hpp"

#include <iostream>

GuiBattleCommands::GuiBattleCommands() {
    printf("Constructor:\tGuiBattleCommands\n");
    systemName = "GuiBattleCommands";
    printf("Loading buttons?\n");
    addButton("Fight!", Message::BATTLE_MENU_FIGHT, 0, 0);
    addButton("Bag!", Message::BATTLE_MENU_BAG, 1, 0);
    addButton("Pkmn!", Message::BATTLE_MENU_PKMN, 0, 1);
    addButton("Run!", Message::BATTLE_MENU_RUN, 1, 1);
}

GuiBattleCommands::~GuiBattleCommands() {
    printf("Destructor:\tGuiBattleCommands\n");
}

// Must add button in order of their appearance, the first button defaults to selected
// Adds buttons left to right, top to bottom
void GuiBattleCommands::addButton(std::string buttonText, Message::types msg, int xPos, int yPos) {
    // Maybe I should assert(totalButtons <= MAX_BUTTONS)?
    if(buttons[xPos][yPos] != NULL) {
        printf("BATTLE MENU BUTTON ERROR! DOUBLE ASSIGNING BUTTON TO SLOT: %i, %i\n", xPos, yPos);
    }
    buttons[xPos][yPos] = new Button{buttonText, msg, !(totalButtonsX && totalButtonsY)};
    if(yPos == 0) {
        totalButtonsX++;
    } else {
        totalButtonsY++;
    }
}

void GuiBattleCommands::selectNextButton(directions direction) {
    buttons[currentSelectedX][currentSelectedY]->setUnselected();

    switch (direction) {
        case UP:
            if(currentSelectedY == 0) {
                currentSelectedY = totalButtonsY - 1;
            } else {
                currentSelectedY--;
            }
        break;

        case DOWN:
            if(currentSelectedY == totalButtonsY - 1) {
                currentSelectedY = 0;
            } else {
                currentSelectedY++;
            }
        break;
    
        case LEFT:
            if(currentSelectedX == 0) {
                currentSelectedX = totalButtonsX - 1;
            } else {
                currentSelectedX--;
            }
        break;

        case RIGHT:
            if(currentSelectedX == totalButtonsX - 1) {
                currentSelectedX = 0;
            } else {
                currentSelectedX++;
            }
        break;

        default:
        break;
    }

    buttons[currentSelectedX][currentSelectedY]->setSelected();
    postMessage(Message::PLAY_SOUND);
}


void GuiBattleCommands::confirmSelection() {
    printf("Confirmed button selection: %s\n", buttons[currentSelectedX][currentSelectedY]->getButtonText().c_str());
    // myMsg->type = Message::GAME_START;
    myMsg.type = buttons[currentSelectedX][currentSelectedY]->getButtonMessage();
}

void GuiBattleCommands::handleMessage(Message& msg) {
    if(!battleMenuOpen) {
        switch(msg.type) {
            case Message::BATTLE_MENU_OPEN:
            battleMenuOpen = true;
            break;

            default:
            break;
        }
        return;
    }
    switch(msg.type) {
        case Message::GUI_UP_PRESSED:
        // printf("\nGuiBattleCommands:\tGui up\n");
        direction = UP;
        selectNextButton(direction);
        printf("Selected button: %s\n", buttons[currentSelectedX][currentSelectedY]->getButtonText().c_str());
        break;

        case Message::GUI_DOWN_PRESSED:
        // printf("\nGuiBattleCommands:\tGui down\n");
        direction = DOWN;
        selectNextButton(direction);
        printf("Selected button: %s\n", buttons[currentSelectedX][currentSelectedY]->getButtonText().c_str());
        break;

        case Message::GUI_LEFT_PRESSED:
        // printf("\nGuiBattleCommands:\tGui left\n");
        direction = LEFT;
        selectNextButton(direction);
        printf("Selected button: %s\n", buttons[currentSelectedX][currentSelectedY]->getButtonText().c_str());
        break;

        case Message::GUI_RIGHT_PRESSED:
        // printf("\nGuiBattleCommands:\tGui right\n");
        direction = RIGHT;
        selectNextButton(direction);
        printf("Selected button: %s\n", buttons[currentSelectedX][currentSelectedY]->getButtonText().c_str());
        break;

        case Message::GUI_ENTER_PRESSED:
        // printf("\nGuiBattleCommands:\tGui confirm selection\n");
        confirmSelection();
        postMessage(myMsg.type);
        break;

        // case Message::BATTLE_MENU_FIGHT:
        // // printf("\nGuiBattleCommands:\tFight\n");
        // break;

        // case Message::BATTLE_MENU_BAG:
        // // printf("GuiBattleCommands:\tBag\n");
        // break;

        // case Message::BATTLE_MENU_PKMN:
        // // printf("GuiBattleCommands:\tPKMN\n");
        // break;

        // case Message::BATTLE_MENU_RUN:
        // // printf("GuiBattleCommands:\tRun\n");
        // break;

        case Message::BATTLE_MENU_CLOSE:
        // printf("GuiBattleCommands:\tBattle menu closed\n");
        battleMenuOpen = false;
        break;

        default:
        break;
    }
}