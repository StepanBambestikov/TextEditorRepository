#pragma once
#include "gtest/gtest.h"
#include "../TextEditorLib/Parser.h"

TEST(Parser, createDTOFail1) {
    InputStream stream(std::make_unique<std::stringstream>("Cpy 2"));
    auto p = Parser(stream);
    ASSERT_FALSE(p.parseStringToDTO());
}

TEST(Parser, createDTOFail2){
    InputStream stream(std::make_unique<std::stringstream>(""));
    auto p = Parser(stream);
    ASSERT_FALSE(p.parseStringToDTO());
}

TEST(Parser, createCopyDTOSuccess){
    InputStream stream(std::make_unique<std::stringstream>("copy 1 2"));
    auto p = Parser(stream);
    auto dtoPTR = p.parseStringToDTO();

    ASSERT_TRUE(dtoPTR->getCommandName() == Commands::COPY);
    ASSERT_TRUE(dtoPTR->getIdx1() == 1);
    ASSERT_TRUE(dtoPTR->getIdx2() == 2);
}

TEST(Parser, createCopyDTOFail){
    InputStream stream(std::make_unique<std::stringstream>("copy 2"));
    auto p = Parser(stream);
    ASSERT_FALSE(p.parseStringToDTO());
}

TEST(Parser, createPasteDTOSuccess){
    InputStream stream(std::make_unique<std::stringstream>("paste 1"));
    auto p = Parser(stream);
    auto dtoPTR = p.parseStringToDTO();

    ASSERT_TRUE(dtoPTR->getCommandName() == Commands::PASTE);
    ASSERT_TRUE(dtoPTR->getIdx1() == 1);
}

TEST(Parser, createPasteDTOFail){
    InputStream stream(std::make_unique<std::stringstream>("paste error "));
    auto p = Parser(stream);
    ASSERT_FALSE(p.parseStringToDTO());
}

TEST(Parser, createInsertDTOSuccess){
    InputStream stream(std::make_unique<std::stringstream>("insert name 12"));
    auto p = Parser(stream);
    auto dtoPTR = p.parseStringToDTO();

    ASSERT_TRUE(dtoPTR->getCommandName() == Commands::INSERT);
    ASSERT_TRUE(dtoPTR->getIdx1() == 12);
}

TEST(Parser, createInsertDTOFail){
    InputStream stream(std::make_unique<std::stringstream>("insert   2 "));
    auto p = Parser(stream);
    ASSERT_FALSE(p.parseStringToDTO());
}

TEST(ParserParser, createDeleteDTOSuccess){
    std::stringstream s{"Delete 1 4"};
    InputStream stream(std::make_unique<std::stringstream>("delete 1 4"));
    auto p = Parser(stream);
    auto dtoPTR = p.parseStringToDTO();

    ASSERT_TRUE(dtoPTR->getCommandName() == Commands::DELETE);
    ASSERT_TRUE(dtoPTR->getIdx1() == 1);
    ASSERT_TRUE(dtoPTR->getIdx2() == 4);
}

TEST(ParserParser, createDeleteDTOFail){
    InputStream stream(std::make_unique<std::stringstream>("delete egdfpldfphl"));
    auto p = Parser(stream);

    ASSERT_FALSE(p.parseStringToDTO());
}

TEST(ParserParser, createUndoDTOSuccess){
    InputStream stream(std::make_unique<std::stringstream>("undo"));
    auto p = Parser(stream);
    auto dtoPTR = p.parseStringToDTO();
    ASSERT_TRUE(dtoPTR->getCommandName() == Commands::UNDO);
}

TEST(ParserParser, createRedoDTOSuccess){
    InputStream stream(std::make_unique<std::stringstream>("redo"));
    auto p = Parser(stream);
    auto dtoPTR = p.parseStringToDTO();
    ASSERT_TRUE(dtoPTR->getCommandName() == Commands::REDO);
}