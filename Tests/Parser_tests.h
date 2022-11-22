#pragma once

#include "../TextEditorLib/Parser.h"
#include "gtest/gtest.h"
#include <sstream>

TEST(Parser, ordinaryString){
    std::istringstream strIn("one two three four");
    Parser p(strIn);
    ASSERT_FALSE(p.eof());
    auto splitString = p.getSplitString().value();
    ASSERT_TRUE(splitString[0] == "one");
    ASSERT_TRUE(splitString[1] == "two");
    ASSERT_TRUE(splitString[2] == "three");
    ASSERT_TRUE(splitString[3] == "four");
}

TEST(Parser, amountOfStrings){
    std::istringstream strIn("1 2\n5 6\n 9 10 \n");
    Parser p(strIn);
    ASSERT_FALSE(p.eof());
    size_t count = 1;
    auto splitString = p.getSplitString().value();
    ASSERT_TRUE(splitString.size() == 2);
    ASSERT_TRUE(splitString[0] == "1");
    ASSERT_TRUE(splitString[1] == "2");
    splitString = p.getSplitString().value();
    ASSERT_TRUE(splitString.size() == 2);
    ASSERT_TRUE(splitString[0] == "5");
    ASSERT_TRUE(splitString[1] == "6");
    splitString = p.getSplitString().value();
    ASSERT_TRUE(splitString.size() == 3);
    ASSERT_TRUE(splitString[0].empty());
    ASSERT_TRUE(splitString[1] == "9");
    ASSERT_TRUE(splitString[2] == "10");
}


TEST(Parser, voidString){
    std::istringstream strIn("");
    Parser p(strIn);
    ASSERT_FALSE(p.eof());
    auto splitString = p.getSplitString().value();
    ASSERT_TRUE(splitString.empty());
}

TEST(Parser, twoSpaces){
    std::istringstream strIn(" ");
    Parser p(strIn);
    ASSERT_FALSE(p.eof());
    auto splitString = p.getSplitString().value();
    ASSERT_TRUE(splitString[0].empty());
}