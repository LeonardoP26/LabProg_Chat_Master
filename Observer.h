//
// Created by leona on 06/11/2022.
//

#ifndef LABPROG_CHAT_MASTER_OBSERVER_H
#define LABPROG_CHAT_MASTER_OBSERVER_H


#include "Messaggio.h"

class Observer{
public:
    virtual ~Observer() = default;

    virtual void attach() = 0;
    virtual void detach() = 0;
    virtual void update(int, Messaggio) = 0;
};


#endif //LABPROG_CHAT_MASTER_OBSERVER_H
