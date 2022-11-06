//
// Created by leona on 06/11/2022.
//

#ifndef LABPROG_CHAT_MASTER_CHAT_H
#define LABPROG_CHAT_MASTER_CHAT_H


#include <list>


#include "Subject.h"
#include "User.h"

class User;
class Chat :public Subject{
public:
    explicit Chat(User us1, User us2);

    virtual ~Chat();


    virtual void subscribe(std::shared_ptr<Observer o>) override;
    virtual void unsubscribe(std::shared_ptr<Observer o>) override;
    virtual void notify() override;


private:
    std::string us1;
    std::string us2;
    std::list<std::shared_ptr<Observer>> observers;
};


#endif //LABPROG_CHAT_MASTER_CHAT_H
