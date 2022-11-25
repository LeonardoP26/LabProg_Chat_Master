//
// Created by leona on 08/11/2022.
//

#include "MessageNotification.h"

MessageNotification::~MessageNotification() {

}

void MessageNotification::attach() {
    std::shared_ptr<MessageNotification> ptr = std::make_shared<MessageNotification>(*this);
    chat->subscribe(ptr);
}

void MessageNotification::detach() {
    std::shared_ptr<MessageNotification> ptr = std::make_shared<MessageNotification>(*this);
    chat->unsubscribe(ptr);
}

void MessageNotification::update() {
    chat->unreadChats();
}
