#pragma once
#include "gtest/gtest.h"
#include "../TextEditorLib/Creators.h"
#include <vector>


TEST(InsertCreator, validData){
    auto bufferPtr = std::make_shared<StringBuffer>();
    auto strPtr = std::make_shared<StringBuffer>("12345");

    auto dto = std::make_unique<CommandDTO>(Commands::INSERT);
    dto->setString(StringBuffer("_insert_me_"));
    dto->setIdx1(2);
    auto creatorPtr = CommandCreator::createCreator(std::move(dto));
    auto commandObj = creatorPtr->tryCreateUserCommand();

    commandObj->redo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "12_insert_me_345");
    commandObj->undo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "12345");
}

TEST(DeleteCreator, validData){
    auto bufferPtr = std::make_shared<StringBuffer>();
    auto strPtr = std::make_shared<StringBuffer>("12345");

    auto dto = std::make_unique<CommandDTO>(Commands::DELETE);
    dto->setIdx1(1);
    dto->setIdx2(3);
    auto creatorPtr = CommandCreator::createCreator(std::move(dto));
    auto commandObj = creatorPtr->tryCreateUserCommand();

    commandObj->redo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "145");
    commandObj->undo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "12345");
}

TEST(CopyCreator, validData){
    auto bufferPtr = std::make_shared<StringBuffer>("44444444444");
    auto strPtr = std::make_shared<StringBuffer>("12345");

    auto dto = std::make_unique<CommandDTO>(Commands::COPY);
    dto->setIdx1(1);
    dto->setIdx2(3);
    auto creatorPtr = CommandCreator::createCreator(std::move(dto));
    auto commandObj = creatorPtr->tryCreateUserCommand();

    commandObj->redo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "12345");
    commandObj->undo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "12345");
}

TEST(PasteCreator, validData){
    auto bufferPtr = std::make_shared<StringBuffer>("_1_");
    auto strPtr = std::make_shared<StringBuffer>("12345");

    auto dto = std::make_unique<CommandDTO>(Commands::PASTE);
    dto->setIdx1(1);
    auto creatorPtr = CommandCreator::createCreator(std::move(dto));
    auto commandObj = creatorPtr->tryCreateUserCommand();

    commandObj->redo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "1_1_2345");
    commandObj->undo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "12345");
}

TEST(UndoCreator, validData){
    auto bufferPtr = std::make_shared<StringBuffer>();
    auto strPtr = std::make_shared<StringBuffer>("12345");

    auto dto = std::make_unique<CommandDTO>(Commands::UNDO);
    auto creatorPtr = CommandCreator::createCreator(std::move(dto));
    EXPECT_NO_THROW(auto commandObj = creatorPtr->tryCreateServiceCommand());
}

TEST(RedoCreator, validData){
    auto bufferPtr = std::make_shared<StringBuffer>();
    auto strPtr = std::make_shared<StringBuffer>("12345");

    auto dto = std::make_unique<CommandDTO>(Commands::REDO);
    auto creatorPtr = CommandCreator::createCreator(std::move(dto));

    EXPECT_NO_THROW(auto commandObj = creatorPtr->tryCreateServiceCommand());
}

TEST(CopyAndPasteCreators, validData){
    auto bufferPtr = std::make_shared<StringBuffer>();
    auto strPtr = std::make_shared<StringBuffer>("12345");
    auto copyDto = std::make_unique<CommandDTO>(Commands::COPY);
    copyDto->setIdx1(1);
    copyDto->setIdx2(3);
    auto copyPtr = CommandCreator::createCreator(std::move(copyDto));
    auto pasteDto = std::make_unique<CommandDTO>(Commands::PASTE);
    pasteDto->setIdx1(2);
    auto pastePtr = CommandCreator::createCreator(std::move(pasteDto));
    auto copyObjPtr = copyPtr->tryCreateUserCommand();
    auto pasteObjPtr = pastePtr->tryCreateUserCommand();
    copyObjPtr->redo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "12345");
    ASSERT_TRUE(bufferPtr->getString() == "23");
    pasteObjPtr->redo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "1223345");
    pasteObjPtr->undo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "12345");
}