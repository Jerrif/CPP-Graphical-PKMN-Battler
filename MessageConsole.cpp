#include "MessageConsole.hpp"
#include <iostream>

MessageConsole::MessageConsole() {
    printf("Constructor:\tMessageConsole\n");
    systemName = "MessageConsole";
}

MessageConsole::~MessageConsole() {
    printf("Destructor:\tMessageConsole\n");
}

void MessageConsole::handleMessage(Message& msg) {
    switch(msg.type) {
        case Message::GUI_OPEN:
        printf("Console:\tGUI_OPEN\n");
        break;

        case Message::GUI_CLOSE:
        printf("Console:\tGUI_CLOSE\n");
        break;

        case Message::GUI_LEFT_PRESSED:
        printf("Console:\tGUI_LEFT_PRESSED\n");
        break;

        case Message::GUI_RIGHT_PRESSED:
        printf("Console:\tGUI_RIGHT_PRESSED\n");
        break;

        case Message::GUI_UP_PRESSED:
        printf("Console:\tGUI_UP_PRESSED\n");
        break;

        case Message::GUI_DOWN_PRESSED:
        printf("Console:\tGUI_DOWN_PRESSED\n");
        break;

        case Message::GUI_ENTER_PRESSED:
        printf("Console:\tGUI_ENTER_PRESSED\n");
        break;

        case Message::GUI_OPTIONS_OPEN:
        printf("Console:\tGUI_OPTIONS_OPEN\n");
        break;

        case Message::GUI_OPTIONS_CLOSE:
        printf("Console:\tGUI_OPTIONS_CLOSE\n");
        break;


        // Main menu GUI messages
        case Message::GUI_MAIN_MENU_OPEN:
        printf("Console:\tGUI_MAIN_MENU_OPEN\n");
        break;

        case Message::GUI_MAIN_MENU_CLOSE:
        printf("Console:\tGUI_MAIN_MENU_CLOSE\n");
        break;


        // Battle GUI messages
        case Message::BATTLE_MENU_OPEN:
        printf("Console:\tBATTLE_MENU_OPEN\n");
        break;

        case Message::BATTLE_MENU_CLOSE:
        printf("Console:\tBATTLE_MENU_CLOSE\n");
        break;

        case Message::BATTLE_MENU_FIGHT:
        printf("Console:\tBATTLE_MENU_FIGHT\n");
        break;

        case Message::BATTLE_MENU_BAG:
        printf("Console:\tBATTLE_MENU_BAG\n");
        break;

        case Message::BATTLE_MENU_PKMN:
        printf("Console:\tBATTLE_MENU_PKMN\n");
        break;

        case Message::BATTLE_MENU_RUN:
        printf("Console:\tBATTLE_MENU_RUN\n");
        break;


        // Movement messages
        case Message::PLAYER_MOVE_LEFT:
        printf("Console:\tPLAYER_MOVE_LEFT\n");
        break;

        case Message::PLAYER_MOVE_RIGHT:
        printf("Console:\tPLAYER_MOVE_RIGHT\n");
        break;

        case Message::PLAYER_MOVE_UP:
        printf("Console:\tPLAYER_MOVE_UP\n");
        break;

        case Message::PLAYER_MOVE_DOWN:
        printf("Console:\tPLAYER_MOVE_DOWN\n");
        break;


        // Sound messages
        case Message::PLAY_SOUND:
        printf("Console:\tPLAY_SOUND\n");
        break;


        // Generic messages
        case Message::GAME_START:
        printf("Console:\tGAME_START\n");
        break;

        case Message::USER_QUIT:
        printf("Console:\tUSER_QUIT\n");
        break;

        case Message::BATTLE_START:
        printf("Console:\tBATTLE_START\n");
        break;

        case Message::BATTLE_END:
        printf("Console:\tBATTLE_END\n");
        break;

        case Message::HELLO_WORLD:
        printf("Console:\tHELLO_WORLD\n");
        break;

        case Message::NULL_MSG:
        printf("Console:\tNULL_MSG\n");
        break;

        case Message::END:
        printf("Console:\tEND\n");
        break;

        // no default is intentional; a compiler error will alert you of any missed messages
        // default:
        // break;
    }
}