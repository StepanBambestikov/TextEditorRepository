#pragma once
#include <vector>
#include <memory>
#include "UserCommand.h"
#include "Exceptions.h"

class StringEditor final{
public:
    StringEditor(std::shared_ptr<StringBuffer> _str) noexcept;
    bool addAndExecuteCommand(std::unique_ptr<UserCommand> cmdPtr);
    bool tryUndo();
    bool tryRedo();
private:
    std::shared_ptr<StringBuffer> str;
    std::shared_ptr<StringBuffer> buffer = std::make_shared<StringBuffer>();

    std::vector<std::unique_ptr<UserCommand>> commands;
    std::unique_ptr<UserCommand> canceledCmd;
};