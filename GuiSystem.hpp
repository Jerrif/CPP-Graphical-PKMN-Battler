#pragma once

#include "System.hpp"
#include "Button.hpp"

class GuiSystem : public System {
public:
    GuiSystem();
    ~GuiSystem();

    void handleMessage(Message* msg);

private:
    // enum battleSelections {
    //     TOP_LEFT,
    //     TOP_RIGHT,
    //     BOTTOM_LEFT,
    //     BOTTOM_RIGHT
    // };
    // battleSelections currentSelection = TOP_LEFT;

    // enum mainMenuSelections {

    // };
    // static const int MAX_BUTTONS = 20;
    // Button* buttons[MAX_BUTTONS];

};