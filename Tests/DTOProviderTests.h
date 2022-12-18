#pragma once
#include "gtest/gtest.h"
#include "../TextEditorLib/DTOProviderFromParser.h"

TEST(DTOProvider, AverageStream){
    std::stringstream stream{"insert _insert_me_ 2\nundo\n   delete 1 2 \n paste 1\n copy 1 2\nerror\n"};
    auto provider = DTOProviderFromParser(std::make_unique<Parser>(stream));
    auto ptr = provider.getDTO();

    ASSERT_TRUE(ptr->getString()->getString() == "_insert_me_");
    ASSERT_TRUE(ptr->getIdx1() == 2);

    ptr = provider.getDTO();
    ASSERT_TRUE(ptr);

    ptr = provider.getDTO();
    ASSERT_TRUE(ptr);
    ASSERT_TRUE(ptr->getIdx1() == 1);
    ASSERT_TRUE(ptr->getIdx2() == 2);

    ptr = provider.getDTO();
    ASSERT_TRUE(ptr);
    ASSERT_TRUE(ptr->getIdx1() == 1);

    ptr = provider.getDTO();
    ASSERT_TRUE(ptr);
    ASSERT_TRUE(ptr->getIdx1() == 1);
    ASSERT_TRUE(ptr->getIdx2() == 2);

    ptr = provider.getDTO();
    ASSERT_FALSE(ptr);

}