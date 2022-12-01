//
// Created by leona on 06/11/2022.
//
#include <unistd.h>
#include <iostream>

#include "Chat.h"
#include "Display.h"



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

void Chat::readChat() {         //TODO Non deve farlo lui
    if(!messages.empty()) {
        std::cout << "\nChat di " << user1 << " con " << user2 << ":" << std::endl;

        for (auto &m: messages) {
            std::cout << m.getSender() << ": " << m.getText() << std::endl;


            if (m.getReceiver() == user1) {
                m.setVisual(true);
            }
        }

    }else{
        std::cout << "\nNon ci sono messaggi nella chat tra " << user1 << " e " << user2 << std::endl;
    }
}

int Chat::mexNonLetti(const std::string& user) {
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

int Chat::getNumMess() {
     return messages.size();
}

Messaggio Chat::getMess(int pos) {
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

