#pragma once

#include <string>

class Message {
public:
    Message();
    ~Message();

    enum types {
        // GUI messages
        GUI_OPEN,
        GUI_CLOSE,
        GUI_LEFT_PRESSED,
        GUI_RIGHT_PRESSED,
        GUI_UP_PRESSED,
        GUI_DOWN_PRESSED,
        GUI_ENTER_PRESSED,
        GUI_OPTIONS_OPEN,
        GUI_OPTIONS_CLOSE,

        // Main menu GUI messages
        GUI_MAIN_MENU_OPEN,
        GUI_MAIN_MENU_CLOSE,

        // Battle GUI messages
        BATTLE_MENU_OPEN,
        BATTLE_MENU_CLOSE,
        BATTLE_MENU_FIGHT,
        BATTLE_MENU_BAG,
        BATTLE_MENU_PKMN,
        BATTLE_MENU_RUN,

        // Movement messages
        PLAYER_MOVE_LEFT,
        PLAYER_MOVE_RIGHT,
        PLAYER_MOVE_UP,
        PLAYER_MOVE_DOWN,

        // Sound messages
        PLAY_SOUND,

        // Generic messages
        GAME_START,
        USER_QUIT,
        BATTLE_START,
        BATTLE_END,
        HELLO_WORLD,
        NULL_MSG,
        END
    };

    types type;
};