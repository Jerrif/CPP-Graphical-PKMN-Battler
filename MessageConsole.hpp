#pragma once

#include "System.hpp"

// this class simply logs all messages sent, and prints their actual enum message (rather than the int value)
class MessageConsole : public System {
public:
    MessageConsole();
    ~MessageConsole();

    void handleMessage(Message& msg);

private:

};