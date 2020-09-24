#include "AudioSystem.hpp"
// #include "Message.hpp"
#include <iostream>

AudioSystem::AudioSystem() {
    printf("Constructor:\tAudioSystem\n");
}

AudioSystem::~AudioSystem() {
    printf("Destructor:\tAudioSystem\n");
}

void AudioSystem::handleMessage(Message& msg) {
    switch(msg.type) {
        case Message::PLAY_SOUND:
        playSound("Dummy Sound");
        break;

        default:
        break;

    }
}

void AudioSystem::playSound(std::string soundPath) {
    // std::cout << "Playing sound: " << soundPath << std::endl;
    // printf("Playing sound: \t%s\n", soundPath.c_str());
}