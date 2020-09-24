#include "System.hpp"
// #include "Message.hpp"
// #include "MessageBus.hpp"

#include <iostream>

System::~System() {
}

void System::handleMessage(Message* msg) {
    printf("Generic System message handler. This should not be able to be called\n");
}

void System::postMessage(Message::types messageType) {
    myMsg->type = messageType;
    msgBus->postMessage(myMsg);
}