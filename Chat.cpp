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
    observers.pop_back();
}

void Chat::notify(std::string user) {
    for(const auto& obs:observers) {
        obs->update(mexNonLetti(user), messages.at(messages.size() - 1));
    }
}

void Chat::addMessage(const Messaggio &Mess) {
    if( ((user1 == Mess.getSender()) && (user2 == Mess.getReceiver())) || ((user2 == Mess.getSender()) && (user1 == Mess.getReceiver())))
    {
        messages.push_back(Mess);
    }else {
        throw std::out_of_range("Errore: mittente o destinatario errati");
    }

    if(user2 == Mess.getReceiver()){ //dNotif
        this->notify(user2);
        this->setAllMessVisual(user1);
    }else
    if(user1 == Mess.getReceiver()){ //dNotif
        this->notify(user1);
        this->setAllMessVisual(user2);
    }
}


int Chat::mexNonLetti(const std::string& user) const{
    int count= 0;
    for(auto &m : messages) {
        if (m.getReceiver() == user && !m.isVisual()) {
            count++;
        }
    }
    return count;
}

void Chat::removeChat() {
   for(int i = 0 ; !messages.empty(); i++) {
        messages.pop_back();
    }
}

int Chat::getNumMess() const{
     return messages.size();
}

Messaggio Chat::getMess(int pos) const{
    pos = pos - 1;
    return messages[pos];
}

void Chat::setAllMessVisual(const std::string& user){
    for(auto &m : messages) {
        if (m.getReceiver() == user && !m.isVisual()) {
            m.setVisual(true);
        }
    }
}

std::string Chat::getUser1() const{
    return user1;
}

std::string Chat::getUser2() const{
    return user2;
}
