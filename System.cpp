#include "System.hpp"
// #include "Message.hpp"
// #include "MessageBus.hpp"

#include <iostream>

// NOTE: static variables just need to be defined in exactly one of your source files:
SDL_Renderer* System::renderer = NULL;

void System::attachRenderer(SDL_Renderer* r) {
    std::cout << "Test Renderer before: " << renderer << "\n" << std::endl;
    renderer = r;
    std::cout << "Test Renderer after: " << renderer << "\n" << std::endl;
}

System::~System() {
}

void System::handleMessage(Message& msg) {
    printf("Generic System message handler. This should not be able to be called\n");
}

void System::postMessage(Message::types messageType) {
    myMsg.type = messageType;
    msgBus->postMessage(myMsg);
}