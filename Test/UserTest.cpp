//
// Created by leona on 21/11/2022.
//

#include "gtest/gtest.h"
#include "../User.h"


TEST(UserChatTest, Generico){
    User Leonardo("Leonardo");
    User Giovanni("Giovanni");
    Messaggio a("Leo", "Giovanni", "Ciao come stai");
    Messaggio b("Leonardo", "Giovanni", "Ciao come stai");

    std::shared_ptr<Chat> ptr = Leonardo.createChat(Giovanni);
    ptr->addMessage(b);

    EXPECT_THROW(ptr->addMessage(a),std::out_of_range);
    ASSERT_EQ(Leonardo.getNumChats(), 1);
    ASSERT_EQ(Giovanni.getNumChats(), 1);
    EXPECT_THROW(Leonardo.createChat(Giovanni),std::out_of_range);
    ASSERT_EQ(ptr->getNumMess(), 1);

    Leonardo.removeChat(ptr, Giovanni);
    ASSERT_EQ(Leonardo.getNumChats(), 0);
    ASSERT_EQ(Giovanni.getNumChats(), 0);
}
