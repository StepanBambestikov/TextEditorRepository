#pragma once
#include "UserCommand.h"
#include "ServiceCommand.h"

class CommandProvider {
public:
    CommandProvider() noexcept = default;
    virtual ~CommandProvider() noexcept = default;
    virtual std::unique_ptr<UserCommand> tryGetUserCommand() = 0;
    virtual std::unique_ptr<ServiceCommand> tryGetServiceCommand() = 0;
    [[nodiscard]] virtual bool hasNext() const = 0;
};
