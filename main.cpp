#include <iostream>
#include <unistd.h>
#include <memory>


#include "Chat.h"
#include "User.h"

int main() {
    User Leo("Leonardo");
    User Filippo("Filippo");



    std::shared_ptr<Chat> ptr = Leo.createChat(Filippo);



    Leo.activeChat();
    Leo.removeChat(Filippo);
    Leo.activeChat();

    return 0;
}
