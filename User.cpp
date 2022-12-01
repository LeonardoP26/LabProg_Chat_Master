//
// Created by leona on 06/11/2022.
//

#include <iostream>

#include "User.h"
#include "MessageNotification.h"
#include "Chat.h"
#include "Display.h"

User::User(std::string name) : name(name){

}

User::~User() {

}

std::shared_ptr<Chat> User::createChat(User &u) {
    for(auto &co:u.couples) {
        if(this->getName() == co.first && u.getName() == co.second || this->getName() == co.second && u.getName() == co.first) {
            std::cout << "Esiste gia una chat tra i due" << std::endl;
            throw std::out_of_range("Esiste gia una chat tra i due");
        }
    }

    Chat *c = new Chat((*this), u);
    std::shared_ptr<Chat> chatptr = std::make_shared<Chat>(*c);
    this->addChat(chatptr, u);

    MessageNotification nm(chatptr);
    nm.attach();

    return chatptr;
}


void User::addChat(const std::shared_ptr<Chat>& c, User &u) {
    chats.insert(make_pair(u.getName(),c));
    couples.insert(make_pair(u.getName(),this->getName()));

    u.chats.insert(make_pair(this->getName(),c));
    u.couples.insert(make_pair(this->getName(),u.getName()));
}


void User::removeChat(std::shared_ptr<Chat> &rm, User &u) {
    //Toglie mappa di chat da entrambi gli utenti
    auto c = chats.find(u.getName());
    chats.erase(c);

    auto rev = u.chats.find(this->getName());
    u.chats.erase(rev);


    //Toglie mappa di coppia da entrambi gli utenti
    auto ex = u.couples.find(this->getName());
    u.couples.erase(ex);

    auto ex1 = couples.find(u.getName());
    couples.erase(ex1);

    //Toglie dNotif
    MessageNotification nm1(rm);
    nm1.detach();

    //Toglie messaggi da chat
    rm->removeChat();

    rm = nullptr;
    delete &rm;
}

const std::string &User::getName() const {
    return name;
}

void User::activeChat() {
    Display::activeChat(*this, chats);
}

int User::getNumChats() {
    return chats.size();
}