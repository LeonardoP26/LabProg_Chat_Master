//
// Created by leona on 28/11/2022.
//

#include <iostream>
#include "Display.h"
#include "Messaggio.h"

void Display::dNotif(int i, const Messaggio& pMess) {
    if (i == 1) {
        std::cout << pMess.getReceiver() <<   " ha " << i << " nuovo messaggio nella chat con " << pMess.getSender() <<  std::endl;
    } else {
        std::cout << pMess.getReceiver() <<   " ha " << i << " nuovi messaggi nella chat con " <<   std::endl;
    }
}

void Display::messNonLetti() {

}

void Display::readChat() {
    
}
