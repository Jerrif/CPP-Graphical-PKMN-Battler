#pragma once

#include "MessageBus.hpp"
#include "Message.hpp"

#include <SDL2/SDL.h>

#include <cassert> // TODO: Remove when done?

// forward declare MessageBus (is this needed?)
// class MessageBus;
// class Message;

class System {
    // a friend class allows that class to access protected methods/members of this class
    // here, this is used to give each system a reference to the message bus
    friend class MessageBus;
public:
    virtual ~System();

    virtual void handleMessage(Message& msg) = 0;
    void postMessage(Message::types messageType);

    // TEXTURE TESTING
    void attachRenderer(SDL_Renderer* r);

protected:
    std::string systemName = "System";
    MessageBus* msgBus = NULL;
    // each derived class of this will have its own instance of Message
    Message myMsg {};

    // TEXTURE TESTING
    /* NOTE: static variables just need to be defined in exactly one of your source files:
    http://www.cs.technion.ac.il/users/yechiel/c++-faq/link-errs-static-data-mems.html */ 
    static SDL_Renderer* renderer;
};