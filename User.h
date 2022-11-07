//
// Created by leona on 06/11/2022.
//

#ifndef LABPROG_CHAT_MASTER_USER_H
#define LABPROG_CHAT_MASTER_USER_H

#include <memory>
#include <string>
#include "Chat.h"
#include <map>


class Chat;
class User {
public:
    explicit User(std::string name);

    ~User();

    //chat create per utente
    std::shared_ptr<Chat> createChat(User &u);

    void addChat(std::shared_ptr<Chat> c, User &u);
    void removeChat(const User &u);
    void activeChat();
    const std::string &getName() const;

private:
    std::string name;
    std::map <std::string,std::shared_ptr<Chat>> chats;
};


#endif //LABPROG_CHAT_MASTER_USER_H
