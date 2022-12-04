#pragma once
#include "StringEditor.h"
#include "StringBuffer.h"
#include "CommandProvider.h"
#include "Creators.h"// TODO кому подключать creator'ов?

class CommandListExecutor final{
public:
    CommandListExecutor(std::unique_ptr<CommandProvider> _provider, StringBuffer _str) noexcept;
    StringBuffer runAllAndGetString();
private:
    std::unique_ptr<CommandProvider> provider;
    std::shared_ptr<StringBuffer> strPtr;
    StringEditor editor;
};