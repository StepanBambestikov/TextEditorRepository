#pragma once
#include "gtest/gtest.h"
#include "../TextEditorLib/InputStream.h"
#include "../TextEditorLib/Parser.h"
#include "../TextEditorLib/DTOProviderFromParser.h"
#include "../TextEditorLib/CreatorProviderFromDTO.h"
#include "../TextEditorLib/CommandProviderFromCreator.h"
#include "Commands.h"

TEST(CommandProvider, AverageStream) {
    InputStream stream(std::make_unique<std::stringstream>(
            "insert _insert_me_ 2\nundo\n\n;dflgeptmdjfgpvj pfjgkdj\n   delete 1 2 \n copy 1 3\n paste 3\nerror\n"));
    auto parsePtr = std::make_unique<Parser>(stream);
    auto dtoProviderPtr = std::make_unique<DTOProviderFromParser>(std::move(parsePtr));
    auto creatorProviderPtr = std::make_unique<CreatorProviderFromDTO>(std::move(dtoProviderPtr));
    auto commandProvider = CommandProviderFromCreator(std::move(creatorProviderPtr));

    auto str = std::make_shared<StringBuffer>("12345");
    auto buf = std::make_shared<StringBuffer>();

    std::unique_ptr<UserCommand> uPtr;
    std::unique_ptr<ServiceCommand> sPtr;
    while(commandProvider.hasNext()){
        uPtr = commandProvider.tryGetUserCommand();
        if (uPtr) {
            uPtr->redo(str, buf);
        }
        else{
            sPtr = commandProvider.tryGetServiceCommand();
        }
    }
    ASSERT_TRUE(str->getString() == "1_i_insert_me_345");
}

