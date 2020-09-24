#pragma once

#include <SDL2/SDL.h>
#include <string>

#include "Message.hpp"
// #include "System.hpp"
// #include "TestSystemOne.hpp"

// Every system that needs to recieve messages needs to be included here
// ^ WRONG! every system needs to be forward declared here

class System; // forward declaring TestSystem
class Message;

class MessageBus {
public:
    MessageBus();
    ~MessageBus();

    void attachToSystem(System& ts);
    void postMessage(Message& msg);
    void sendMessages();

private:
    // this is just some arbitrary number I picked right now
    static const int MAX_SYSTEMS = 10;
    int attachedSystems = 0;
    System* systems[MAX_SYSTEMS] = {};

    static const int MAX_MESSAGES = 12;
    int pendingMessages = 0;
    Message messageQueue[MAX_MESSAGES];
};
