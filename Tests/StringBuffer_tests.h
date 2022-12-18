#pragma once
#include "gtest/gtest.h"
#include "../TextEditorLib/StringBuffer.h"

TEST(StringBuffer, Constructor){
    ASSERT_NO_THROW( StringBuffer("some types") );
}

TEST(StringBuffer, AverageGetStringInRange){
    std::string str = "1234567890";
    auto buf = StringBuffer(str);
    auto subStr = buf.getSubStringInRange(1, 4);
    ASSERT_TRUE(subStr.getString() == "234");
    EXPECT_NO_THROW(buf.getSubStringInRange(3, 3));
    ASSERT_TRUE(buf.getSubStringInRange(3, 3).getString() == "");
}

TEST(StringBuffer, GetStringInRangeVoidString){
    std::string str = "";
    auto buf = StringBuffer(str);
    EXPECT_THROW(auto subStr = buf.getSubStringInRange(1, 4), IncorrectArgumentsGetStringInRange);
    auto subStr = buf.getSubStringInRange(0, 0);
    EXPECT_THROW(subStr = buf.getSubStringInRange(1, 0), IncorrectArgumentsGetStringInRange);
}

TEST(StringBuffer, GetStringInRangeAllRanges){
    std::string str = "12345";
    auto buf = StringBuffer(str);
    auto subStr = buf.getSubStringInRange(0, 5);
    ASSERT_TRUE(subStr.getString() == "12345");
    subStr = buf.getSubStringInRange(0, 4);
    ASSERT_TRUE(subStr.getString() == "1234");
    subStr = buf.getSubStringInRange(0, 3);
    ASSERT_TRUE(subStr.getString() == "123");
    subStr = buf.getSubStringInRange(0, 2);
    ASSERT_TRUE(subStr.getString() == "12");
    subStr = buf.getSubStringInRange(0, 1);
    ASSERT_TRUE(subStr.getString() == "1");
    subStr = buf.getSubStringInRange(0, 0);
    ASSERT_TRUE(subStr.getString() == "");

    EXPECT_THROW(auto subStr2 = buf.getSubStringInRange(-1, 5), IncorrectArgumentsGetStringInRange);
    subStr = buf.getSubStringInRange(0, 5);
    ASSERT_TRUE(subStr.getString() == "12345");
    subStr = buf.getSubStringInRange(1, 5);
    ASSERT_TRUE(subStr.getString() == "2345");
    subStr = buf.getSubStringInRange(2, 5);
    ASSERT_TRUE(subStr.getString() == "345");
    subStr = buf.getSubStringInRange(3, 5);
    ASSERT_TRUE(subStr.getString() == "45");
    subStr = buf.getSubStringInRange(4, 5);
    ASSERT_TRUE(subStr.getString() == "5");
    subStr = buf.getSubStringInRange(5, 5);
    ASSERT_TRUE(subStr.getString() == "");
}

TEST(StringBuffer, AveragePasteInPosition){
    std::string str = "1234567890";
    auto buf = StringBuffer(str);
    buf.pasteInPosition(4, StringBuffer("_00_"));
    ASSERT_TRUE(buf.getString() == "1234_00_567890");
    EXPECT_THROW(buf.pasteInPosition(15, StringBuffer(" ")), IncorrectArgumentsPasteInPosition);
}

TEST(StringBuffer, PasteInPositionInEveryPosition){
    std::string str = "123";
    auto buf = StringBuffer(str);
    EXPECT_THROW(buf.pasteInPosition(-1, StringBuffer("_")), IncorrectArgumentsPasteInPosition);
    buf.pasteInPosition(0, StringBuffer("_"));
    ASSERT_TRUE(buf.getString() == "_123");
    buf = StringBuffer(str);
    buf.pasteInPosition(1, StringBuffer("_"));
    ASSERT_TRUE(buf.getString() == "1_23");
    buf = StringBuffer(str);
    buf.pasteInPosition(2, StringBuffer("_"));
    ASSERT_TRUE(buf.getString() == "12_3");
    buf = StringBuffer(str);
    buf.pasteInPosition(3, StringBuffer("_"));
    ASSERT_TRUE(buf.getString() == "123_");
    buf = StringBuffer(str);
    EXPECT_THROW(buf.pasteInPosition(4, StringBuffer("_")), IncorrectArgumentsPasteInPosition);
}

TEST(StringBuffer, AverageDeleteStringInRange){
    std::string str = "1234567890";
    auto buf = StringBuffer(str);
    buf.deleteStringInRange(1, 4);
    ASSERT_TRUE(buf.getString() == "1567890");
}

TEST(StringBuffer, DeleteStringInRangeSomeRanges){
    std::string str = "123";
    auto buf = StringBuffer(str);
    buf.deleteStringInRange(0, 3);
    ASSERT_TRUE(buf.getString() == "");
    buf = StringBuffer(str);
    buf.deleteStringInRange(0, 2);
    ASSERT_TRUE(buf.getString() == "3");
    buf = StringBuffer(str);
    buf.deleteStringInRange(0, 1);
    ASSERT_TRUE(buf.getString() == "23");
    buf = StringBuffer(str);
    buf.deleteStringInRange(0, 0);
    ASSERT_TRUE(buf.getString() == "123");
    EXPECT_THROW(buf.deleteStringInRange(-1, 3), IncorrectArgumentsdeleteStringInRange);
    buf = StringBuffer(str);
    buf.deleteStringInRange(0, 3);
    ASSERT_TRUE(buf.getString() == "");
    buf = StringBuffer(str);
    buf.deleteStringInRange(1, 3);
    ASSERT_TRUE(buf.getString() == "1");
    buf = StringBuffer(str);
    buf.deleteStringInRange(2, 3);
    ASSERT_TRUE(buf.getString() == "12");
    buf = StringBuffer(str);
    buf.deleteStringInRange(3, 3);
    ASSERT_TRUE(buf.getString() == "123");
}