#pragma once

#include "GameObject.hpp"
#include "Message.hpp"
#include "LTexture.hpp"
#include <iostream>

class Button : public GameObject {
public:
    // Button(std::string pButtonText, Message::types msgType, bool pSelected = false);
    Button(std::string pButtonText, Message::types msgType, LTexture* texture, bool pSelected = false);
    ~Button();

    bool isSelected();
    void setSelected();
    void setUnselected();
    std::string getButtonText();
    Message::types getButtonMessage();

    // public
    LTexture* selectedTexture;
    LTexture* unselectedTexture;
    // void render();

private:
    std::string buttonText {"nullText"};
    Message::types tempMsg;
    bool selected {false};
    Message* buttonMessage = new Message{};

    // graphics
    // LTexture selectedTexture{renderer};
    // LTexture unselectedTexture{renderer};
    // LTexture* selectedTexture;
    // LTexture* unselectedTexture;
};