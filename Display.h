//
// Created by leona on 28/11/2022.
//

#ifndef LABPROG_CHAT_MASTER_DISPLAY_H
#define LABPROG_CHAT_MASTER_DISPLAY_H


#include <memory>
#include "Messaggio.h"
#include "Chat.h"
#include "User.h"

class Display {
public:
    static void dNotif(int i, const Messaggio& pMess);

    static void activeChat(User user, std::map<std::string,std::shared_ptr<Chat>>&);

    static void readChat(const std::shared_ptr<Chat>&);
};


#endif //LABPROG_CHAT_MASTER_DISPLAY_H
