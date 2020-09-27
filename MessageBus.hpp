#pragma once

#include "Message.hpp"
// #include "System.hpp"

// Every system that needs to recieve messages needs to be included here
// ^ WRONG! every system needs to be forward declared here

#include <SDL2/SDL.h>
#include <string>
#include <vector>

class System;
class Message;

class MessageBus {
public:
    MessageBus();
    ~MessageBus();

    void attachToSystem(System& ts);
    void detachSystem(System& system);
    void postMessage(Message& msg);
    void sendMessages();
    void printSystemAddresses();

private:
    // this is just some arbitrary number I picked right now
    static const int MAX_SYSTEMS = 12;
    // int attachedSystems = 0;
    // System* systems[MAX_SYSTEMS] = {};
    std::vector<System*> systems;

    static const int MAX_MESSAGES = 12;
    int pendingMessages = 0;
    Message messageQueue[MAX_MESSAGES];
};
