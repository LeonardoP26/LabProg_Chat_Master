#include <unistd.h>
#include <memory>

#include "User.h"
#include "Messaggio.h"
#include "Chat.h"
#include "Display.h"

int main() {
    User Leo("Leonardo");
    User Filippo("Filippo");
    User Giuseppe("Giuseppe");


    std::shared_ptr<Chat> ptr = Leo.createChat(Filippo);
    std::shared_ptr<Chat> ptrG = Giuseppe.createChat(Leo);

    Leo.activeChat();
    Filippo.activeChat();
    Giuseppe.activeChat();


    Messaggio mess1("Leonardo", "Filippo", "Ciao");

    Messaggio mess2("Filippo", "Leonardo" , "Ciao anche a te");
    Messaggio mess3("Filippo", "Leonardo" , "Come va?");
    Messaggio mess4("Filippo", "Leonardo" , "Ci vediamo dopo?");

    Messaggio mess5("Leonardo", "Filippo", "Tutto bene. Certo a che ora?");
    Messaggio mess6("Leonardo", "Filippo", "Tutto bene. Certo 1");

    Messaggio mess7("Filippo", "Leonardo" , "Verso le 18?");

    Messaggio mess8("Leonardo", "Filippo", "Va bene");




    Messaggio mess11("Giuseppe", "Leonardo" , "Tutto bene?");
    Messaggio mess12("Leonardo", "Giuseppe" , "Si");

    readChat(ptr);
    ptr->addMessage(mess1);
    ptr->addMessage(mess2);
    ptr->addMessage(mess3);
    ptr->addMessage(mess4);
    ptr->addMessage(mess5);


    ptrG->addMessage(mess11);
    ptrG->addMessage(mess12);


    ptr->addMessage(mess6);
    ptr->addMessage(mess7);
    ptr->addMessage(mess8);

    readChat(ptr);


    Leo.removeChat(ptr, Filippo);
    Leo.removeChat(ptrG, Giuseppe);


    Leo.activeChat();
    Filippo.activeChat();
    Giuseppe.activeChat();


    readChat(ptr);

    std::shared_ptr<Chat> ptrG1 = Giuseppe.createChat(Leo);
    std::shared_ptr<Chat> ptr1 = Filippo.createChat(Leo);
    std::shared_ptr<Chat> ptr2 = Filippo.createChat(Giuseppe);
    ptrG1->addMessage(mess11);
    readChat(ptrG1);

    Leo.activeChat();
    Filippo.activeChat();
    Giuseppe.activeChat();

    return 0;
}
