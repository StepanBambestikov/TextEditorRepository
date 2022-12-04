#pragma once
#include "gtest/gtest.h"
#include "../TextEditorLib/DTO.h"

TEST(CopyDTO, normalData){
    auto dto = CopyDTO(1, 2);
    ASSERT_TRUE(dto.getIdx1() == 1);
    ASSERT_TRUE(dto.getIdx2() == 2);
}

TEST(CopyDTO, DTOInserface){
    CopyDTO dto = CopyDTO(1, 2);
    CommandDTO& dtoI = dto;
    ASSERT_NO_THROW(CopyDTO coDTO = dynamic_cast<CopyDTO&>(dtoI));
}

TEST(PasteDTO, normalData){
    auto dto = PasteDTO(1);
    ASSERT_TRUE(dto.getPosition() == 1);
}

TEST(PasteDTO, DTOInserface){
    PasteDTO dto = PasteDTO(1);
    CommandDTO& dtoI = dto;
    ASSERT_NO_THROW(PasteDTO paDTO = dynamic_cast<PasteDTO&>(dtoI));
}

TEST(DeleteDTO, normalData){
    auto dto = DeleteDTO(1, 2);
    ASSERT_TRUE(dto.getIdx1() == 1);
    ASSERT_TRUE(dto.getIdx2() == 2);
}

TEST(DeleteDTO, DTOInserface){
    DeleteDTO dto = DeleteDTO(1, 2);
    CommandDTO& dtoI = dto;
    ASSERT_NO_THROW(DeleteDTO deDTO = dynamic_cast<DeleteDTO&>(dtoI));
}

TEST(InsertDTO, normalData){
    auto dto = InsertDTO(StringBuffer{"123"}, 1);
    ASSERT_TRUE(dto.getPosition() == 1);
    ASSERT_TRUE(dto.getString().getString() == "123");
}

TEST(InsertDTO, DTOInserface){
    InsertDTO dto = InsertDTO(StringBuffer{"123"}, 1);
    CommandDTO& dtoI = dto;
    ASSERT_NO_THROW(InsertDTO inDTO = dynamic_cast<InsertDTO&>(dtoI));
}

TEST(UndoDTO, normalData){
    ASSERT_NO_THROW(auto dto = UndoDTO());
}

TEST(UndoDTO, DTOInserface){
    UndoDTO dto = UndoDTO();
    CommandDTO& dtoI = dto;
    ASSERT_NO_THROW(UndoDTO unDTO = dynamic_cast<UndoDTO&>(dtoI));
}

TEST(RedoDTO, normalData){
    ASSERT_NO_THROW(auto dto = RedoDTO());
}

TEST(Redo, DTOInserface){
    RedoDTO dto = RedoDTO();
    CommandDTO& dtoI = dto;
    ASSERT_NO_THROW(RedoDTO reDTO = dynamic_cast<RedoDTO&>(dtoI));
}