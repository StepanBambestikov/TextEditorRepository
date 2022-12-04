#pragma once
#include "gtest/gtest.h"
#include "../TextEditorLib/InputStream.h"

TEST(InputStream, stringstream){
    auto stream = InputStream(std::make_unique<std::stringstream>("0 1     23 45"));
    std::string word;
    int num;
    *stream.is >> num;
    ASSERT_TRUE(num == 0);
    *stream.is >> word;
    ASSERT_TRUE(word == "1");
    *stream.is >> word;
    ASSERT_TRUE(word == "23");
    *stream.is >> num;
    ASSERT_TRUE(num == 45);
}

//TODO tests for another istream
