//
// Created by leona on 06/11/2022.
//


#include <iostream>
#include "User.h"
#include "MessageNotification.h"
#include "Chat.h"

User::User(std::string name) : name(name){

}


User::~User() {

}

std::shared_ptr<Chat> User::createChat(User &u) {
    Chat *c = new Chat((*this), u);
    std::shared_ptr<Chat> chatptr = std::make_shared<Chat>(*c);
    this->addChat(chatptr,u);
    u.addChat(chatptr, (*this));

    MessageNotification nm(chatptr);
    nm.attach();

    return chatptr;
}

void User::addChat(std::shared_ptr<Chat> c, User &u) {
    chats.insert(make_pair(u.getName(),c));
}

void User::removeChat(std::shared_ptr<Chat> rm, User u) {
    auto i = chats.find(u.getName());
    chats.erase(i);

    MessageNotification nm1(rm);
    nm1.detach();

    rm->removeChat(u);
//TODO remove inverso
}

const std::string &User::getName() const {
    return name;
}

void User::activeChat() {
    if(chats.size() == 1){
        std::cout << getName() << " ha "  << chats.size() << " chat attiva: " << std::endl;
    }else{
        std::cout << getName() << " ha "  << chats.size() << " chat attive: " << std::endl;
    }
    for(auto &c:chats) {
        std::cout << c.first << std::endl;
    }
}
