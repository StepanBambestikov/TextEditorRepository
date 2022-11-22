#pragma once
#include "StringEditor.h"
#include "Parser.h"
#include "StringBuffer.h"
#include "Creators.h"// TODO кому подключать creator'ов?

class CommandListExecutor final{
public:
    CommandListExecutor(const Parser& _commandList, const StringBuffer& _str) noexcept;
    StringBuffer runAllAndGetString();
private:
    StringEditor editor;
    Parser commandList;
    std::shared_ptr<StringBuffer> strPtr;
};