#pragma once
#include "Exceptions.h"
#include "StringEditor.h"
#include "StringBuffer.h"
#include "CommandProvider.h"

class CommandListExecutor final{
public:
    CommandListExecutor(std::unique_ptr<CommandProvider> _provider) noexcept;
    StringBuffer runAllAndGetString(std::unique_ptr<StringEditor> editorPtr);
private:
    std::unique_ptr<CommandProvider> provider;
};