//
// Created by leona on 06/11/2022.
//


#include <iostream>
#include "User.h"


User::User(std::string name) : name(name){

}


User::~User() {

}

std::shared_ptr<Chat> User::createChat(User &u) {
    Chat *c = new Chat((*this), u);
    std::shared_ptr<Chat> chatptr = std::make_shared<Chat>(*c);
    this->addChat(chatptr,(u));
    return chatptr;
}

void User::addChat(std::shared_ptr<Chat> c, User &u) {
    chats.insert(make_pair(u.getName(),c));
}

void User::removeChat(const User &u) {
    auto c = chats.find(u.getName());
    chats.erase(c);
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
    for(auto &c:chats)
        std::cout << c.first << std::endl;
}
