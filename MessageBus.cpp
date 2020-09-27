#include "MessageBus.hpp"
#include "Message.hpp"
#include "System.hpp"

#include <iostream>

MessageBus::MessageBus() {
    printf("Constructor:\tMessageBus\n");
}

MessageBus::~MessageBus() {
    printf("Destructor:\tMessageBus\n");
}

void MessageBus::printSystemAddresses() {
    // just for debugging
    for(auto & element : systems) {
        if(element != NULL) {
            // std::cout << "System: " << &element << std::endl; // don't know what this is
            std::cout << "System: " << element << std::endl; // this is the actual address of the thing
        }
    }
}

void MessageBus::detachSystem(System& system) {
    for(size_t i = 0; i < systems.size(); ++i ) {
        if(systems[i] == &system) {
            std::cout << "Detaching system " << i << " at: " << systems[i] << std::endl;
            systems.erase(systems.begin() + i);
            // attachedSystems--;
            return;
        }
    }
}

void MessageBus::attachToSystem(System& system) {
    systems.push_back(&system);
    printf("Message bus attached to System. Size: %llu\n", systems.size());
    // attachedSystems++;

    system.msgBus = this;

    return;
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
        for(size_t j = 0; j < systems.size(); ++j ) {
            systems[j]->handleMessage(messageQueue[i]);
        }
    }
    pendingMessages = 0;
}