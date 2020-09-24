#include "MessageBus.hpp"
#include "Message.hpp"
#include "System.hpp"
// #include "TestSystemOne.hpp"

#include <iostream>

MessageBus::MessageBus() {
    printf("Constructor:\tMessageBus\n");
}

MessageBus::~MessageBus() {
    printf("Destructor:\tMessageBus\n");
}

void MessageBus::attachToSystem(System& system) {
    for(int i=0; i < MAX_SYSTEMS; ++i) {
        if(systems[i] != NULL) {
            // find the first empty slot for a system
            continue;
        }
        systems[i] = &system;
        printf("Message bus attached to System at index: %i\n", i);
        attachedSystems++;

        system.msgBus = this;

        return;
    }
}

// testing out a queue system. This is basically "addToQueue" right now
void MessageBus::postMessage(Message& msg) {
    // printf("Adding message to queue: %i\n", msg.type);
    messageQueue[pendingMessages] = msg;
    pendingMessages++;
}

// send each message in queue, one by one
void MessageBus::sendMessages() {
    if(!pendingMessages) {
        return;
    }
    for(int i=0; i < pendingMessages; i++) {
    // printf("Posting message: %i\n", messageQueue[i].type);
        for(int j=0; j < attachedSystems; ++j) {
            systems[j]->handleMessage(messageQueue[i]);
        }
        // printf("Done posting message: %i\n", messageQueue[i].type);
    }
    pendingMessages = 0;
}