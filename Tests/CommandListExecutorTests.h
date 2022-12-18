#pragma once
#include "gtest/gtest.h"
#include "../TextEditorLib/Parser.h"
#include "../TextEditorLib/DTOProviderFromParser.h"
#include "../TextEditorLib/CreatorProviderFromDTO.h"
#include "../TextEditorLib/CommandProviderFromCreator.h"
#include "../TextEditorLib/CommandListExecutor.h"

TEST(CommandListExecutor, averageData){
    auto strPtr = std::make_unique<StringBuffer>("12345");
    std::stringstream stream{"insert _insert_me_ 2\nundo\n\nredo\ndelete 1 5\nundo\nundo\nredo\n\ncopy 1 5\npaste 3\nundo\nredo"};

    auto parsePtr = std::make_unique<Parser>(stream);
    auto dtoProviderPtr = std::make_unique<DTOProviderFromParser>(std::move(parsePtr));
    auto creatorProviderPtr = std::make_unique<CreatorProviderFromDTO>(std::move(dtoProviderPtr));
    auto commandProviderPtr = std::make_unique<CommandProviderFromCreator>(std::move(creatorProviderPtr));

    auto editorPtr = std::make_unique<StringEditor>(std::move(strPtr));

    CommandListExecutor executor(std::move(commandProviderPtr));
    auto changedStr = executor.runAllAndGetString(std::move(editorPtr));
    ASSERT_TRUE(*changedStr == "12_2_ininsert_me_345");
}

TEST(CommandListExecutor, correctOnlyInsert){
    auto strPtr = std::make_unique<StringBuffer>("12345");
    std::stringstream strIn{"insert _insert_me_ 2\n\nre do\n        \nrdo\n"};
    auto parsePtr = std::make_unique<Parser>(strIn);
    auto dtoProviderPtr = std::make_unique<DTOProviderFromParser>(std::move(parsePtr));
    auto creatorProviderPtr = std::make_unique<CreatorProviderFromDTO>(std::move(dtoProviderPtr));
    auto commandProviderPtr = std::make_unique<CommandProviderFromCreator>(std::move(creatorProviderPtr));

    auto editorPtr = std::make_unique<StringEditor>(std::move(strPtr));

    CommandListExecutor executor(std::move(commandProviderPtr));
    auto changedStr = executor.runAllAndGetString(std::move(editorPtr));
    ASSERT_TRUE(*changedStr == "12_insert_me_345");
}

TEST(CommandListExecutor, oneIncorrect){
    auto strPtr = std::make_unique<StringBuffer>("12345");
    std::stringstream strIn{"insert _insert_me_ 2\n\nre do\nsfkgjf fdgfg dfg dfg dfg dfgfgfgfgfg\nundo\n"};
    Parser p(strIn);
    auto parsePtr = std::make_unique<Parser>(strIn);
    auto dtoProviderPtr = std::make_unique<DTOProviderFromParser>(std::move(parsePtr));
    auto creatorProviderPtr = std::make_unique<CreatorProviderFromDTO>(std::move(dtoProviderPtr));
    auto commandProviderPtr = std::make_unique<CommandProviderFromCreator>(std::move(creatorProviderPtr));

    auto editorPtr = std::make_unique<StringEditor>(std::move(strPtr));

    CommandListExecutor executor(std::move(commandProviderPtr));
    auto changedStr = executor.runAllAndGetString(std::move(editorPtr));
    ASSERT_TRUE(*changedStr == "12345");
}