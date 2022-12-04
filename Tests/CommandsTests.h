#pragma once
#include "../TextEditorLib/Commands.h"
#include "gtest/gtest.h"

TEST(Delete, constructor){
    auto strBufPtr = std::make_shared<StringBuffer>("df");
    ASSERT_NO_THROW(Delete(0, strBufPtr->size()));
}

TEST(Delete, redo_and_undo){
    auto strBufPtr = std::make_shared<StringBuffer>("12345");
    auto del = Delete(0, 2);
    del.redo(strBufPtr, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "345");
    del.undo(strBufPtr, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "12345");
}

TEST(Delete, incorrect_data){
    auto strBufPtr = std::make_shared<StringBuffer>("12345");
    auto del = Delete(0, 10);
    EXPECT_ANY_THROW(del.redo(strBufPtr, {{}}));
    ASSERT_TRUE(strBufPtr->getString() == "12345");
    del.undo(strBufPtr, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "12345");
}

TEST(Delete, VoidString){
    auto strBufPtr = std::make_shared<StringBuffer>("");
    EXPECT_ANY_THROW(Delete(0, 1).redo(strBufPtr, {{}}));
    auto del = Delete(0, 0);
    del.redo(strBufPtr, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "");
    del.undo(strBufPtr, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "");
}

TEST(Delete, DeleteSomeRanges){
    auto strBufPtr = std::make_shared<StringBuffer>("123");
    EXPECT_ANY_THROW(Delete(0, 4).redo(strBufPtr, {{}}));
    auto del = Delete(0, 3);
    del.redo(strBufPtr, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "");
    del.undo(strBufPtr, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "123");
    del = Delete(0, 1);
    del.redo(strBufPtr, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "23");
    del.undo(strBufPtr, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "123");
    del = Delete(0, 0);
    del.redo(strBufPtr, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "123");
    del.undo(strBufPtr, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "123");
    del = Delete(-1, 0);
    EXPECT_ANY_THROW(del.redo({strBufPtr}, {{}}));
}

TEST(Insert, constructor){
    auto strBufPtr = std::make_shared<StringBuffer>("12345");
    auto strBufPtrS = StringBuffer("12345");
    ASSERT_NO_THROW(Insert(strBufPtrS, 2));
}

TEST(Insert, redo_and_undo){
    auto strBufPtr = std::make_shared<StringBuffer>("12345");
    auto strForInc = StringBuffer("_insert_me_");
    auto insertObj = Insert(strForInc, 2);
    insertObj.redo({strBufPtr}, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "12_insert_me_345");
    insertObj.undo({strBufPtr}, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "12345");
}

TEST(Insert, IncorrectData){
    auto strBufPtr = std::make_shared<StringBuffer>("12345");
    auto strForInc = StringBuffer("_insert_me_");
    auto insertObj = Insert(strForInc, 10 );
    EXPECT_ANY_THROW(insertObj.redo(strBufPtr, {{}}));
    ASSERT_TRUE(strBufPtr->getString() == "12345");
    insertObj.undo(strBufPtr, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "12345");
}

TEST(Insert, VoidString){
    auto strBufPtr = std::make_shared<StringBuffer>("");
    auto strForInc = StringBuffer("_insert_me_");
    auto insertObj = Insert(strForInc, 1 );
    EXPECT_ANY_THROW(insertObj.redo(strBufPtr, {{}}));
    insertObj = Insert(strForInc, 0 );
    insertObj.redo(strBufPtr, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "_insert_me_");
    insertObj = Insert(strForInc, -1 );
    EXPECT_ANY_THROW(insertObj.redo(strBufPtr, {{}}));
}

TEST(Insert, SomePositions){
    auto strBufPtr = std::make_shared<StringBuffer>("123");
    auto strForInc = StringBuffer("_");
    auto insertObj = Insert(strForInc, -1);
    EXPECT_ANY_THROW(insertObj.redo(strBufPtr, {{}}));
    insertObj = Insert(strForInc, 0 );
    insertObj.redo(strBufPtr, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "_123");
    insertObj.undo(strBufPtr, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "123");
    insertObj = Insert(strForInc, 1 );
    insertObj.redo(strBufPtr, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "1_23");
    insertObj.undo(strBufPtr, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "123");
    insertObj = Insert(strForInc, 2 );
    insertObj.redo(strBufPtr, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "12_3");
    insertObj.undo(strBufPtr, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "123");
    insertObj = Insert(strForInc, 3 );
    insertObj.redo(strBufPtr, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "123_");
    insertObj.undo(strBufPtr, {{}});
    ASSERT_TRUE(strBufPtr->getString() == "123");
    insertObj = Insert(strForInc, 4 );
    EXPECT_ANY_THROW(insertObj.redo(strBufPtr, {{}}));
}

TEST(Copy, constructor){
    auto strBufPtr = std::make_shared<StringBuffer>("12345");
    auto bufPtr = std::make_shared<StringBuffer>();
    ASSERT_NO_THROW(Copy(0, 1) );
}

TEST(Paste, constructor){
    auto strBufPtr = std::make_shared<StringBuffer>("12345");
    auto bufPtr = std::make_shared<StringBuffer>();
    ASSERT_NO_THROW(Paste(0) );
}

TEST(Copy_and_paste, AverageData){
    auto strBufPtr = std::make_shared<StringBuffer>("12345");
    auto bufObj = std::make_shared<StringBuffer>();
    auto copyCmd = Copy(0, 3);
    auto pasteCmd = Paste(3);
    copyCmd.redo(strBufPtr, bufObj);
    ASSERT_TRUE(strBufPtr->getString() == "12345");
    ASSERT_TRUE(bufObj->getString() == "123");
    pasteCmd.redo(strBufPtr, bufObj);
    ASSERT_TRUE(strBufPtr->getString() == "12312345");
    pasteCmd.undo(strBufPtr, bufObj);
    ASSERT_TRUE(strBufPtr->getString() == "12345");
}
/*
TEST(Copy_and_paste, VoidString){
    auto strBufPtr = std::make_shared<StringBuffer>("");
    auto bufObj = std::make_shared<StringBuffer>();
    auto copyCmd = Copy(0, 0);
    auto pasteCmd = Paste(0);
    copyCmd.redo(strBufPtr, bufObj);
    ASSERT_TRUE(strBufPtr->getString() == "");
    pasteCmd.redo(strBufPtr, bufObj);
    ASSERT_TRUE(strBufPtr->getString() == "");
    pasteCmd.undo(strBufPtr, bufObj);
    ASSERT_TRUE(strBufPtr->getString() == "");

    pasteCmd = Paste(1);
    EXPECT_ANY_THROW(pasteCmd.redo(strBufPtr, bufObj);
    EXPECT_ANY_THROW(pasteCmd.undo(strBufPtr, bufObj);
}*/


TEST(Copy_and_paste, SomeRanges){
    auto strBufPtr = std::make_shared<StringBuffer>("123");
    auto bufObj = std::make_shared<StringBuffer>();
    auto copyCmd = Copy(0, 3);
    auto pasteCmd = Paste(-1);
    copyCmd.redo({strBufPtr}, bufObj);
    ASSERT_TRUE(strBufPtr->getString() == "123");
    EXPECT_ANY_THROW(pasteCmd.redo(strBufPtr, bufObj));
    EXPECT_ANY_THROW(pasteCmd.undo(strBufPtr, bufObj));
    pasteCmd = Paste(0);
    pasteCmd.redo(strBufPtr, bufObj);
    ASSERT_TRUE(strBufPtr->getString() == "123123");
    pasteCmd.undo(strBufPtr, bufObj);
    ASSERT_TRUE(strBufPtr->getString() == "123");

    pasteCmd = Paste(1);
    pasteCmd.redo(strBufPtr, bufObj);
    ASSERT_TRUE(strBufPtr->getString() == "112323");
    pasteCmd.undo(strBufPtr, bufObj);
    ASSERT_TRUE(strBufPtr->getString() == "123");

    pasteCmd = Paste(2);
    pasteCmd.redo(strBufPtr, bufObj);
    ASSERT_TRUE(strBufPtr->getString() == "121233");
    pasteCmd.undo(strBufPtr, bufObj);
    ASSERT_TRUE(strBufPtr->getString() == "123");

    pasteCmd = Paste(3);
    pasteCmd.redo(strBufPtr, bufObj);
    ASSERT_TRUE(strBufPtr->getString() == "123123");
    pasteCmd.undo(strBufPtr, bufObj);
    ASSERT_TRUE(strBufPtr->getString() == "123");
}