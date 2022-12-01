//
// Created by leona on 28/11/2022.
//

#ifndef LABPROG_CHAT_MASTER_DISPLAY_H
#define LABPROG_CHAT_MASTER_DISPLAY_H


#include <memory>
#include "Messaggio.h"
#include "Chat.h"

class Display {
public:
    static void dNotif(int i, const Messaggio& pMess);

    void messNonLetti();

    void readChat();
};


#endif //LABPROG_CHAT_MASTER_DISPLAY_H
