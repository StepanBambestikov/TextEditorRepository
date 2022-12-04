#pragma once
#include "gtest/gtest.h"
#include "../TextEditorLib/CommandListExecutor.h"

TEST(CommandListExecutor, averageData){
    auto str = StringBuffer("12345");
    InputStream strIn(std::make_unique<std::stringstream>(
            "insert _insert_me_ 2\nundo\n\nredo\ndelete 1 5\nundo\nundo\nredo\n\ncopy 1 5\npaste 3\nundo\nredo"));
    auto parsePtr = std::make_unique<Parser>(strIn);
    auto dtoProviderPtr = std::make_unique<DTOProviderFromParser>(std::move(parsePtr));
    auto creatorProviderPtr = std::make_unique<CreatorProviderFromDTO>(std::move(dtoProviderPtr));
    auto commandProviderPtr = std::make_unique<CommandProviderFromCreator>(std::move(creatorProviderPtr));

    CommandListExecutor executor(std::move(commandProviderPtr), str);
    auto changedStr = executor.runAllAndGetString();
    ASSERT_TRUE(changedStr.getString() == "12_2_ininsert_me_345");
}

TEST(CommandListExecutor, correctOnlyInsert){
    auto str = StringBuffer("12345");
    InputStream strIn(std::make_unique<std::stringstream>(
            "insert _insert_me_ 2\n\nre do\n        \nrdo\n"));
    auto parsePtr = std::make_unique<Parser>(strIn);
    auto dtoProviderPtr = std::make_unique<DTOProviderFromParser>(std::move(parsePtr));
    auto creatorProviderPtr = std::make_unique<CreatorProviderFromDTO>(std::move(dtoProviderPtr));
    auto commandProviderPtr = std::make_unique<CommandProviderFromCreator>(std::move(creatorProviderPtr));

    CommandListExecutor executor(std::move(commandProviderPtr), str);
    auto changedStr = executor.runAllAndGetString();
    ASSERT_TRUE(changedStr.getString() == "12_insert_me_345");
}

TEST(CommandListExecutor, oneIncorrect){
    auto str = StringBuffer("12345");
    InputStream strIn(std::make_unique<std::stringstream>(
            "insert _insert_me_ 2\n\nre do\nsfkgjf fdgfg dfg dfg dfg dfgfgfgfgfg\nundo\n"));
    Parser p(strIn);
    auto parsePtr = std::make_unique<Parser>(strIn);
    auto dtoProviderPtr = std::make_unique<DTOProviderFromParser>(std::move(parsePtr));
    auto creatorProviderPtr = std::make_unique<CreatorProviderFromDTO>(std::move(dtoProviderPtr));
    auto commandProviderPtr = std::make_unique<CommandProviderFromCreator>(std::move(creatorProviderPtr));

    CommandListExecutor executor(std::move(commandProviderPtr), str);
    auto changedStr = executor.runAllAndGetString();
    ASSERT_TRUE(changedStr.getString() == "12345");
}