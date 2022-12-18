#pragma once

#include "../TextEditorLib/Parser.h"
#include "../TextEditorLib/DTOProviderFromParser.h"
#include "gtest/gtest.h"
#include "../TextEditorLib/CreatorProviderFromDTO.h"
#include "Creators.h"

TEST(CreatorProvider, AverageStream){
    std::stringstream stream{"insert _insert_me_ 2\nundo\n   delete 1 2 \n paste 1\n copy 1 2\nerror\n"};
    auto parsePtr = std::make_unique<Parser>(stream);
    auto creatorProvider = CreatorProviderFromDTO(std::make_unique<DTOProviderFromParser>(std::move(parsePtr)));
    auto ptr = creatorProvider.getCreator();
    ASSERT_TRUE(ptr);
    InsertCreator* inCreator = dynamic_cast<InsertCreator*>(ptr.get());
    EXPECT_NO_THROW(inCreator->tryCreateUserCommand());
    EXPECT_NO_THROW(inCreator->tryCreateServiceCommand());
    EXPECT_NO_THROW(inCreator->tryCreateUserCommand());
    EXPECT_NO_THROW(inCreator->tryCreateServiceCommand());
    EXPECT_NO_THROW(inCreator->tryCreateUserCommand());

    ptr = creatorProvider.getCreator();
    ASSERT_TRUE(ptr);
    UndoCreator* unCreator = dynamic_cast<UndoCreator*>(ptr.get());
    EXPECT_NO_THROW(unCreator->tryCreateUserCommand());
    EXPECT_NO_THROW(unCreator->tryCreateServiceCommand());

    ptr = creatorProvider.getCreator();
    ASSERT_TRUE(ptr);
    DeleteCreator* delCreator = dynamic_cast<DeleteCreator*>(ptr.get());
    EXPECT_NO_THROW(delCreator->tryCreateUserCommand());
    EXPECT_NO_THROW(delCreator->tryCreateServiceCommand());

    ptr = creatorProvider.getCreator();
    ASSERT_TRUE(ptr);
    PasteCreator* paCreator = dynamic_cast<PasteCreator*>(ptr.get());
    EXPECT_NO_THROW(paCreator->tryCreateUserCommand());
    EXPECT_NO_THROW(paCreator->tryCreateServiceCommand());

    ptr = creatorProvider.getCreator();
    ASSERT_TRUE(ptr);
    CopyCreator* coCreator = dynamic_cast<CopyCreator*>(ptr.get());
    EXPECT_NO_THROW(coCreator->tryCreateUserCommand());
    EXPECT_NO_THROW(coCreator->tryCreateServiceCommand());

    ptr = creatorProvider.getCreator();
    ASSERT_FALSE(ptr);
}
