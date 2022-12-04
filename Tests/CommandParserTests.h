#pragma once
#include "gtest/gtest.h"
#include "../TextEditorLib/CommandParser.h"

TEST(CommandParser, createDTOFail1){
    InputStream stream(std::make_unique<std::stringstream>("Cpy 2"));
    ASSERT_FALSE(parseStreamToDTO(std::move(stream)));
}

TEST(CommandParser, createDTOFail2){
    InputStream stream(std::make_unique<std::stringstream>(""));
    ASSERT_FALSE(parseStreamToDTO(std::move(stream)));
}

TEST(CommandParser, createCopyDTOSuccess){
    InputStream stream(std::make_unique<std::stringstream>("copy 1 2"));
    auto dtoPTR = parseStreamToDTO(std::move(stream));

    auto CDTOptr = dynamic_cast<CopyDTO*>(dtoPTR.get());
    ASSERT_TRUE(CDTOptr->getIdx1() == 1);
    ASSERT_TRUE(CDTOptr->getIdx2() == 2);
}

TEST(CommandParser, createCopyDTOFail){
    InputStream stream(std::make_unique<std::stringstream>("copy 2"));
    ASSERT_FALSE(parseStreamToDTO(std::move(stream)));
}

TEST(CommandParser, createPasteDTOSuccess){
    InputStream stream(std::make_unique<std::stringstream>("paste 1"));
    auto dtoPTR = parseStreamToDTO(std::move(stream));

    auto PDTOptr = dynamic_cast<PasteDTO*>(dtoPTR.get());
    ASSERT_TRUE(PDTOptr->getPosition() == 1);
}

TEST(CommandParser, createPasteDTOFail){
    InputStream stream(std::make_unique<std::stringstream>("paste error "));
    ASSERT_FALSE(parseStreamToDTO(std::move(stream)));
}

TEST(CommandParser, createInsertDTOSuccess){
    InputStream stream(std::make_unique<std::stringstream>("insert name 12"));
    auto dtoPTR = parseStreamToDTO(std::move(stream));

    auto IDTOptr = dynamic_cast<InsertDTO*>(dtoPTR.get());
    ASSERT_TRUE(IDTOptr->getPosition() == 12);
}

TEST(CommandParser, createInsertDTOFail){
    InputStream stream(std::make_unique<std::stringstream>("insert   2 "));
    ASSERT_FALSE(parseStreamToDTO(std::move(stream)));
}

TEST(CommandParser, createDeleteDTOSuccess){
    std::stringstream s{"Delete 1 4"};
    InputStream stream(std::make_unique<std::stringstream>("delete 1 4"));
    auto dtoPTR = parseStreamToDTO(std::move(stream));

    auto DDTOptr = dynamic_cast<DeleteDTO*>(dtoPTR.get());
    ASSERT_TRUE(DDTOptr->getIdx1() == 1);
    ASSERT_TRUE(DDTOptr->getIdx2() == 4);
}

TEST(CommandParser, createDeleteDTOFail){
    InputStream stream(std::make_unique<std::stringstream>("delete egdfpldfphl"));
    ASSERT_FALSE(parseStreamToDTO(std::move(stream)));
}

TEST(CommandParser, createUndoDTOSuccess){
    InputStream stream(std::make_unique<std::stringstream>("undo"));
    auto dtoPTR = parseStreamToDTO(std::move(stream));

    ASSERT_NO_THROW(auto DDTOptr = dynamic_cast<UndoDTO*>(dtoPTR.get()););
}

TEST(CommandParser, createRedoDTOSuccess){
    InputStream stream(std::make_unique<std::stringstream>("redo"));
    auto dtoPTR = parseStreamToDTO(std::move(stream));

    ASSERT_NO_THROW(auto DDTOptr = dynamic_cast<RedoDTO*>(dtoPTR.get()););
}