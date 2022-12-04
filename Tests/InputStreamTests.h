#pragma once
#include "gtest/gtest.h"
#include "../Lib/InputStream.h"

TEST(InputStream, stringstream){
    std::stringstream ss{"0 1     23 45"};
    auto stream = InputStream(ss);
    std::string word;
    int num;
    stream.is >> num;
    ASSERT_TRUE(num == 0);
    stream.is >> word;
    ASSERT_TRUE(word == "1");
    stream.is >> word;
    ASSERT_TRUE(word == "23");
    stream.is >> num;
    ASSERT_TRUE(num == 45);
}

//TODO tests for another istream
