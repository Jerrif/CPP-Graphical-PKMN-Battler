#include "Button.hpp"
#include "LTexture.hpp"
#include <iostream>

// Button::Button(std::string pButtonText, Message::types msgType, bool pSelected)
// : buttonText{pButtonText}, tempMsg{msgType}, selected{pSelected} {
Button::Button(std::string pButtonText, Message::types msgType, LTexture* texture, bool pSelected)
: buttonText{pButtonText}, tempMsg{msgType}, selected{pSelected} {
    printf("Constructor:\tButton\n");
    buttonMessage->type = tempMsg;

    // TEXTURE TESTING
    // printf("Loading texture: %s\n", selectedTexture);
    // printf("Loading texture: %s\n", unSelectedTexture);
    // selectedTexture.loadFromFile("images/004b.png");
    // unSelectedTexture.loadFromFile("images/001b.png");
    // selectedTexture.loadFromFile("images/battleCommandButtons.png");
    // unSelectedTexture.loadFromFile("images/001b.png");
    // renderTexture = &unSelectedTexture;
    // renderTexture = (selected ? &selectedTexture : &unselectedTexture);
    // renderTexture = (selected ? selectedTexture : unselectedTexture);
    renderTexture = texture;
}

Button::~Button() {
    printf("Destructor:\tButton\n");
}

bool Button::isSelected() {
    return selected;
}

void Button::setSelected() {
    selected = true;
    // renderTexture = &selectedTexture;
    renderTexture = selectedTexture;
}

void Button::setUnselected() {
    selected = false;
    // renderTexture = &unselectedTexture;
    renderTexture = unselectedTexture;
}

std::string Button::getButtonText() {
    return buttonText;
}

Message::types Button::getButtonMessage() {
    return buttonMessage->type;
}

// void Button::render() {
//     selectedTexture.render(100, 100, NULL, NULL);
// }