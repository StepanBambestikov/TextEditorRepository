#pragma once
#include "gtest/gtest.h"
#include "../TextEditorLib/Creators.h"
#include <vector>


TEST(InsertCreator, validData){
    auto bufferPtr = std::make_shared<StringBuffer>();
    auto strPtr = std::make_shared<StringBuffer>("12345");

    auto creatorPtr = CommandCreator::createCreator( std::make_unique<InsertDTO>(StringBuffer("_insert_me_"), 2));
    auto commandObj = creatorPtr->createCommand();

    commandObj->redo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "12_insert_me_345");
    commandObj->undo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "12345");
}

TEST(DeleteCreator, validData){
    auto bufferPtr = std::make_shared<StringBuffer>();
    auto strPtr = std::make_shared<StringBuffer>("12345");

    auto creatorPtr = CommandCreator::createCreator( std::make_unique<DeleteDTO>(1, 3) );
    auto commandObj = creatorPtr->createCommand();

    commandObj->redo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "145");
    commandObj->undo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "12345");
}

TEST(CopyCreator, validData){
    auto bufferPtr = std::make_shared<StringBuffer>("44444444444");
    auto strPtr = std::make_shared<StringBuffer>("12345");

    auto creatorPtr = CommandCreator::createCreator( std::make_unique<CopyDTO>(1, 3) );
    auto commandObj = creatorPtr->createCommand();

    commandObj->redo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "12345");
    commandObj->undo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "12345");
}

TEST(PasteCreator, validData){
    auto bufferPtr = std::make_shared<StringBuffer>("_1_");
    auto strPtr = std::make_shared<StringBuffer>("12345");

    auto creatorPtr = CommandCreator::createCreator( std::make_unique<PasteDTO>(1) );
    auto commandObj = creatorPtr->createCommand();

    commandObj->redo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "1_1_2345");
    commandObj->undo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "12345");
}

TEST(UndoCreator, validData){
    auto bufferPtr = std::make_shared<StringBuffer>();
    auto strPtr = std::make_shared<StringBuffer>("12345");

    auto creatorPtr = CommandCreator::createCreator( std::make_unique<UndoDTO>() );
    auto commandObj = creatorPtr->createCommand();

    commandObj->redo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "12345");
    commandObj->undo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "12345");
}

TEST(RedoCreator, validData){
    auto bufferPtr = std::make_shared<StringBuffer>();
    auto strPtr = std::make_shared<StringBuffer>("12345");

    auto creatorPtr = CommandCreator::createCreator( std::make_unique<RedoDTO>() );
    auto commandObj = creatorPtr->createCommand();

    commandObj->redo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "12345");
    commandObj->undo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "12345");
}

TEST(CopyAndPasteCreators, validData){
    auto bufferPtr = std::make_shared<StringBuffer>();
    auto strPtr = std::make_shared<StringBuffer>("12345");
    auto copyPtr = CommandCreator::createCreator(std::make_unique<CopyDTO>(1, 3));
    auto pastePtr = CommandCreator::createCreator(std::make_unique<PasteDTO>(2));
    auto copyObjPtr = copyPtr->createCommand();
    auto pasteObjPtr = pastePtr->createCommand();
    copyObjPtr->redo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "12345");
    ASSERT_TRUE(bufferPtr->getString() == "23");
    pasteObjPtr->redo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "1223345");
    pasteObjPtr->undo(strPtr, bufferPtr);
    ASSERT_TRUE(strPtr->getString() == "12345");
}