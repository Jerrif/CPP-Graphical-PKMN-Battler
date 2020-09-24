#pragma once

#include "GuiSystem.hpp"

class GuiMainMenu : public GuiSystem {
public:
    GuiMainMenu();
    ~GuiMainMenu();

    void handleMessage(Message* msg);

private:

    void addButton(std::string buttonText, Message::types msg);
    void selectNextButton();
    void selectPreviousButton();
    void confirmSelection();

    bool mainMenuOpen = true;
    static const int MAX_BUTTONS = 12;
    int totalButtons = 0;
    int currentSelected = 0; // 0 based
    Button* buttons[MAX_BUTTONS] = {};
};