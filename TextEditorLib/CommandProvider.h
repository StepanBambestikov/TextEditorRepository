#pragma once
#include "CommandInterface.h"

class CommandProvider {
public:
    CommandProvider() = default;
    virtual ~CommandProvider() = default;
    virtual std::unique_ptr<CommandInterface> getCommand() = 0;
    virtual bool hasNext() const = 0;
};
