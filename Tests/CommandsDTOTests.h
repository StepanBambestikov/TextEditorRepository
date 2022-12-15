#pragma once
#include "gtest/gtest.h"
#include "../TextEditorLib/CommandDTO.h"

TEST(CommandDTO, constructor){
    EXPECT_NO_THROW(auto dto = CommandDTO(Commands::COPY));
    EXPECT_NO_THROW(auto dto = CommandDTO(Commands::PASTE));
    EXPECT_NO_THROW(auto dto = CommandDTO(Commands::INSERT));
    EXPECT_NO_THROW(auto dto = CommandDTO(Commands::DELETE));
    EXPECT_NO_THROW(auto dto = CommandDTO(Commands::UNDO));
    EXPECT_NO_THROW(auto dto = CommandDTO(Commands::REDO));
}

TEST(CommandDTO, copyArgs){
    auto dto = CommandDTO(Commands::COPY);
    dto.setIdx1(1);
    dto.setIdx2(2);
    ASSERT_TRUE(dto.getIdx1() == 1);
    ASSERT_TRUE(dto.getIdx2() == 2);
    ASSERT_TRUE(dto.getCommandName() == Commands::COPY);
    ASSERT_FALSE(dto.getString());
}

TEST(CommandDTO, deleteArgs){
    auto dto = CommandDTO(Commands::DELETE);
    dto.setIdx1(1);
    dto.setIdx2(2);
    ASSERT_TRUE(dto.getIdx1() == 1);
    ASSERT_TRUE(dto.getIdx2() == 2);
    ASSERT_TRUE(dto.getCommandName() == Commands::DELETE);
    ASSERT_FALSE(dto.getString());
}

TEST(CommandDTO, insertArgs){
    auto dto = CommandDTO(Commands::INSERT);
    dto.setIdx1(1);
    dto.setString( StringBuffer{"smf"} );
    ASSERT_TRUE(dto.getIdx1() == 1);
    ASSERT_FALSE(dto.getIdx2());
    ASSERT_TRUE(dto.getCommandName() == Commands::INSERT);
    ASSERT_TRUE(dto.getString().value().getString() == "smf");
}

TEST(CommandDTO, pasteArgs){
    auto dto = CommandDTO(Commands::PASTE);
    dto.setIdx1(1);
    ASSERT_TRUE(dto.getIdx1() == 1);
    ASSERT_FALSE(dto.getIdx2());
    ASSERT_TRUE(dto.getCommandName() == Commands::PASTE);
    ASSERT_FALSE(dto.getString());
}

TEST(CommandDTO, undoArgs){
    auto dto = CommandDTO(Commands::UNDO);
    ASSERT_FALSE(dto.getIdx1());
    ASSERT_FALSE(dto.getIdx2());
    ASSERT_TRUE(dto.getCommandName() == Commands::UNDO);
    ASSERT_FALSE(dto.getString());
}

TEST(CommandDTO, redoArgs){
    auto dto = CommandDTO(Commands::REDO);
    ASSERT_FALSE(dto.getIdx1());
    ASSERT_FALSE(dto.getIdx2());
    ASSERT_TRUE(dto.getCommandName() == Commands::REDO);
    ASSERT_FALSE(dto.getString());
}
