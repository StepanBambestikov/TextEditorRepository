#pragma once
#include "gtest/gtest.h"
#include "../TextEditorLib/StringBuffer.h"

TEST(StringBuffer, constructor){
    ASSERT_NO_THROW( StringBuffer("some types") );
}

TEST(StringBuffer, getStringInRange){
    std::string str = "1234567890";
    auto buf = StringBuffer(str);
    auto subStr = buf.getStringInRange(1, 4);
    ASSERT_TRUE(subStr.getString() == "234");
    EXPECT_THROW(buf.getStringInRange(1, 20), IncorrectArgumentsGetStringInRange);
    EXPECT_NO_THROW(buf.getStringInRange(3, 3));
    ASSERT_TRUE(buf.getStringInRange(3, 3).getString() == "");
}

TEST(StringBuffer, pasteInPosition){
    std::string str = "1234567890";
    auto buf = StringBuffer(str);
    buf.pasteInPosition(4, StringBuffer("_00_"));
    ASSERT_TRUE(buf.getString() == "1234_00_567890");
    EXPECT_THROW(buf.pasteInPosition(15, StringBuffer(" ")), IncorrectArgumentsPasteInPosition);
}

TEST(StringBuffer, deleteStringInRange){
    std::string str = "1234567890";
    auto buf = StringBuffer(str);
    buf.deleteStringInRange(1, 4);
    ASSERT_TRUE(buf.getString() == "1567890");
    EXPECT_THROW(buf.deleteStringInRange(1, 20), IncorrectArgumentsdeleteStringInRange);
}