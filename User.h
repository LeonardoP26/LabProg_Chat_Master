//
// Created by leona on 06/11/2022.
//

#ifndef LABPROG_CHAT_MASTER_USER_H
#define LABPROG_CHAT_MASTER_USER_H

#include <string>
#include "Chat.h"


class Chat;
class User {
public:
    explicit User(std::string name);

    ~User();


private:
    std::string name;
};


#endif //LABPROG_CHAT_MASTER_USER_H
