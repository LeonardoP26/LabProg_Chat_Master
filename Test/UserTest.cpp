//
// Created by leona on 21/11/2022.
//

#include "gtest/gtest.h"
#include "../User.h"
#include "../Messaggio.h"
#include "../Chat.h"


TEST(UserChatTest, GenChat){
    User Leonardo("Leonardo");
    User Giovanni("Giovanni");
    Messaggio a("Leo", "Giovanni", "Ciao come stai");
    Messaggio b("Leonardo", "Giovanni", "Ciao come stai");

    std::shared_ptr<Chat> ptr = Leonardo.createChat(Giovanni);
    ptr->addMessage(b);

    EXPECT_THROW(ptr->addMessage(a),std::out_of_range);
    EXPECT_THROW(Leonardo.createChat(Giovanni),std::out_of_range);
}





TEST(UserChatTest, SpecMess) {
    User Leonardo("Leonardo");
    User Giovanni("Giovanni");
    Messaggio a("Leonardo", "Giovanni", "Ciao come stai");
    Messaggio b("Giovanni", "Leonardo", "Tutto bene");

    std::shared_ptr<Chat> ptr = Leonardo.createChat(Giovanni);
    ptr->addMessage(a);
    ptr->addMessage(b);

    Messaggio spec_mess = ptr->getMess(1);
    ASSERT_EQ(spec_mess.getSender(), "Leonardo");


    Messaggio spec_mess1 = ptr->getMess(2);
    ASSERT_EQ(spec_mess1.getSender(), "Giovanni");
}



TEST(UserChatTest, NumChats) {
    User Leonardo("Leonardo");
    User Giovanni("Giovanni");
    Messaggio a("Leonardo", "Giovanni", "Ciao come stai");
    Messaggio b("Giovanni", "Leonardo", "Tutto bene");

    std::shared_ptr<Chat> ptr = Leonardo.createChat(Giovanni);

    ASSERT_EQ(Leonardo.getNumChats(), 1);
    ASSERT_EQ(Giovanni.getNumChats(), 1);

    Leonardo.removeChat(ptr, Giovanni);

    ASSERT_EQ(Leonardo.getNumChats(), 0);
    ASSERT_EQ(Giovanni.getNumChats(), 0);
}




TEST(UserChatTest, NumMess) {
    User Leonardo("Leonardo");
    User Giovanni("Giovanni");
    Messaggio a("Leonardo", "Giovanni", "Ciao come stai");
    Messaggio b("Giovanni", "Leonardo", "Tutto bene");

    std::shared_ptr<Chat> ptr = Leonardo.createChat(Giovanni);
    ptr->addMessage(a);


    ASSERT_EQ(ptr->getNumMess(), 1);
}