#pragma once
#include "gtest/gtest.h"
#include "../TextEditorLib/DTOProvider.h"

TEST(DTOProvider, AverageStream){
    InputStream stream(std::make_unique<std::stringstream>("insert _insert_me_ 2\nundo\n   delete 1 2 \n paste 1\n copy 1 2\nerror\n"));
    Parser p(stream);
    auto provider = DTOProvider(std::make_shared<Parser>(p));
    auto ptr = provider.getDTO();
    ASSERT_TRUE(ptr);
    InsertDTO* inDTO = dynamic_cast<InsertDTO*>(ptr.get());
    ASSERT_TRUE(inDTO->getString().getString() == "_insert_me_");
    ASSERT_TRUE(inDTO->getPosition() == 2);

    ptr = provider.getDTO();
    ASSERT_TRUE(ptr);
    ASSERT_NO_THROW(UndoDTO* unDTO = dynamic_cast<UndoDTO*>(ptr.get()));

    ptr = provider.getDTO();
    ASSERT_TRUE(ptr);
    DeleteDTO* deDTO = dynamic_cast<DeleteDTO*>(ptr.get());
    ASSERT_TRUE(deDTO->getIdx1() == 1);
    ASSERT_TRUE(deDTO->getIdx2() == 2);

    ptr = provider.getDTO();
    ASSERT_TRUE(ptr);
    PasteDTO* paDTO = dynamic_cast<PasteDTO*>(ptr.get());
    ASSERT_TRUE(paDTO->getPosition() == 1);

    ptr = provider.getDTO();
    ASSERT_TRUE(ptr);
    CopyDTO* coDTO = dynamic_cast<CopyDTO*>(ptr.get());
    ASSERT_TRUE(coDTO->getIdx1() == 1);
    ASSERT_TRUE(coDTO->getIdx2() == 2);

    ptr = provider.getDTO();
    ASSERT_FALSE(ptr);

}