#pragma once
#include "gtest/gtest.h"
#include "../TextEditorLib/CommandListExecutor.h"

TEST(CommandListExecutor, averageData){
    auto str = StringBuffer("12345");
    std::istringstream strIn("insert _insert_me_ 2\nundo\nredo\ndelete 1 5\nundo\nundo\nredo\nredo\ncopy 1 5\npaste 3\nundo\nredo");
    Parser p(strIn);
    CommandListExecutor executor(p, str);
    auto changedStr = executor.runAllAndGetString();
    ASSERT_TRUE(changedStr.getString() == "12_2_ininsert_me_345");
}

TEST(CommandListExecutor, correctOnlyInsert){
    auto str = StringBuffer("12345");
    std::istringstream strIn("insert _insert_me_ 2\nre do\nrdo\n");
    Parser p(strIn);
    CommandListExecutor executor(p, str);
    auto changedStr = executor.runAllAndGetString();
    ASSERT_TRUE(changedStr.getString() == "12_insert_me_345");
}

TEST(CommandListExecutor, oneIncorrect){
    auto str = StringBuffer("12345");
    std::istringstream strIn("insert _insert_me_ 2\nre do\nundo\n");
    Parser p(strIn);
    CommandListExecutor executor(p, str);
    auto changedStr = executor.runAllAndGetString();
    ASSERT_TRUE(changedStr.getString() == "12345");
}