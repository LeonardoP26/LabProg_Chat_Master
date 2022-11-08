//
// Created by leona on 06/11/2022.
//

#include <iostream>

#include "Chat.h"


Chat::Chat(User us1, User us2) : user1(us1.getName()), user2(us2.getName()) {

};

Chat::~Chat() {

}

void Chat::subscribe(std::shared_ptr<Observer> o) {
    observers.push_back(o);
}

void Chat::unsubscribe(std::shared_ptr<Observer> o) {
    observers.remove(o);
}

void Chat::notify() {
    for(const auto& obs:observers)
        obs->update();
}

void Chat::addMessage(const Messaggio &Mess) {
    if( ((user1 == Mess.getSender()) && (user2 == Mess.getReceiver())) ||
            ((user2 == Mess.getSender()) && (user1 == Mess.getReceiver())))
    {
        messages.push_back(Mess);
    }else {
        throw std::out_of_range("Errore: mittente o destinatario errati");
    }

    if(user1 == Mess.getReceiver()){
        this->notify();
    }
}

void Chat::readChat() {
    if(!messages.empty()) {
        std::cout << "\nChat di " << user1 << " con " << user2 << ":" << std::endl;
        for (auto &m: messages) {
            std::cout << m.getSender() << ": " << m.getText() << std::endl;

            if(m.getReceiver() == user1) {
                m.setVisual(true);
            }
        }
        this->notify();
    }else{
        std::cout << "Non ci sono messaggi in questa chat" << std::endl;
    }
}

void Chat::unreadChats() {
    int i = 0;
    for(auto &m : messages){
        if(m.getSender() == user2 && !m.isVisual()){
            i++;
        }
    }
    std::cout << "\n" << user1 << " ha " << i << " messaggi non letti nella chat con " << user2 << std::endl;
}
