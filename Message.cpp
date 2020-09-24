#include "Message.hpp"

Message::Message() {
    printf("Constructor:\tMessage\n");
    type = NULL_MSG;
}

Message::~Message() {
    printf("Destructor:\tMessage\n");
}