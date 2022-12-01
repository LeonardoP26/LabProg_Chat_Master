//
// Created by leona on 08/11/2022.
//

#ifndef LABPROG_CHAT_MASTER_MESSAGENOTIFICATION_H
#define LABPROG_CHAT_MASTER_MESSAGENOTIFICATION_H


#include <memory>

#include "Observer.h"
#include "Chat.h"
#include "Messaggio.h"

class MessageNotification : public Observer{
public:
    explicit MessageNotification(std::shared_ptr<Chat> chatSubject) : chat(chatSubject){}

    ~MessageNotification() override;

    void attach() override;
    void detach() override;
    void update(int, Messaggio) override;

private:
    std::shared_ptr<Chat> chat;
};


#endif //LABPROG_CHAT_MASTER_MESSAGENOTIFICATION_H
