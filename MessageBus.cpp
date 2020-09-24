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
void MessageBus::postMessage(Message* msg) {
    printf("Adding message to queue: %i\n", msg->type);
    messageQueue[pendingMessages] = msg;
    pendingMessages++;
}
// void MessageBus::postMessage(Message* msg) { // THIS WAS THE ORIGINAL ONE
//     for(int i=0; i < attachedSystems; ++i) {
//         systems[i]->handleMessage(msg);
//     }
// }

void MessageBus::sendMessages() {
    if(!pendingMessages) {
        return;
    }
    for(int i=0; i < pendingMessages; i++) {
    printf("Posting message: %i\n", messageQueue[i]->type);
        for(int j=0; j < attachedSystems; ++j) {
            systems[j]->handleMessage(messageQueue[i]);
        }
        printf("Done posting message: %i\n", messageQueue[i]->type);
    }
    printf("Resetting pending messages\n");
    pendingMessages = 0;
}