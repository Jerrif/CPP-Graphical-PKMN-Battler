#pragma once

#include "Message.hpp"
#include "LTexture.hpp"
#include <iostream>

class Button {
public:
    Button(std::string pButtonText, Message::types msgType, bool pSelected = false);
    ~Button();

    bool isSelected();
    void setSelected();
    void setUnselected();
    std::string getButtonText();
    Message::types getButtonMessage();

private:
    std::string buttonText {"nullText"};
    Message::types tempMsg;
    bool selected {false};
    Message* buttonMessage = new Message{};

    // graphics
    // LTexture selectedTexture{renderer};

};