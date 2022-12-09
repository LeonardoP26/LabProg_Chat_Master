//
// Created by leona on 28/11/2022.
//

#ifndef LABPROG_CHAT_MASTER_DISPLAY_H
#define LABPROG_CHAT_MASTER_DISPLAY_H


#include <iostream>
#include "Messaggio.h"
#include "Chat.h"
#include "User.h"

static void dNotif(int, const Messaggio&);

static void dActiveChat(User, std::map<std::string,std::shared_ptr<Chat>>&);

static void readChat(const std::shared_ptr<Chat>&);



void dNotif(int i, const Messaggio& pMess) {
    if (i == 1) {
        std::cout << pMess.getReceiver() << " ha " << i << " nuovo messaggio nella chat con " << pMess.getSender() <<  std::endl;
    } else {
        std::cout << pMess.getReceiver() << " ha " << i << " nuovi messaggi nella chat con " << std::endl;
    }
}


void dActiveChat(User pUser, std::map<std::string,std::shared_ptr<Chat>> &Map) {
    if(pUser.getNumChats() == 1){
        std::cout << "\n" << pUser.getName() << " ha "  << pUser.getNumChats() << " chat attiva: " << std::endl;
    }else if(pUser.getNumChats() == 0){
        std::cout << "\n" << pUser.getName() << " ha "  << pUser.getNumChats() << " chat attive. " << std::endl;
    }else{
        std::cout << "\n" << pUser.getName() << " ha "  << pUser.getNumChats() << " chat attive: " << std::endl;
    }
    for(auto &c:Map){
        std::cout << "-" << c.first << std::endl;
    }
}



void readChat(const std::shared_ptr<Chat>& pChat) {
    if(pChat == nullptr){
        return;
    }
    if(pChat->getNumMess() != 0) {
        std::cout << "\nChat di " << pChat->getUser1() << " con " << pChat->getUser2() << ":" << std::endl;

        for (int i = 1; i <= pChat->getNumMess(); i++) {
            std::cout << pChat->getMess(i).getSender() << ": " << pChat->getMess(i).getText() << std::endl;
            pChat->getMess(i).setVisual(true);
        }
    }else{
        std::cout << "\nNon ci sono messaggi nella chat tra " << pChat->getUser1() << " e " << pChat->getUser2() << std::endl;
    }
}


#endif //LABPROG_CHAT_MASTER_DISPLAY_H
