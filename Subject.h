//
// Created by leona on 06/11/2022.
//

#ifndef LABPROG_CHAT_MASTER_SUBJECT_H
#define LABPROG_CHAT_MASTER_SUBJECT_H


#include <memory>
#include "Observer.h"

class Subject {
public:
    virtual ~Subject() = default;
    virtual void subscribe(std::shared_ptr<Observer> observer) = 0;
    virtual void unsubscribe(std::shared_ptr<Observer> observer) = 0;
    virtual void notify(std::string) = 0;
};


#endif //LABPROG_CHAT_MASTER_SUBJECT_H
