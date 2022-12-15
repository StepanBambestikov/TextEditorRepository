#pragma once
#include "gtest/gtest.h"
#include "../TextEditorLib/StringEditor.h"
#include "../TextEditorLib/Commands.h"


TEST(StringEditor, OrdinaryCommands){
    auto str = std::make_shared<StringBuffer>("12345");
    auto insertCmd = std::make_unique<Insert>(StringBuffer("_insert_me_"), 2);
    auto deleteCmd = std::make_unique<Delete>(1, 5);
    auto copyCmd = std::make_unique<Copy>(1, 5);
    auto pasteCmd = std::make_unique<Paste>(3);

    StringEditor editor{str};
    editor.addAndExecuteCommand(std::move(insertCmd));
    ASSERT_TRUE(str->getString() == "12_insert_me_345");
    editor.tryUndo();
    ASSERT_TRUE(str->getString() == "12345");
    editor.tryRedo();
    ASSERT_TRUE(str->getString() == "12_insert_me_345");
    editor.addAndExecuteCommand(std::move(deleteCmd));
    ASSERT_TRUE(str->getString() == "1sert_me_345");
    editor.tryUndo();
    ASSERT_TRUE(str->getString() == "12_insert_me_345");
    editor.tryUndo();
    ASSERT_TRUE(str->getString() == "12345");
    editor.tryRedo();
    ASSERT_TRUE(str->getString() == "12_insert_me_345");
    editor.addAndExecuteCommand(std::move(copyCmd));
    ASSERT_TRUE(str->getString() == "12_insert_me_345");
    editor.addAndExecuteCommand(std::move(pasteCmd));
    ASSERT_TRUE(str->getString() == "12_2_ininsert_me_345");
    editor.tryUndo();
    ASSERT_TRUE(str->getString() == "12_insert_me_345");
    editor.tryRedo();
    ASSERT_TRUE(str->getString() == "12_2_ininsert_me_345");
}

TEST(StringEditor, TooManyUndo){
    auto str = std::make_shared<StringBuffer>("12345");
    auto insertCmd = std::make_unique<Insert>(StringBuffer("_insert_me_"), 2);

    StringEditor editor(str);
    editor.addAndExecuteCommand(std::move(insertCmd));
    ASSERT_TRUE(str->getString() == "12_insert_me_345");
    editor.tryUndo();
    ASSERT_TRUE(str->getString() == "12345");
    EXPECT_THROW(editor.tryUndo(), UndoEditorException);
}

TEST(StringEditor, Undo){
    auto str = std::make_shared<StringBuffer>("123");
    auto insertCmd1 = std::make_unique<Insert>(StringBuffer("_insert_me_"), 1);
    auto insertCmd2 = std::make_unique<Insert>(StringBuffer("_insert_me_"), 2);

    StringEditor editor{str};
    editor.addAndExecuteCommand(std::move(insertCmd1));
    editor.tryUndo();
    editor.addAndExecuteCommand(std::move(insertCmd2));
    editor.tryUndo();
    EXPECT_THROW(editor.tryUndo(), UndoEditorException);
}
