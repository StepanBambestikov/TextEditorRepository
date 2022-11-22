#pragma once
#include <vector>
#include <memory>
#include "CommandInterface.h"
#include "Exceptions.h"

class StringEditor final{
public:
    StringEditor() noexcept;
    void addAndExecuteCommand(std::shared_ptr<CommandInterface> cmdPtr);
    void undo();
    void redo();
private:
    std::vector<std::shared_ptr<CommandInterface>> commands;
    int currentCmd = { -1 };
    std::shared_ptr<CommandInterface> canceledCmd;
};