//
// Created by leona on 06/11/2022.
//
#include <unistd.h>
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

void Chat::notify() {
    for(const auto& obs:observers)
        obs->update();
}

void Chat::addMessage(const Messaggio &Mess) {
    if( ((user1 == Mess.getSender()) && (user2 == Mess.getReceiver())) || ((user2 == Mess.getSender()) && (user1 == Mess.getReceiver())))
    {
        if((user1 == Mess.getSender())){
            std::cout << "\n" << user1 << " sta scrivendo a " << user2 << "..." << std::endl;
        }else{
            std::cout << "\n" << user2 << " sta scrivendo a " << user1 << "..." << std::endl;
        }

        sleep(1);
        messages.push_back(Mess);
    }else {
        throw std::out_of_range("Errore: mittente o destinatario errati");
    }

    if(user1 == Mess.getReceiver() || user1 == Mess.getSender()){ //notifica entrambi
        this->notify();
    }
}

void Chat::readChat() {
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

void Chat::unreadChats() {
    int i = 0;
    int a = 0;
    for(auto &m : messages){

        if(m.getSender() == user2 && !m.isVisual()) {
            i++;
        }

        if (m.getSender() == user1 && !m.isVisual()) {
            a++;
            i = 0; //Se è il sender allora vuol dire che ha letto i messaggi prima
        } else if (i > 0 && a > 0) {
            a = 0;
        }
    }

    if(i>0) {
        if (i == 1) {
            std::cout << "" << user1 << " ha " << i << " nuovo messaggio nella chat con " << user2 << std::endl;
        } else {
            std::cout << "" << user1 << " ha " << i << " nuovi messaggi nella chat con " << user2 << std::endl;
        }
    }
    if(a>0){
        if (a == 1) {
            std::cout << "" << user2 << " ha " << a << " nuovo messaggio nella chat con " << user1 << std::endl;
        } else {
            std::cout << "" << user2 << " ha " << a << " nuovi messaggi nella chat con " << user1 << std::endl;
        }
    }
    sleep(1);
}

void Chat::removeChat() {
   for(int i = 0 ; messages.size(); i++) {
        messages.pop_back();
    }
}
