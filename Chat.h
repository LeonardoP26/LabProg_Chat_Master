//
// Created by leona on 06/11/2022.
//

#ifndef LABPROG_CHAT_MASTER_CHAT_H
#define LABPROG_CHAT_MASTER_CHAT_H


#include <list>
#include <vector>

#include "Subject.h"
#include "User.h"
#include "Messaggio.h"

class User;
class Chat :public Subject{
public:
    explicit Chat(User us1, User us2);

    virtual ~Chat();

    void addMessage(const Messaggio &Mess);

    void removeChat();

    int mexNonLetti(const std::string&);

    int getNumMess();

    Messaggio getMess(int);

    void setAllMessVisual(const std::string&);

    std::string getUser1();
    std::string getUser2();



    virtual void subscribe(std::shared_ptr<Observer> o) override;
    virtual void unsubscribe(std::shared_ptr<Observer> o) override;
    virtual void notify(std::string) override;


private:
    std::string user1;
    std::string user2;
    std::list<std::shared_ptr<Observer>> observers;
    std::vector<Messaggio> messages;
};


#endif //LABPROG_CHAT_MASTER_CHAT_H