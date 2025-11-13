#pragma once

#include "GuiSystem.hpp"

class GuiMainMenu : public GuiSystem {
public:
    GuiMainMenu();
    ~GuiMainMenu();

    void handleMessage(Message& msg);

    void update();

private:

    void addButton(std::string buttonText, Message::types msg);
    // void addButton(std::string buttonText, Message::types msg, std::string selectedTexture, std::string unselectedTexture);
    // void loadButtonTextures(std::string selectedTexture, std::string unselectedTexture);
    void loadButtonTextures();
    void selectNextButton();
    void selectPreviousButton();
    void confirmSelection();

    bool mainMenuOpen = true;
    static const int MAX_BUTTONS = 12;
    int totalButtons = 0;
    int currentSelected = 0; // 0 based

    struct myButton {
        Button* button;
        LTexture* selectedTexture;
        SDL_Rect selectedRenderQuad;
        LTexture* unselectedTexture;
        SDL_Rect unselectedRenderQuad;
    };

    myButton myButtons[MAX_BUTTONS] = {};

    Button* buttons[MAX_BUTTONS] = {};

    LTexture* backgroundTexture;
    LTexture buttonSheet{renderer};
};