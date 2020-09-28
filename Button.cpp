#include "Button.hpp"
#include "LTexture.hpp"
#include <iostream>

Button::Button(std::string pButtonText, Message::types msgType, bool pSelected) : buttonText{pButtonText}, tempMsg{msgType}, selected{pSelected} {
    printf("Constructor:\tButton\n");
    buttonMessage->type = tempMsg;
}

Button::~Button() {
    printf("Destructor:\tButton\n");
}

bool Button::isSelected() {
    return selected;
}

void Button::setSelected() {
    selected = true;
}

void Button::setUnselected() {
    selected = false;
}

std::string Button::getButtonText() {
    return buttonText;
}

Message::types Button::getButtonMessage() {
    return buttonMessage->type;
}