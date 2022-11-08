#include <iostream>
#include <unistd.h>
#include <memory>


#include "Chat.h"
#include "User.h"

int main() {
    User Leo("Leonardo");
    User Filippo("Filippo");
    User Giuseppe("Giuseppe");



    std::shared_ptr<Chat> ptr = Leo.createChat(Filippo);
    std::shared_ptr<Chat> ptrG = Leo.createChat(Giuseppe);
    Leo.activeChat();


    Messaggio mess1("Leonardo", "Filippo", "Ciao");
    Messaggio mess2("Filippo", "Leonardo" , "Ciao anche a te");
    Messaggio mess3("Filippo", "Leonardo" , "Tutto bene?");

    Messaggio mess4("Leonardo", "Giuseppe", "we");
    ptrG->addMessage(mess4);



    ptr->addMessage(mess1);
    ptr->addMessage(mess2);
    ptr->addMessage(mess3);


    ptr->unreadChats();

    ptr->readChat();
    ptr->unreadChats();
    ptrG->unreadChats();



    Leo.removeChat(Filippo);
    Leo.activeChat();

    return 0;
}
