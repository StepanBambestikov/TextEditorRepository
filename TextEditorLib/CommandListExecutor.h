#pragma once
#include "Exceptions.h"
#include "StringEditor.h"
#include "StringBuffer.h"
#include "CommandProvider.h"

class CommandListExecutor final{
public:
    CommandListExecutor(std::unique_ptr<CommandProvider> _provider, StringBuffer _str) noexcept;
    StringBuffer runAllAndGetString();
private:
    std::unique_ptr<CommandProvider> provider;
    std::shared_ptr<StringBuffer> strPtr;
    StringEditor editor;
};