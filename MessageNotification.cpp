//
// Created by leona on 08/11/2022.
//

#include <iostream>
#include "MessageNotification.h"
#include "Display.h"


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

void MessageNotification::update(int i, Messaggio pMess) {
    Display::dNotif(i, pMess);
}
