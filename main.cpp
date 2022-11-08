#include <iostream>
#include <unistd.h>
#include <memory>


#include "Chat.h"
#include "User.h"
#include "Messaggio.h"
#include "MessageNotification.h"

int main() {
    User Leo("Leonardo");
    User Filippo("Filippo");
    User Giuseppe("Giuseppe");

/*


    std::shared_ptr<Chat> ptr = Leo.createChat(Filippo);
    std::shared_ptr<Chat> ptr1 = Filippo.createChat(Leo);
    std::shared_ptr<Chat> ptrG = Giuseppe.createChat(Leo);
    Leo.activeChat();
    Filippo.activeChat();
    Giuseppe.activeChat();


    Messaggio mess1("Leonardo", "Filippo", "Ciao");
    Messaggio mess2("Filippo", "Leonardo" , "Ciao anche a te");
    Messaggio mess3("Filippo", "Leonardo" , "Tutto bene?");
    Messaggio mess5("Leonardo", "Filippo" , "Tuttasdne?");

    Messaggio mess4("Giuseppe", "Leonardo", "we");
    Messaggio mess6("Leonardo", "Giuseppe", "ciaone");





    ptrG->addMessage(mess4);
    ptrG->addMessage(mess6);


    sleep(1);
    ptr->addMessage(mess1);
    ptr->addMessage(mess2);

    sleep(2);
    ptr->addMessage(mess3);
    ptr->addMessage(mess5);


    sleep(2);
    ptr->readChat();
    ptrG->readChat();
    ptr1->readChat();



    Leo.removeChat(ptr, Filippo);

    ptr->readChat();

    Leo.activeChat();
    Giuseppe.activeChat();
    Filippo.activeChat();
*/



    std::shared_ptr<Chat> ptr = Leo.createChat(Filippo);
    std::shared_ptr<Chat> ptr1 = Filippo.createChat(Leo);
    std::shared_ptr<Chat> ptrG = Giuseppe.createChat(Leo);
    Leo.activeChat();
    Filippo.activeChat();
    Giuseppe.activeChat();


    Messaggio mess1("Leonardo", "Filippo", "Ciao");
    Messaggio mess2("Filippo", "Leonardo" , "Ciao anche a te");

    Messaggio mess3("Giuseppe", "Leonardo" , "Tutto bene?");
    Messaggio mess5("Leonardo", "Giuseppe" , "Si");

    ptr->addMessage(mess1);
    ptr->addMessage(mess2);

    ptrG->addMessage(mess3);
    ptrG->addMessage(mess5);

    Leo.removeChat(ptr, Filippo);
    //ptr->addMessage(mess1);
    //ptr->addMessage(mess2);
    //TODO togliere addMessage se chat cancellata, o comunque rifare attach per notifiche
    ptr->readChat();
    ptrG->readChat();
    ptr1->readChat();

    return 0;
}
