#include "GuiMainMenu.hpp"

#include <iostream>

GuiMainMenu::GuiMainMenu() {
    printf("Constructor:\tGuiMainMenu\n");
    systemName = "GuiMainMenu";
    printf("Loading buttons?\n");

    loadButtonTextures();

    addButton("Start!", Message::GAME_START);
    addButton("Options!", Message::GUI_OPTIONS_OPEN);
    addButton("Quit!", Message::USER_QUIT);
    addButton("Hidden Button!", Message::NULL_MSG);
}

GuiMainMenu::~GuiMainMenu() {
    printf("Destructor:\tGuiMainMenu\n");
}

void GuiMainMenu::loadButtonTextures() {
    // LTexture* t = new LTexture{renderer};
    // textureSheet = new LTexture{renderer};
    // buttonSheet = new LTexture{renderer};
    buttonSheet.loadFromFile("images/battleCommandButtons.png");
}

// Must add button in order of their appearance, the first button defaults to selected
// void GuiMainMenu::addButton(std::string buttonText, Message::types msg, std::string selectedTexture, std::string unselectedTexture) {
void GuiMainMenu::addButton(std::string buttonText, Message::types msg) {
    // Maybe I should assert(totalButtons <= MAX_BUTTONS)?
    // buttons[totalButtons] = new Button{buttonText, msg, !totalButtons};

    // this is stupid, I don't even pass this struct in to the actual button, it just does nothing

    myButtons[totalButtons].button = new Button{buttonText, msg, &buttonSheet, !totalButtons};
    myButtons[totalButtons].selectedTexture = &buttonSheet;
    myButtons[totalButtons].button->selectedTexture = &buttonSheet;
    myButtons[totalButtons].selectedRenderQuad = {100, 100 * totalButtons, 100, 40};
    myButtons[totalButtons].unselectedTexture = &buttonSheet;
    myButtons[totalButtons].button->unselectedTexture = &buttonSheet;
    myButtons[totalButtons].unselectedRenderQuad = {100, 100 * totalButtons, 100, 40};

    totalButtons++;
}

void GuiMainMenu::selectNextButton() {
    // buttons[currentSelected]->setUnselected();
    myButtons[currentSelected].button->setUnselected();

    if(currentSelected == totalButtons - 1) {
        currentSelected = 0;
    } else {
        currentSelected++;
    }
    // buttons[currentSelected]->setSelected();
    myButtons[currentSelected].button->setSelected();
    postMessage(Message::PLAY_SOUND);
}

void GuiMainMenu::selectPreviousButton() {
    // buttons[currentSelected]->setUnselected();
    myButtons[currentSelected].button->setUnselected();

    if(currentSelected == 0) {
        currentSelected = totalButtons - 1;
    } else {
        currentSelected--;
    }
    // buttons[currentSelected]->setSelected();
    myButtons[currentSelected].button->setSelected();
    postMessage(Message::PLAY_SOUND);
}

void GuiMainMenu::confirmSelection() {
    // printf("Confirmed button selection: %s\n", buttons[currentSelected]->getButtonText().c_str());
    // myMsg.type = buttons[currentSelected]->getButtonMessage();
    printf("Confirmed button selection: %s\n", myButtons[currentSelected].button->getButtonText().c_str());
    myMsg.type = myButtons[currentSelected].button->getButtonMessage();
}

void GuiMainMenu::handleMessage(Message& msg) {
    if(!mainMenuOpen) {
        switch(msg.type) {
            case Message::GUI_MAIN_MENU_OPEN:
            mainMenuOpen = true;
            break;

            default:
            break;
        }
        return;
    }
    switch(msg.type) {
        case Message::GUI_UP_PRESSED:
        // printf("\nGuiMainMenu:\tGui up\n");
        selectPreviousButton();
        // printf("Selected button: %s\n", buttons[currentSelected]->getButtonText().c_str());
        printf("Selected button: %s\n", myButtons[currentSelected].button->getButtonText().c_str());
        break;

        case Message::GUI_DOWN_PRESSED:
        // printf("\nGuiMainMenu:\tGui down\n");
        selectNextButton();
        // printf("Selected button: %s\n", buttons[currentSelected]->getButtonText().c_str());
        printf("Selected button: %s\n", myButtons[currentSelected].button->getButtonText().c_str());
        break;

        case Message::GUI_ENTER_PRESSED:
        // printf("\nGuiMainMenu:\tGui confirm selection\n");
        confirmSelection();
        postMessage(myMsg.type);
        break;

        // case Message::GAME_START:
        // printf("\nGuiMainMenu:\tGame start message\n");
        // mainMenuOpen = false;
        // break;

        case Message::GUI_OPTIONS_OPEN:
        printf("GuiMainMenu:\tGui options open\n");
        break;

        case Message::USER_QUIT:
        printf("GuiMainMenu:\tUser quit\n");
        break;

        case Message::NULL_MSG:
        // printf("GuiMainMenu:\tHidden message\n");
        break;

        case Message::GUI_MAIN_MENU_CLOSE:
        printf("GuiMainMenu:\tMain menu closed\n");
        mainMenuOpen = false;
        break;

        default:
        break;
    }
}

void GuiMainMenu::update() {
    if(!mainMenuOpen) return;
    for(int i = 0; i < totalButtons; ++i) {
        // buttons[i]->render(150, 100 + (i * 100), NULL, false);
        myButtons[i].button->render(150, 100 + (i * 100), NULL, false);
    }
}