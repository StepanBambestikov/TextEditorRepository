#pragma once
#include "gtest/gtest.h"
#include "../TextEditorLib/Creators.h"
#include <vector>

using IterType = std::vector<std::string>::iterator;

TEST(Creator, invalidName){
    auto bufferPtr = std::make_shared<StringBuffer>();
    auto strPtr = std::make_shared<StringBuffer>("12345");
    std::vector<std::string> args{"almost_insert", "_insert_me_", "dont_number"};
    EXPECT_THROW(CommandCreator<IterType>::createCreator(args.begin(), args.end()), IncorrectArgumentsInCreateCreator);
}

TEST(InsertCreator, validData){
    auto bufferPtr = std::make_shared<StringBuffer>();
    auto strPtr = std::make_shared<StringBuffer>("12345");
    std::vector<std::string> args{"insert", "_insert_me_", "2"};
    auto creatorPtr = CommandCreator<IterType>::createCreator(args.begin(), args.end());
    ASSERT_TRUE(creatorPtr->getValidity());
    auto commandObj = creatorPtr->createCommand(strPtr, bufferPtr);

    commandObj->redo();
    ASSERT_TRUE(strPtr->getString() == "12_insert_me_345");
    commandObj->undo();
    ASSERT_TRUE(strPtr->getString() == "12345");
}

TEST(InsertCreator, invalidArgs){
    auto bufferPtr = std::make_shared<StringBuffer>();
    auto strPtr = std::make_shared<StringBuffer>("12345");
    std::vector<std::string> args{"insert", "_insert_me_", "dont_number"};
    auto creatorPtr = CommandCreator<IterType>::createCreator(args.begin(), args.end());
    ASSERT_FALSE(creatorPtr->getValidity());
}


TEST(DeleteCreator, validData){
    auto bufferPtr = std::make_shared<StringBuffer>();
    auto strPtr = std::make_shared<StringBuffer>("12345");
    std::vector<std::string> args{"delete", "1", "3"};
    auto creatorPtr = CommandCreator<IterType>::createCreator(args.begin(), args.end());
    ASSERT_TRUE(creatorPtr->getValidity());
    auto commandObj = creatorPtr->createCommand(strPtr, bufferPtr);

    commandObj->redo();
    ASSERT_TRUE(strPtr->getString() == "145");
    commandObj->undo();
    ASSERT_TRUE(strPtr->getString() == "12345");
}

TEST(InsertCreator, invalidArgCount){
    auto strPtr = std::make_shared<StringBuffer>("12345");
    std::vector<std::string> args{"delete", "1"};
    args.emplace_back("delete");
    auto creatorPtr = CommandCreator<IterType>::createCreator(args.begin(), args.end());
    ASSERT_FALSE(creatorPtr->getValidity());
}

TEST(CopyCreator, validData){
    auto bufferPtr = std::make_shared<StringBuffer>();
    auto strPtr = std::make_shared<StringBuffer>("12345");
    std::vector<std::string> args{"copy", "1", "3"};
    auto creatorPtr = CommandCreator<IterType>::createCreator(args.begin(), args.end());
    ASSERT_TRUE(creatorPtr->getValidity());
    auto commandObj = creatorPtr->createCommand(strPtr, bufferPtr);
    commandObj->redo();
    ASSERT_TRUE(strPtr->getString() == "12345");
    commandObj->undo();
    ASSERT_TRUE(strPtr->getString() == "12345");
}

TEST(CopyCreator, invalidArgs){
    auto bufferPtr = std::make_shared<StringBuffer>();
    auto strPtr = std::make_shared<StringBuffer>("12345");
    std::vector<std::string> args{"copy","_insert_me_", "4"};
    auto creatorPtr = CommandCreator<IterType>::createCreator(args.begin(), args.end());
    ASSERT_FALSE(creatorPtr->getValidity());
    EXPECT_ANY_THROW(creatorPtr->createCommand(strPtr, bufferPtr));
}

TEST(PasteCreator, validData){
    auto bufferPtr = std::make_shared<StringBuffer>();
    auto strPtr = std::make_shared<StringBuffer>("12345");
    std::vector<std::string> args{"paste","2"};
    auto creatorPtr = CommandCreator<IterType>::createCreator(args.begin(), args.end());
    ASSERT_TRUE(creatorPtr->getValidity());
    auto commandObj = creatorPtr->createCommand(strPtr, bufferPtr);
    commandObj->redo();
    ASSERT_TRUE(strPtr->getString() == "12345");
    commandObj->undo();
    ASSERT_TRUE(strPtr->getString() == "12345");
}

TEST(PasteCreator, invalidArgs){
    auto bufferPtr = std::make_shared<StringBuffer>();
    auto strPtr = std::make_shared<StringBuffer>("12345");
    std::vector<std::string> args{"paste","_insert_me_", "4"};
    auto creatorPtr = CommandCreator<IterType>::createCreator(args.begin(), args.end());
    ASSERT_FALSE(creatorPtr->getValidity());
    EXPECT_ANY_THROW(creatorPtr->createCommand(strPtr, bufferPtr));
}

TEST(CopyAndPasteCreators, validData){
    auto bufferPtr = std::make_shared<StringBuffer>();
    auto strPtr = std::make_shared<StringBuffer>("12345");
    std::vector<std::string> copyArgs{"copy", "1", "3"};
    std::vector<std::string> pasteArgs{"paste", "2"};
    auto copyPtr = CommandCreator<IterType>::createCreator(copyArgs.begin(), copyArgs.end());
    auto pastePtr = CommandCreator<IterType>::createCreator(pasteArgs.begin(), pasteArgs.end());
    auto copyObjPtr = copyPtr->createCommand(strPtr, bufferPtr);
    auto pasteObjPtr = pastePtr->createCommand(strPtr, bufferPtr);
    copyObjPtr->redo();
    ASSERT_TRUE(strPtr->getString() == "12345");
    ASSERT_TRUE(bufferPtr->getString() == "23");
    pasteObjPtr->redo();
    ASSERT_TRUE(strPtr->getString() == "1223345");
    pasteObjPtr->undo();
    ASSERT_TRUE(strPtr->getString() == "12345");
}
