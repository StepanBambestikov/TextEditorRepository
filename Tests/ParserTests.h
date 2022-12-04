#pragma once
#include "gtest/gtest.h"
#include "../TextEditorLib/Parser.h"

TEST(Parser, amountOfStrings){
    InputStream stream(std::make_unique<std::stringstream>("1 2\n5 word\n 9 10 \n"));
    Parser p(stream);
    ASSERT_FALSE(p.eof());
    size_t count = 1;
    int a, b;
    std::string word;

    auto string = p.getStringStream();
    *string.is >> a;
    *string.is >> b;
    ASSERT_TRUE(a == 1);
    ASSERT_TRUE(b == 2);

    string = p.getStringStream();
    *string.is >> a;
    *string.is >> word;
    ASSERT_TRUE(a == 5);
    ASSERT_TRUE(word == "word");

    string = p.getStringStream();
    *string.is >> a;
    *string.is >> b;
    ASSERT_TRUE(a == 9);
    ASSERT_TRUE(b == 10);

    string = p.getStringStream();
    ASSERT_TRUE(p.eof());
}