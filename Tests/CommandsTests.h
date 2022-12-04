#pragma once
#include "../TextEditorLib/Commands.h"
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

TEST(Delete, VoidString){
    auto strBufPtr = std::make_shared<StringBuffer>("");
    EXPECT_ANY_THROW(Delete(strBufPtr, 0, 1).redo());
    auto del = Delete(strBufPtr, 0, 0);
    del.redo();
    ASSERT_TRUE(strBufPtr->getString() == "");
    del.undo();
    ASSERT_TRUE(strBufPtr->getString() == "");
}

TEST(Delete, DeleteSomeRanges){
    auto strBufPtr = std::make_shared<StringBuffer>("123");
    EXPECT_ANY_THROW(Delete(strBufPtr, 0, 4).redo());
    auto del = Delete(strBufPtr, 0, 3);
    del.redo();
    ASSERT_TRUE(strBufPtr->getString() == "");
    del.undo();
    ASSERT_TRUE(strBufPtr->getString() == "123");
    del = Delete(strBufPtr, 0, 1);
    del.redo();
    ASSERT_TRUE(strBufPtr->getString() == "23");
    del.undo();
    ASSERT_TRUE(strBufPtr->getString() == "123");
    del = Delete(strBufPtr, 0, 0);
    del.redo();
    ASSERT_TRUE(strBufPtr->getString() == "123");
    del.undo();
    ASSERT_TRUE(strBufPtr->getString() == "123");
    del = Delete(strBufPtr, -1, 0);
    EXPECT_ANY_THROW(del.redo());
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

TEST(Insert, IncorrectData){
    auto strBufPtr = std::make_shared<StringBuffer>("12345");
    auto strForInc = StringBuffer("_insert_me_");
    auto insertObj = Insert(strBufPtr, strForInc, 10 );
    EXPECT_ANY_THROW(insertObj.redo());
    ASSERT_TRUE(strBufPtr->getString() == "12345");
    insertObj.undo();
    ASSERT_TRUE(strBufPtr->getString() == "12345");
}

TEST(Insert, VoidString){
    auto strBufPtr = std::make_shared<StringBuffer>("");
    auto strForInc = StringBuffer("_insert_me_");
    auto insertObj = Insert(strBufPtr, strForInc, 1 );
    EXPECT_ANY_THROW(insertObj.redo());
    insertObj = Insert(strBufPtr, strForInc, 0 );
    insertObj.redo();
    ASSERT_TRUE(strBufPtr->getString() == "_insert_me_");
    insertObj = Insert(strBufPtr, strForInc, -1 );
    EXPECT_ANY_THROW(insertObj.redo());
}

TEST(Insert, SomePositions){
    auto strBufPtr = std::make_shared<StringBuffer>("123");
    auto strForInc = StringBuffer("_");
    auto insertObj = Insert(strBufPtr, strForInc, -1);
    EXPECT_ANY_THROW(insertObj.redo());
    insertObj = Insert(strBufPtr, strForInc, 0 );
    insertObj.redo();
    ASSERT_TRUE(strBufPtr->getString() == "_123");
    insertObj.undo();
    ASSERT_TRUE(strBufPtr->getString() == "123");
    insertObj = Insert(strBufPtr, strForInc, 1 );
    insertObj.redo();
    ASSERT_TRUE(strBufPtr->getString() == "1_23");
    insertObj.undo();
    ASSERT_TRUE(strBufPtr->getString() == "123");
    insertObj = Insert(strBufPtr, strForInc, 2 );
    insertObj.redo();
    ASSERT_TRUE(strBufPtr->getString() == "12_3");
    insertObj.undo();
    ASSERT_TRUE(strBufPtr->getString() == "123");
    insertObj = Insert(strBufPtr, strForInc, 3 );
    insertObj.redo();
    ASSERT_TRUE(strBufPtr->getString() == "123_");
    insertObj.undo();
    ASSERT_TRUE(strBufPtr->getString() == "123");
    insertObj = Insert(strBufPtr, strForInc, 4 );
    EXPECT_ANY_THROW(insertObj.redo());
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

TEST(Copy_and_paste, AverageData){
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

TEST(Copy_and_paste, VoidString){
    auto strBufPtr = std::make_shared<StringBuffer>("");
    auto bufObj = std::make_shared<StringBuffer>();
    auto copyCmd = Copy(strBufPtr, bufObj, 0, 0);
    auto pasteCmd = Paste(strBufPtr, bufObj, 0);
    copyCmd.redo();
    ASSERT_TRUE(strBufPtr->getString() == "");
    pasteCmd.redo();
    ASSERT_TRUE(strBufPtr->getString() == "");
    pasteCmd.undo();
    ASSERT_TRUE(strBufPtr->getString() == "");

    pasteCmd = Paste(strBufPtr, bufObj, 1);
    EXPECT_ANY_THROW(pasteCmd.redo());
    EXPECT_ANY_THROW(pasteCmd.undo());
}

TEST(Copy_and_paste, SomeRanges){
    auto strBufPtr = std::make_shared<StringBuffer>("123");
    auto bufObj = std::make_shared<StringBuffer>();
    auto copyCmd = Copy(strBufPtr, bufObj, 0, 3);
    auto pasteCmd = Paste(strBufPtr, bufObj, -1);
    copyCmd.redo();
    ASSERT_TRUE(strBufPtr->getString() == "123");
    EXPECT_ANY_THROW(pasteCmd.redo());
    EXPECT_ANY_THROW(pasteCmd.undo());
    pasteCmd = Paste(strBufPtr, bufObj, 0);
    pasteCmd.redo();
    ASSERT_TRUE(strBufPtr->getString() == "123123");
    pasteCmd.undo();
    ASSERT_TRUE(strBufPtr->getString() == "123");

    pasteCmd = Paste(strBufPtr, bufObj, 1);
    pasteCmd.redo();
    ASSERT_TRUE(strBufPtr->getString() == "112323");
    pasteCmd.undo();
    ASSERT_TRUE(strBufPtr->getString() == "123");

    pasteCmd = Paste(strBufPtr, bufObj, 2);
    pasteCmd.redo();
    ASSERT_TRUE(strBufPtr->getString() == "121233");
    pasteCmd.undo();
    ASSERT_TRUE(strBufPtr->getString() == "123");

    pasteCmd = Paste(strBufPtr, bufObj, 3);
    pasteCmd.redo();
    ASSERT_TRUE(strBufPtr->getString() == "123123");
    pasteCmd.undo();
    ASSERT_TRUE(strBufPtr->getString() == "123");
}

