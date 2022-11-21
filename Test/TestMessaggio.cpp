//
// Created by leona on 14/11/2022.
//
#include "gtest/gtest.h"
#include "../Messaggio.h"

TEST(TestMessaggio,CostruttoreMessaggio){
    Messaggio m("Leonardo","Filippo","ciao");

    ASSERT_EQ("Leonardo",m.getSender());
    ASSERT_EQ("Filippo",m.getReceiver());
    ASSERT_EQ(false,m.isVisual());
    ASSERT_EQ("ciao",m.getText());
}