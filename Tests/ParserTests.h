#pragma once
#include "gtest/gtest.h"
#include "../TextEditorLib/Parser.h"

TEST(Parser, createDTOFail1) {
    std::stringstream stream{"Cpy 2"};
    auto p = Parser(stream);
    ASSERT_FALSE(p.parseWhileNotDTO());
}

TEST(Parser, createDTOFail2){
    std::stringstream stream{};
    auto p = Parser(stream);
    ASSERT_FALSE(p.parseWhileNotDTO());
}

TEST(Parser, createCopyDTOSuccess){
    std::stringstream stream{"copy 1 2"};
    auto p = Parser(stream);
    auto dtoPTR = p.parseWhileNotDTO();

    ASSERT_TRUE(dtoPTR->getCommandName() == Commands::COPY);
    ASSERT_TRUE(dtoPTR->getIdx1() == 1);
    ASSERT_TRUE(dtoPTR->getIdx2() == 2);
}

TEST(Parser, createCopyDTOFail){
    std::stringstream stream{"copy 2"};
    auto p = Parser(stream);
    ASSERT_FALSE(p.parseWhileNotDTO());
}

TEST(Parser, createPasteDTOSuccess){
    std::stringstream stream{"paste 1"};
    auto p = Parser(stream);
    auto dtoPTR = p.parseWhileNotDTO();

    ASSERT_TRUE(dtoPTR->getCommandName() == Commands::PASTE);
    ASSERT_TRUE(dtoPTR->getIdx1() == 1);
}

TEST(Parser, createPasteDTOFail){
    std::stringstream stream{"paste error "};
    auto p = Parser(stream);
    ASSERT_FALSE(p.parseWhileNotDTO());
}

TEST(Parser, createInsertDTOSuccess){
    std::stringstream stream{"insert name 12"};
    auto p = Parser(stream);
    auto dtoPTR = p.parseWhileNotDTO();

    ASSERT_TRUE(dtoPTR->getCommandName() == Commands::INSERT);
    ASSERT_TRUE(dtoPTR->getIdx1() == 12);
}

TEST(Parser, createInsertDTOFail){
    std::stringstream stream{"insert   2 "};
    auto p = Parser(stream);
    ASSERT_FALSE(p.parseWhileNotDTO());
}

TEST(ParserParser, createDeleteDTOSuccess){
    std::stringstream stream{"delete 1 4"};
    auto p = Parser(stream);
    auto dtoPTR = p.parseWhileNotDTO();

    ASSERT_TRUE(dtoPTR->getCommandName() == Commands::DELETE);
    ASSERT_TRUE(dtoPTR->getIdx1() == 1);
    ASSERT_TRUE(dtoPTR->getIdx2() == 4);
}

TEST(ParserParser, createDeleteDTOFail){
    std::stringstream stream{"delete egdfpldfphl"};
    auto p = Parser(stream);

    ASSERT_FALSE(p.parseWhileNotDTO());
}

TEST(ParserParser, createUndoDTOSuccess){
    std::stringstream stream{"undo"};
    auto p = Parser(stream);
    auto dtoPTR = p.parseWhileNotDTO();
    ASSERT_TRUE(dtoPTR->getCommandName() == Commands::UNDO);
}

TEST(ParserParser, createRedoDTOSuccess){
    std::stringstream stream{"redo"};
    auto p = Parser(stream);
    auto dtoPTR = p.parseWhileNotDTO();
    ASSERT_TRUE(dtoPTR->getCommandName() == Commands::REDO);
}