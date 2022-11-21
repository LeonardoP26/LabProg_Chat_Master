#include <iostream>
#include <unistd.h>
#include <memory>


#include "User.h"
#include "Messaggio.h"
#include "Chat.h"

int main() {
    User Leo("Leonardo");
    User Filippo("Filippo");
    User Giuseppe("Giuseppe");


    std::shared_ptr<Chat> ptr = Leo.createChat(Filippo);
    //std::shared_ptr<Chat> ptr1 = Filippo.createChat(Leo); // esiste già
    std::shared_ptr<Chat> ptrG = Giuseppe.createChat(Leo);

    Leo.activeChat();
    Filippo.activeChat();
    Giuseppe.activeChat();


    Messaggio mess1("Leonardo", "Filippo", "Ciao");
    Messaggio mess2("Filippo", "Leonardo" , "Ciao anche a te");
    Messaggio mess3("Filippo", "Leonardo" , "Come va?");

    Messaggio mess10("Filippo", "Leonardo" , "Ci vediamo dopo?");
    Messaggio mess11("Leonardo", "Filippo", "Tutto bene. Certo a che ora?");
    Messaggio mess21("Leonardo", "Filippo", "Tutto bene. Certo 1");
    Messaggio mess12("Filippo", "Leonardo" , "Verso le 18?");
    Messaggio mess13("Leonardo", "Filippo", "Va bene");


    Messaggio mess4("Giuseppe", "Leonardo" , "Tutto bene?");
    Messaggio mess5("Leonardo", "Giuseppe" , "Si");


    ptr->addMessage(mess1);
    ptr->addMessage(mess2);
    ptr->addMessage(mess3);

    ptr->addMessage(mess10);
    ptr->addMessage(mess11);
    ptr->addMessage(mess21);

    ptr->addMessage(mess12);
    ptr->addMessage(mess13);


    ptrG->addMessage(mess4);
    ptrG->addMessage(mess5);


    ptr->readChat();

    Leo.removeChat(ptr, Filippo);
    Leo.removeChat(ptrG, Giuseppe);

    sleep(2);
    Leo.activeChat();
    Filippo.activeChat();
    Giuseppe.activeChat();
    sleep(2);

    if(ptr != NULL) {
        ptr->readChat();
    }
    if(ptrG != NULL) {
        ptrG->readChat();
    }


    sleep(2);
    std::shared_ptr<Chat> ptrG1 = Giuseppe.createChat(Leo);
    std::shared_ptr<Chat> ptr1 = Filippo.createChat(Leo);
    std::shared_ptr<Chat> ptr2 = Filippo.createChat(Giuseppe);
    ptrG1->addMessage(mess5);
    ptrG1->readChat();
    sleep(2);
    Leo.activeChat();
    Filippo.activeChat();
    Giuseppe.activeChat();

    return 0;
}
