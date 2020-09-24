#pragma once

#include "System.hpp"

class AudioSystem : public System {
public:
    AudioSystem();
    ~AudioSystem();

    void handleMessage(Message* msg);

    void playSound(std::string soundPath);

private:
    // Message* myMsg = new Message{};
};