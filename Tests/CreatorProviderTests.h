#pragma once
#include "gtest/gtest.h"
#include "../TextEditorLib/CreatorProviderFromDTO.h"
#include "Creators.h"

TEST(CreatorProvider, AverageStream){
    InputStream stream(std::make_unique<std::stringstream>("insert _insert_me_ 2\nundo\n   delete 1 2 \n paste 1\n copy 1 2\nerror\n"));
    auto parsePtr = std::make_unique<Parser>(stream);
    auto creatorProvider = CreatorProviderFromDTO(std::make_unique<DTOProviderFromParser>(std::move(parsePtr)));
    auto ptr = creatorProvider.getCreator();
    ASSERT_TRUE(ptr);
    InsertCreator* inCreator = dynamic_cast<InsertCreator*>(ptr.get());
    EXPECT_NO_THROW(inCreator->createCommand());
    EXPECT_NO_THROW(inCreator->createCommand());
    EXPECT_NO_THROW(inCreator->createCommand());

    ptr = creatorProvider.getCreator();
    ASSERT_TRUE(ptr);
    UndoCreator* unCreator = dynamic_cast<UndoCreator*>(ptr.get());
    EXPECT_NO_THROW(unCreator->createCommand());

    ptr = creatorProvider.getCreator();
    ASSERT_TRUE(ptr);
    DeleteCreator* delCreator = dynamic_cast<DeleteCreator*>(ptr.get());
    EXPECT_NO_THROW(delCreator->createCommand());

    ptr = creatorProvider.getCreator();
    ASSERT_TRUE(ptr);
    PasteCreator* paCreator = dynamic_cast<PasteCreator*>(ptr.get());
    EXPECT_NO_THROW(paCreator->createCommand());

    ptr = creatorProvider.getCreator();
    ASSERT_TRUE(ptr);
    CopyCreator* coCreator = dynamic_cast<CopyCreator*>(ptr.get());
    EXPECT_NO_THROW(coCreator->createCommand());

    ptr = creatorProvider.getCreator();
    ASSERT_FALSE(ptr);
}
