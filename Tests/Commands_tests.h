#pragma once
#include "../Commands.h"
#include "gtest/gtest.h"

TEST(Delete, constructor){
    auto strBufPtr = std::make_shared<StringBuffer>("df");
    ASSERT_NO_THROW(Delete(strBufPtr, 0, strBufPtr->size()));
}

TEST(Delete, redo_and_undo){
    auto strBufPtr = std::make_shared<StringBuffer>("12345");
    auto del = Delete(strBufPtr, 0, 2);
    del.redo();
    ASSERT_TRUE(strBufPtr->getString() == "345");
    del.undo();
    ASSERT_TRUE(strBufPtr->getString() == "12345");
}

TEST(Delete, incorrect_data){
    auto strBufPtr = std::make_shared<StringBuffer>("12345");
    auto del = Delete(strBufPtr, 0, 10);
    EXPECT_ANY_THROW(del.redo());
    ASSERT_TRUE(strBufPtr->getString() == "12345");
    del.undo();
    ASSERT_TRUE(strBufPtr->getString() == "12345");
}

TEST(Insert, constructor){
    auto strBufPtr = std::make_shared<StringBuffer>("12345");
    auto strBufPtrS = StringBuffer("12345");
    ASSERT_NO_THROW(Insert(strBufPtr,strBufPtrS, 2));
}

TEST(Insert, redo_and_undo){
    auto strBufPtr = std::make_shared<StringBuffer>("12345");
    auto strForInc = StringBuffer("_insert_me_");
    auto insertObj = Insert(strBufPtr, strForInc, 2);
    insertObj.redo();
    ASSERT_TRUE(strBufPtr->getString() == "12_insert_me_345");
    insertObj.undo();
    ASSERT_TRUE(strBufPtr->getString() == "12345");
}

TEST(Insert, incorrect_data){
    auto strBufPtr = std::make_shared<StringBuffer>("12345");
    auto strForInc = StringBuffer("_insert_me_");
    auto insertObj = Insert(strBufPtr, strForInc, 10 );
    EXPECT_ANY_THROW(insertObj.redo());
    ASSERT_TRUE(strBufPtr->getString() == "12345");
    insertObj.undo();
    ASSERT_TRUE(strBufPtr->getString() == "12345");
}

TEST(Copy, constructor){
    auto strBufPtr = std::make_shared<StringBuffer>("12345");
    auto bufPtr = std::make_shared<StringBuffer>();
    ASSERT_NO_THROW(Copy(strBufPtr, bufPtr, 0, 1) );
}

TEST(Paste, constructor){
    auto strBufPtr = std::make_shared<StringBuffer>("12345");
    auto bufPtr = std::make_shared<StringBuffer>();
    ASSERT_NO_THROW(Paste(strBufPtr, bufPtr, 0) );
}

TEST(Copy_and_paste, redo){
    auto strBufPtr = std::make_shared<StringBuffer>("12345");
    auto bufObj = std::make_shared<StringBuffer>();
    auto copyCmd = Copy(strBufPtr, bufObj, 0, 3);
    auto pasteCmd = Paste(strBufPtr, bufObj, 3);
    copyCmd.redo();
    ASSERT_TRUE(strBufPtr->getString() == "12345");
    ASSERT_TRUE(bufObj->getString() == "123");
    pasteCmd.redo();
    ASSERT_TRUE(strBufPtr->getString() == "12312345");
    pasteCmd.undo();
    ASSERT_TRUE(strBufPtr->getString() == "12345");
}

