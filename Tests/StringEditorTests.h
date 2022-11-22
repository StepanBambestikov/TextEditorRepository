#pragma once
#include "gtest/gtest.h"
#include "../StringEditor.h"
#include "../Commands.h"


TEST(StringEditor, OrdinaryCommands){
    auto str = std::make_shared<StringBuffer>("12345");
    auto buf = std::make_shared<StringBuffer>();
    auto insertCmd = std::make_shared<Insert>(str, StringBuffer("_insert_me_"), 2);
    auto deleteCmd = std::make_shared<Delete>(str, 1, 5);
    auto copyCmd = std::make_shared<Copy>(str, buf, 1, 5);
    auto pasteCmd = std::make_shared<Paste>(str, buf, 3);

    StringEditor editor;
    editor.addAndExecuteCommand(insertCmd);
    ASSERT_TRUE(str->getString() == "12_insert_me_345");
    editor.undo();
    ASSERT_TRUE(str->getString() == "12345");
    editor.redo();
    ASSERT_TRUE(str->getString() == "12_insert_me_345");
    editor.addAndExecuteCommand(deleteCmd);
    ASSERT_TRUE(str->getString() == "1sert_me_345");
    editor.undo();
    ASSERT_TRUE(str->getString() == "12_insert_me_345");
    editor.undo();
    ASSERT_TRUE(str->getString() == "12345");
    editor.redo();
    ASSERT_TRUE(str->getString() == "12_insert_me_345");
    editor.redo();
    ASSERT_TRUE(str->getString() == "12_insert_me_345");
    editor.addAndExecuteCommand(copyCmd);
    ASSERT_TRUE(str->getString() == "12_insert_me_345");
    ASSERT_TRUE(buf->getString() == "2_in");
    editor.addAndExecuteCommand(pasteCmd);
    ASSERT_TRUE(str->getString() == "12_2_ininsert_me_345");
    editor.undo();
    ASSERT_TRUE(str->getString() == "12_insert_me_345");
    editor.redo();
    ASSERT_TRUE(str->getString() == "12_2_ininsert_me_345");
}

TEST(StringEditor, TooManyUndo){
    auto str = std::make_shared<StringBuffer>("12345");
    auto buf = std::make_shared<StringBuffer>();
    auto insertCmd = std::make_shared<Insert>(str, StringBuffer("_insert_me_"), 2);

    StringEditor editor;
    editor.addAndExecuteCommand(insertCmd);
    ASSERT_TRUE(str->getString() == "12_insert_me_345");
    editor.undo();
    ASSERT_TRUE(str->getString() == "12345");
    EXPECT_THROW(editor.undo(), UndoEditorException);
}
