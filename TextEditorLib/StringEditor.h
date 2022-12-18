#pragma once
#include <vector>
#include <memory>
#include "UserCommand.h"
#include "EditorBuffer.h"
#include "Exceptions.h"

class StringEditor final{
public:
    StringEditor(std::unique_ptr<StringBuffer> _str) noexcept;
    [[nodiscard]] StringBuffer getString() const;
    bool tryAddAndExecuteCommand(std::unique_ptr<UserCommand> cmdPtr);
    bool tryUndo();
    bool tryRedo();
private:
    std::shared_ptr<StringBuffer> str;
    EditorBuffer& buffer = EditorBuffer::getInstance();

    std::vector<std::unique_ptr<UserCommand>> commands;
    std::unique_ptr<UserCommand> canceledCmd;
};